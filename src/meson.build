src_files = files('main.cpp')
gtkmm_dep = dependency('gtkmm-4.0')
glibmm_dep = dependency('glibmm-2.68')
inc = include_directories('gtkwin')


subdir('models')
subdir('objlcurl')
subdir('http')
subdir('gtkwin')

inc_model = include_directories('models')
inc_obj = include_directories('objlcurl')
inc_gwin = include_directories('gtkwin')
inc_http = include_directories('http')

executable('phdev', 
  sources : src_files,
  dependencies : [gtkmm_dep, glibmm_dep],
  include_directories :[inc, inc_model, inc_obj, inc_gwin, inc_http],
  link_with : [gtkwin_dep, model_dep, objcurl_dep, http_dep]
  )
