inc_win_src = include_directories('../../inc/win')
#En el mismo file
inc_win_model_src = include_directories('../../inc/win/model')
#para no agregar otro meson.build subdirectorio
src_files = files(['GtkMainWin.cpp', 'model/RequestStart.cpp'])

gtkmm_dep = dependency('gtkmm-4.0')
glibmm_dep = dependency('glibmm-2.68', required: true)
curl_dep = dependency('libcurl', required : true)
jsonc_dep = dependency('jsoncpp', required : true)

inc_model = include_directories('../../inc/model')
inc_curl = include_directories('../../inc/curl')
inc_jcpp = include_directories('../../inc/jcpp')


gtkwin_dep = static_library(
            'gwlib',
             sources: src_files,
             #include_directories: [inc_win],
             include_directories : [inc_win_src, inc_win_model_src, inc_model, inc_curl, inc_jcpp],
             #link_with: [model_dep, objcurl_dep, http_dep, libjson_dep],
             dependencies: [gtkmm_dep,glibmm_dep, curl_dep, jsonc_dep],
             install : false)
