inc_src = include_directories('../../inc/jcpp')

src_files = files(['SaveInfo.cpp', 'ReadFileJson.cpp'])
jsoncpp_dep = dependency('jsoncpp', required : true)

jcpp_dep = static_library(
            'jcpplib',
             sources: src_files,
             dependencies:[jsoncpp_dep],
             include_directories : [inc_src],
             install : false)


