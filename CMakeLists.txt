cmake_minimum_required(VERSION 3.10)

project(qr-cc LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(qr-cc qr-cc.cc generator.cc decoder.cc)
