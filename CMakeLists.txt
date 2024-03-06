cmake_minimum_required(VERSION 3.20)
project(main
    VERSION 1.0 
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPLER "D:/Program Files/mingw-w64/bin/gcc")
set(CMAKE_CXX_COMPILER "D:/Program Files/mingw-w64/bin/g++")


OPTION(SERVER_BUILD "Enable server executable process." OFF)
OPTION(CLIENT_BUILD "Enable client executable process." OFF)
OPTION(DEMO_BUILD "Enable demo executable process." OFF)

if (SERVER_BUILD)
    set(SSOURCE_FILES src/main.cpp)
    add_executable(server ${SSOURCE_FILES})
    target_link_libraries(server PRIVATE Ws2_32)
endif()

if (CLIENT_BUILD)
    set(CSOURCE_FILES src/client.cpp)
    add_executable(client ${CSOURCE_FILES})
    target_link_libraries(client PRIVATE Ws2_32)
endif()

if (DEMO_BUILD)
    set(DSOURCE_FILES src/demo01.cpp)
    add_executable(demo ${DSOURCE_FILES})
    target_link_libraries(demo PRIVATE Ws2_32)
endif()