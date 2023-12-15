import socket
import threading

def handle_client(client_socket):
    request = client_socket.recv(1024)
    print(f"Received: {request.decode()}")
    client_socket.send("HTTP/1.1 200 OK\r\n".encode())
    client_socket.send("Content-Type: text/html\r\n\r\n".encode())
    client_socket.send("<html><body><h1>Hello, World!</h1></body></html>".encode())
    client_socket.close()

def start_server(port):
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('0.0.0.0', port))
    server.listen(5)
    print(f"[*] Listening on 0.0.0.0:{port}")

    while True:
        client, addr = server.accept()
        print(f"[*] Accepted connection from: {addr[0]}:{addr[1]}")
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

if __name__ == "__main__":
    start_server(8080)
