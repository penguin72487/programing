#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string>
#include <thread>
#include <vector>
using namespace std;

void sendRequest(const char* sendbuf) {
    while(true) {
        // this_thread::sleep_for(chrono::seconds(1));  // 暫停1秒
        WSADATA wsaData;
        SOCKET ConnectSocket;
        struct sockaddr_in serverAddr;
        char recvbuf[512];
        int recvbuflen = 512;

        // 初始化 Winsock
        if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
            printf("WSAStartup failed\n");
            return;
        }

        // 創建一個新的套接字
        ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("Error at socket(): %ld\n", WSAGetLastError());
            WSACleanup();
            return;
        }

        // 設置服務器地址
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(80); // 使用端口80
        serverAddr.sin_addr.s_addr = inet_addr("140.112.5.189"); // 使用指定的IP地址

        // 連接到服務器
        if (connect(ConnectSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            printf("Failed to connect.\n");
            closesocket(ConnectSocket);
            WSACleanup();
            return;
        }

        // 發送數據
        if (send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0) == SOCKET_ERROR) {
            printf("send failed: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return;
        }

        // 接收服務器回應
        int iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            printf("%.*s\n", iResult, recvbuf);
        } else if (iResult == 0) {
            printf("Connection closed\n");
        } else {
            printf("recv failed: %d\n", WSAGetLastError());
        }

        // 關閉套接字
    }
    
}

int main() {
    const char *sendbuf = "GET / HTTP/1.0\r\n\r\n";

        vector<thread> threads;
        for(int i = 0; i < 8; ++i) {
            threads.push_back(thread(sendRequest, sendbuf));
        }

        for(auto& th : threads) {
            th.join();
        }

        // this_thread::sleep_for(chrono::seconds(1));  // 暫停1秒

    return 0;
}
