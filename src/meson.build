inc_src = include_directories(
  [
    '..',
    '../inc/win',
    '../inc/win/model',
    '../inc/curl',
    '../inc/model',
    '../inc/jcpp',
  ],
)

gtkmm_dep = dependency('gtkmm-4.0')
glibmm_dep = dependency('glibmm-2.68', required: true)
curl_dep = dependency('libcurl', required: true)
jsonc_dep = dependency('jsoncpp', required: true)

subdir('models')
subdir('curl_model')
subdir('gtk_model')
subdir('jcpp')

gtk_win_dep = static_library('wingtk_lib',
sources: 'GtkMainWin.cpp',
include_directories: inc_src,
link_with: [
   model_dep, jcpp_dep, curl_model_dep, gtk_model_dep
],
dependencies: [gtkmm_dep, glibmm_dep, curl_dep, jsonc_dep])

executable('troping',
  sources: 'main.cpp',
  dependencies: [gtkmm_dep, glibmm_dep, curl_dep, jsonc_dep],
  include_directories: [inc_src], # inc_model, inc_curl, inc_jcpp],
   link_with: [
      model_dep, jcpp_dep, curl_model_dep, gtk_model_dep, gtk_win_dep
   ],
  #link_args: ['/SUBSYSTEM:WINDOWS'] #windows,,
)