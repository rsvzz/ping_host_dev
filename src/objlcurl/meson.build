inc_obj = include_directories('.')

objlcurl_files = files(['HttpRequestCurl.cpp'])
curl_dep = dependency('libcurl')
objcurl_dep = static_library(
            'oblib',
             sources: objlcurl_files,
             include_directories : inc_obj,
             dependencies : [curl_dep],
             install : true)

