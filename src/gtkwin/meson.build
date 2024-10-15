inc_win = include_directories('.')

gtkwin_files = files(['GtkMainWin.cpp', 'ClientRequest.cpp', 'RequestStart.cpp'])
gtkmm_dep = dependency('gtkmm-4.0')
curl_dep = dependency('libcurl')

inc_model = include_directories('../models')
inc_obj = include_directories('../objlcurl')
gtkwin_dep = static_library(
            'gwlib',
             sources: gtkwin_files,
             dependencies: [gtkmm_dep, curl_dep],
             include_directories : [inc_win, inc_model, inc_obj],
             link_with: [model_dep, objcurl_dep],
             install : true)
