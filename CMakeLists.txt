cmake_minimum_required(VERSION 3.5.0)

project(Message_Logger)
include_directories(${PROJECT_SOURCE_DIR}/inc/)

add_library(Message_Lib ./src/Message_Logger.cpp)

add_executable(${PROJECT_NAME} ./app/main.cpp)
target_link_libraries(${PROJECT_NAME} Message_Lib)