# Write a TCP/UDP application

## Client/Server Architecture

This project implements a client/server architecture for TCP/UDP communication. The architecture consists of the following components:

### Client
- The client is responsible for initiating communication with the server.
- It sends requests to the server and processes the responses.
- The client implementation can be found in `app/Client/client_main.cpp`.

### Server
- The server listens for incoming client connections.
- It processes client requests and sends back appropriate responses.
- The server also broadcasts messages received from one client to all other connected clients.
- The server implementation can be found in `app/Server/server_main.cpp`.

### Core Library
- Shared functionality between the client and server is implemented in the `core` module.
- This includes utilities, logging, and other shared components.
- Core implementation files are located in `core/implementation/`.

### Build and Run
- The project uses CMake for building the client and server applications.
- After building, the binaries for the client and server can be found in the `bin/` directory.
