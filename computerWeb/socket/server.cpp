void do_main(int newsockfd) {
	int		ret;
	char		buf[MAX_LINE];

	while((ret = readready(newsockfd)) >= 0) {
		if(ret == 0) continue;
		if(readline(newsockfd, buf, MAX_LINE) <= 0) break;
		fputs(buf, stdout);
		if(buf[0] == '@') {
			int		len;

			len = strlen(buf);
			send(newsockfd, buf+1, len-1, 0);
		} else if(strncmp(buf, "QUIT", 4) == 0) {
			kill(getppid(), SIGKILL);
			break;
		} else if(strncmp(buf, "GET ", 4) == 0) {
			char	bufskip[MAX_LINE];
			char	*msg =
				"HTTP/1.0 200 OK\r\n"
				"Content-Type: text/plain\r\n"
				"\r\nTest OK\n";

			while(readline(newsockfd, bufskip, MAX_LINE))
				if(strncmp(bufskip, "\r\n", 2) == 0) break;
			send(newsockfd, msg, strlen(msg), 0);
			send(newsockfd, buf, strlen(buf), 0);
			break;
		}
	}
}
int tcp_open_server(char *port) {
	int			sockfd;
	struct sockaddr_in	serv_addr;

	/* Open a TCP socket (an Internet stream socket). */
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1;

	/* Bind our local address so that the client can send to us. */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family	  = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port	  = htons(atoi(port));

	if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
		return -1;
	listen(sockfd, 5);
	return sockfd;
}

int main(int argc, char *argv[]) {
	int			sockfd, newsockfd, clilen, childpid;
	struct sockaddr_in	cli_addr;

	sockfd = tcp_open_server(argv[1]);

	for( ; ; ) {
	/* Wait for a connection from a client process. (Concurrent Server)*/
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
		if(newsockfd < 0) exit(1); /* server: accept error */
		if((childpid  = fork()) < 0) exit(1); /* server: fork error */

		if(childpid == 0) {		/* child process	*/
			close(sockfd);		/* close original socket*/
			do_main(newsockfd);	/* process the request	*/
			exit(0);
		}

		close(newsockfd);		/* parent process	*/
	}
}