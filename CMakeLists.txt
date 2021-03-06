cmake_minimum_required(VERSION 3.12)
project(NativeEncrypt)

set(CMAKE_CXX_STANDARD 14)

set(JAVA_HOME $ENV{JAVA_HOME})

MESSAGE(STSTUS "###################################")
MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
    set(OS_PATH linux)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
    set(OS_PATH win32)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    MESSAGE(STATUS "current platform: FreeBSD")
    set(OS_PATH linux)
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
    set(OS_PATH linux)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
MESSAGE(STSTUS "###################################")

IF(CMAKE_BUILD_TYPE MATCHES "")
    SET(CMAKE_BUILD_TYPE "Release")
    #SET(CMAKE_BUILD_TYPE "Debug")
ENDIF()

set(INC_DIR ${JAVA_HOME}/include ${JAVA_HOME}/include/${OS_PATH})
set(LINK_DIR ${JAVA_HOME}/lib libs/${CMAKE_BUILD_TYPE})
set(SOURCE_FILES com_ft_encrypt_Encrypt.h Encrypt.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../libs/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../libs/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/${CMAKE_BUILD_TYPE})
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../ModifyJar/Encrypt")

include_directories(${INC_DIR})
link_directories(${LINK_DIR})

IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
    link_libraries(jvm)
ENDIF()


add_library(NativeEncrypt SHARED ${SOURCE_FILES})