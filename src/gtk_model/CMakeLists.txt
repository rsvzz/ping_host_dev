
add_library(gtkwin RequestStart.cpp GtkMainWin.cpp)
include_directories(models)
include_directories(objlcurl)
include_directories(http)
include_directories(jsoncpplib)

target_include_directories(gtkwin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gtkwin PUBLIC models objlcurl http jsoncpplib)
target_link_libraries(gtkwin PUBLIC ${GTKMM_LIBRARIES})
target_link_libraries(gtkwin PUBLIC ${JSONCPP_LIBRARIES})

