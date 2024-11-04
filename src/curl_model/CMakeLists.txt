add_library(objlcurl HttpRequestCurl.cpp)
target_include_directories(objlcurl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(objlcurl PUBLIC ${CURL_LIBRARIES})