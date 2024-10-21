
add_library(gtkwin RequestStart.cpp GtkMainWin.cpp)
include_directories(models)
include_directories(objlcurl)

target_include_directories(gtkwin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gtkwin PUBLIC models objlcurl)
target_link_libraries(gtkwin PUBLIC ${GTKMM_LIBRARIES})

