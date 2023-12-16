    int iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
        printf("Bytes received: %d\n", iResult);
        printf("%.*s\n", iResult, recvbuf);
    } else if (iResult == 0) {
        printf("Connection closed\n");
    } else {
        printf("recv failed: %d\n", WSAGetLastError());
    }