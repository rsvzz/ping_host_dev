inc_gtk_model_src = include_directories(
    [
        '../../../inc/win/model', 
        '../../../inc/model',
        '../../../inc/curl'
        ])

gtkmm_dep = dependency('gtkmm-4.0')
curl_dep = dependency('libcurl', required: true)

src_files = files('RequestStart.cpp')

gtk_model_dep=static_library(
    'gtk_model_lib',
    sources: src_files,
    include_directories: [inc_gtk_model_src],
    dependencies: [gtkmm_dep, curl_dep],
    install: false
)