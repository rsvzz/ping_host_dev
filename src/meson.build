inc_src = include_directories(['.','../inc/win', '../inc/win/model']) #gtkwin main
src_files = files('main.cpp')
gtkmm_dep = dependency('gtkmm-4.0')
glibmm_dep = dependency('glibmm-2.68', required: true)
curl_dep = dependency('libcurl', required: true)
jsonc_dep = dependency('jsoncpp', required: true)

#inc_model = include_directories('../inc/model')
#inc_curl = include_directories('../inc/curl')
#inc_jcpp = include_directories('../inc/jcpp')

subdir('models')
subdir('curl_model')
subdir('gtkwin')
subdir('jcpp')

executable(
  'troping',
  sources: src_files,
  dependencies: [gtkmm_dep, glibmm_dep, curl_dep, jsonc_dep],
  include_directories: [inc_src],# inc_model, inc_curl, inc_jcpp],
  link_with: [model_dep, jcpp_dep, curl_model_dep, gtkwin_dep]
  #link_args: ['/SUBSYSTEM:WINDOWS'] #windows,
)