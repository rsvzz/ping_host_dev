
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
#include_directories(${CURL_INCLUDE_DIR})
link_directories(${CURL_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

add_subdirectory(models)
add_subdirectory(objlcurl)
add_subdirectory(gtkwin)
add_subdirectory(http)
add_executable(app main.cpp)
#target_compile_definitions(app PRIVATE _HAS_STD_BYTE=0)
target_link_libraries(app PUBLIC models objlcurl http gtkwin)
target_link_libraries(app PUBLIC ${GTKMM_LIBRARIES})
target_link_libraries(app PUBLIC ${CURL_LIBRARIES})



#target_link_libraries(app PUBLIC objlcurl ${GTKMM_LIBRARIES})
#set_target_properties(app PROPERTIES WIN32_EXECUTABLE true)  # If you dont want console to run with your .exe
