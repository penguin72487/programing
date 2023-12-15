#include <bits/stdc++.h>
netinetnetinetT
#include <string.h>      // 對於 memset 函數
#include <sys/socket.h>  // 對於套接字函數和常量
#include <stdlib.h>      // 對於 atoi 函數
#include <sys/types.h>   // 對於某些系統類型和函數
#include <sys/select.h>  // 對於 select 函數和 fd_set 類型
#include <sys/time.h>    // 對於 timeval 結構體
#include <errno.h>       // 對於 errno 變量
#include <unistd.h>      // 對於 read 函數
#include <arpa/inet.h>   // 對於 inet_addr 和 gethostbyname 函數

int tcp_open_client(char *host, char *port) {
#include <string.h> // Include the header file for bzero function

int	sockfd;
struct sockaddr_in	serv_addr;

/* Fill in "serv_addr" with the address of the server */
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family	  = AF_INET;
serv_addr.sin_addr.s_addr = my_inet_addr(host);
serv_addr.sin_port	  = htons(atoi(port));

/* Open a TCP socket (an Internet stream socket). */
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0
   || connect(sockfd, (struct sockaddr *) &serv_addr,
                sizeof(serv_addr)) < 0)
    return -1;
	return sockfd;
}
int readready(int fd) {
	fd_set		map;
	int		ret;
	struct timeval	_zerotimeval = {0, 0};

	do {
		FD_ZERO(&map); FD_SET(fd, &map);
		ret = select(fd+1, &map, NULL, NULL, &_zerotimeval);
		if(ret >= 0) return ret;
	} while(errno == EINTR);
	return ret;
}

/* readline() - read a line (ended with '\n') from a file descriptor
 *	. return the number of chars read, -1 on errors
 */
int readline(int fd, char *ptr, int maxlen) {
	int	n, rc;
	char	c;

	for (n = 1; n < maxlen; n++) {
		if ( (rc = read(fd, &c, 1)) == 1) {
			*ptr++ = c;
			if (c == '\n') break;
		} else if (rc == 0) {
			if (n == 1) return (0);	/* EOF, no data read	*/
			else break;		/* EOF, some data read	*/
		} else return (-1);		/* Error		*/
	}
	*ptr = 0;
	return (n);
}
/* my_inet_addr() - convert host/IP into binary data in network byte order
 */
in_addr_t my_inet_addr(char *host) {
	in_addr_t		inaddr;
	struct hostent		*hp;

	inaddr = inet_addr(host);
	if(inaddr == INADDR_NONE && (hp = gethostbyname(host)) != NULL)
		bcopy(hp->h_addr, (char *) &inaddr, hp->h_length);
	return inaddr;
}
int main(int argc, char *argv[]) {
	int		sockfd, len, ret;
	char		buf[MAX_LINE];

	sockfd = tcp_open_client(argv[1], argv[2]);
	while(1) {
		if((ret = readready(sockfd)) < 0) break;
		if(ret > 0) {
			if(readline(sockfd, buf, MAX_LINE) <= 0) break;
			fputs(buf, stdout);
		}
		if((ret = readready(0)) < 0) break;
		if(ret > 0) {
			if(fgets(buf, MAX_LINE, stdin) == NULL) break;
			len = strlen(buf);
			send(sockfd, buf, len, 0);
			if(strncmp(buf, "QUIT", 4) == 0) break;
		}
	}
	close(sockfd);
	return 0;
}