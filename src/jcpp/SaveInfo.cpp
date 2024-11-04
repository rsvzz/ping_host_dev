#include "../../inc/jcpp/SaveInfo.hpp"

SaveInfo::SaveInfo(string path) : 
                ReadFileJson<StFile>::ReadFileJson(path)
{
}

SaveInfo::~SaveInfo()
{
}

StFile* SaveInfo::get_obj_file(){

    auto root = get_root_json();

    if (root != NULL)
    {
        StFile *item = new StFile;

        item->host_name = (*root)["host"].asString();
        item->rq_count = (*root)["rq_count"].asInt();
        return item;
    }

    return NULL;
}
void SaveInfo::set_obj_file(StFile* item){
    
    Json::Value root;
    root["host"] = item->host_name;
    root["rq_count"] = item->rq_count; //(*root)["name"] pointer

    set_root_json(root);
    
}