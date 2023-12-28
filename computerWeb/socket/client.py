import socket
import sys

def http_get(host, port, path):
    request = f"GET {path} HTTP/1.0\r\nHost: {host}\r\n\r\n"
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.send(request.encode())
        response = b""
        while True:
            chunk = s.recv(4096)
            if not chunk:
                break
            response += chunk
        response = response.decode()
        headers = response.split("\r\n\r\n")[0]
        print(f"Headers: {headers}")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python3 client.py [host] [port] [path]")
        sys.exit(1)
    
    host = sys.argv[1]
    port = int(sys.argv[2])
    path = sys.argv[3]
    http_get(host, port, path)