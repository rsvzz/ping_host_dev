cmake_minimum_required(VERSION 3.5)
project(PING_HOST_DEV)

#antes no funciona en app anterios gcc12
#set(CMAKE_C_STANDARD 11)
#set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GTK4_INCLUDE_DIRS "C:/msys64/mingw64/include")
set(GTK4_LIBRARY_DIRS "C:/msys64/mingw64/lib")
set(GTKMM_LIBRARY_DIRS "C:/msys64/mingw64/lib")
set(PKG_CONFIG_PATH "C:/msys64/mingw64/lib/pkgconfig:C:/msys64/mingw64/share/pkgconfig")
#Linux
##set(GTKMM_INCLUDE_DIRS "/usr/include")
##set(GTKMM_LIBRARY_DIRS "/usr/lib/x86_64-linux-gnu")
##set(CURL_INCLUDE_DIRS "/usr/include/x86_64-linux-gnu")
##set(CURL_LIBRARY_DIRS "libcurl")
##set(GTKMM_INCLUDE_DIRS "/usr/lib/x86_64-linux-gnu")
##set(PKG_CONFIG_PATH "/usr/lib/x86_64-linux-gnu/pkgconfig:/usr/share/pkgconfig")
#---------------end linux
#
#set(CMAKE_SYSTEM_NAME Window)
#set(CMAKE_CXX_COMPILER "FILEPATH=C:/msys64/mingw64/bin/g++")
#set(CMAKE_C_COMPILER "FILEPATH=C:/msys64/mingw64/bin/gcc")
#set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64/lib/pkgconfig;C:/msys64/ucrt64/share/pkgconfig")

find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
pkg_check_modules(GLIBMM REQUIRED glibmm-2.68)
pkg_check_modules(LIBCURL REQUIRED libcurl)
add_subdirectory(src)
#add_executable(app src/main.cpp)
#set_target_properties(app PROPERTIES WIN32_EXECUTABLE true)  # If you dont want console to run with your .exe
#target_link_libraries(app ${GTKMM_LIBRARIES})
