add_library(jsoncpplib SaveInfo.cpp)

target_include_directories(jsoncpplib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(jsoncpplib ${JSONCPP_LIBRARIES})

