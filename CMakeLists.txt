cmake_minimum_required(VERSION 3.5)
project(PING_HOST_DEV)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(GTK4_INCLUDE_DIRS "C:/msys64/mingw64/include")
set(GTK4_LIBRARY_DIRS "C:/msys64/mingw64/lib")
set(PKG_CONFIG_PATH "C:/msys64/mingw64/lib/pkgconfig:C:/msys64/mingw64/share/pkgconfig")
#set(CMAKE_SYSTEM_NAME Window)
#set(CMAKE_CXX_COMPILER "FILEPATH=C:/msys64/mingw64/bin/g++")
#set(CMAKE_C_COMPILER "FILEPATH=C:/msys64/mingw64/bin/gcc")
#set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64/lib/pkgconfig;C:/msys64/ucrt64/share/pkgconfig")

find_package(PkgConfig REQUIRED)
pkg_check_modules(REQUIRED gtkmm-4.0)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

add_executable(app src/main.cpp)
set_target_properties(app PROPERTIES WIN32_EXECUTABLE true)  # If you dont want console to run with your .exe
target_link_libraries(app ${GTK4_LIBRARIES})
