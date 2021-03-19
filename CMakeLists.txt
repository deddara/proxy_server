cmake_minimum_required(VERSION 3.17)
project(proxy_server)


SET(CMAKE_CXX_FLAGS -pthread)

add_executable(proxy_server
        ./src/proxy_server.cpp
        ./src/Server.cpp
        ./src/Client.cpp)
