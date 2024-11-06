inc_src = include_directories(['../../inc/curl','../../inc/model'])

src_files = files(['HttpRequestCurl.cpp', 'ClientRequest.cpp'])
curl_dep = dependency('libcurl', required : true)

curl_model_dep = static_library(
            'curl_model_lib',
             sources: src_files,
             include_directories : inc_src,
             dependencies : [curl_dep],
             install : false)

