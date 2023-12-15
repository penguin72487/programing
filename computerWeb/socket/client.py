import socket
import sys

def http_get(host, port, path):
    request = f"GET {path} HTTP/1.0\r\nHost: {host}\r\n\r\n"
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.send(request.encode())
        response = s.recv(4096)
        print(response.decode())

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python3 client.py [host] [port] [path]")
        sys.exit(1)
    
    host= "ee.nuk.edu.tw"
    port = 80 
    path = sys.argv
    http_get(host, int(port), path)
