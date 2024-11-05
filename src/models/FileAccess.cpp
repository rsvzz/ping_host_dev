#include "../../inc/model/FileAccess.hpp"
FileAccess::FileAccess(/* args */)
{
}

FileAccess::~FileAccess()
{
}

bool FileAccess::save_file(char *_path, AccessFile _data)
{
    return true;
}

AccessFile FileAccess::get_file_content(char *_path){
    return AccessFile();
}