inc_http = include_directories('.')
http_files = files(['ClientRequest.cpp'])
curl_dep = dependency('libcurl')

inc_model = include_directories('../models')
inc_obj = include_directories('../objlcurl')

http_dep = static_library(
            'httplib',
             sources: http_files,
             dependencies: [curl_dep],
             include_directories : [inc_http,inc_model, inc_obj],
             link_with: [model_dep, objcurl_dep],
             install : true)