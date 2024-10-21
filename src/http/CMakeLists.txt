add_library(http ClientRequest.cpp)
include_directories(models)
include_directories(objlcurl)

target_include_directories(http PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(http PUBLIC models objlcurl)
target_link_libraries(http PUBLIC ${CURL_LIBRARIES})