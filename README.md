# 🧠 TCP Socket Client & Server in C

This project demonstrates how to build a **basic TCP client** and **TCP server** in C using **raw sockets** and standard POSIX functions on Linux.

It is a simple and educational implementation aimed at understanding the low-level networking concepts in system programming.

---

## 📁 Files Included

- `sockets.c` → TCP Client  
- `srv.c` → TCP Server

---

## 🚀 How It Works

### ✅ TCP Client (`sockets.c`)
- Connects to a web server using a hardcoded IP and port (default: port `80`)
- Sends an HTTP `HEAD` request
- Receives and prints the response headers
- Demonstrates:
  - Socket creation via `socket()`
  - Server address setup (`struct sockaddr_in`)
  - Connection with `connect()`
  - Sending with `write()`
  - Receiving with `read()`

---

### ✅ TCP Server (`srv.c`)
- Listens for incoming TCP connections on port `8181`
- Accepts a connection, reads the client’s message, and responds with a basic HTTP-like string
- Demonstrates:
  - Socket setup and binding (`bind()`)
  - Listening (`listen()`)
  - Accepting a client (`accept()`)
  - Reading and writing to the client socket
  - Clean shutdown using `close()`

---

## 🛠️ How to Compile

You can compile each file separately using `gcc`:

```bash
# Compile the client
gcc sockets.c -o client

# Compile the server
gcc srv.c -o server

