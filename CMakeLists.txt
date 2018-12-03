cmake_minimum_required(VERSION 3.12)
project(NativeEncrypt)

set(CMAKE_CXX_STANDARD 14)

set(JAVA_HOME $ENV{JAVA_HOME})

set(INC_DIR ${JAVA_HOME}/include;${JAVA_HOME}/include/win32;)
set(LINK_DIR ${JAVA_HOME}/lib)
set(SOURCE_FILES com_ft_encrypt_Encrypt.h Encrypt.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../ModifyJar/Encrypt")

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(jvm)

add_library(NativeEncrypt SHARED ${SOURCE_FILES})