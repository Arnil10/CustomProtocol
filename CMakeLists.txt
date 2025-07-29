cmake_minimum_required(VERSION 3.15)
project(CustomProtocol)

set(CMAKE_CXX_STANDARD 17)


find_package(Poco REQUIRED COMPONENTS Net Foundation)

include_directories(include)

add_executable(Server src/Server.cpp src/Protocol.cpp)
target_link_libraries(Server PRIVATE Poco::Net Poco::Foundation)

add_executable(Client src/Client.cpp src/Protocol.cpp)
target_link_libraries(Client PRIVATE Poco::Net Poco::Foundation)
