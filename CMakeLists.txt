cmake_minimum_required(VERSION 3.17)
project(proxy_server)

set(CMAKE_CXX_STANDARD 14)

add_executable(proxy_server
        proxy_server.cpp
        Server.cpp
        Client.cpp)
