cmake_minimum_required(VERSION 3.0)
project (mav)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(mav ${SOURCES} ${INCLUDE_DIRS})

find_package(ZLIB REQUIRED)
if (ZLIB_FOUND)
    include_directories(${ZLIB_INCLUDE_DIRS})
    target_link_libraries(mav ${ZLIB_LIBRARIES})
endif(ZLIB_FOUND)

find_package(OpenSSL REQUIRED)
if (OPENSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIRS})
    target_link_libraries(mav ${OPENSSL_LIBRARIES})
endif(OPENSSL_FOUND)

