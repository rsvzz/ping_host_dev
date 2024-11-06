inc_src = include_directories(['../../inc/jcpp', '../../inc/model'])
src_files = files(['SaveInfo.cpp'])
jsoncpp_dep = dependency('jsoncpp', required : true)

jcpp_dep=static_library(
            'jcpp_lib',
             sources: src_files,
             dependencies:[jsoncpp_dep],
             include_directories : [inc_src],
             install : false)


