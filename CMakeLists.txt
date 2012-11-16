cmake_minimum_required(VERSION 2.8)

SET(BINARY_NAME tests)

LINK_DIRECTORIES(/opt/local/lib)

SET(SOURCES
    bully.cpp
    Process.cpp
    Protocol.cpp
    Communicator.cpp
    Printer.cpp
    Message.cpp
    Timer.cpp
)

ADD_EXECUTABLE(${BINARY_NAME} ${SOURCES})

INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(/opt/local/include/)

TARGET_LINK_LIBRARIES(${BINARY_NAME} boost_thread-mt)
TARGET_LINK_LIBRARIES(${BINARY_NAME}  boost_system-mt)





