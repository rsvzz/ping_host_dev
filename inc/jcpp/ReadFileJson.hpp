#pragma once
#include <iostream>
#include <fstream>
#include <json/json.h>
using std::string;
template <typename T>
class ReadFileJson
{
protected:
    /* data */
    string path_file;
    Json::Value* get_root_json();
    void set_root_json(Json::Value);

public:
    ReadFileJson(string);
    ~ReadFileJson();
    /// @brief obj json a manipular
    /// @return type obj
    virtual T* get_obj_file() = 0;
    /// @brief to write in file
    /// @param  Obj saves
    virtual void set_obj_file(T*) = 0;
};

// #include "tpp/ReadFileJson.tpp"

template <class T>
ReadFileJson<T>::ReadFileJson(string path)
{
    path_file = path;
}

template <class T>
ReadFileJson<T>::~ReadFileJson()
{
}

template <class T>
Json::Value* ReadFileJson<T>::get_root_json()
{
    std::ifstream file(path_file);
    if (!file.is_open())
    {
        return NULL;
    }

    Json::Value *root = new Json::Value;
    try
    {
        file >> (*root);//pointer
        return root;
    }
    catch (const std::exception &e)
    {
    }
    return NULL;
   
}

template <class T>
void ReadFileJson<T>::set_root_json(Json::Value root)
{
    std::ofstream archivo(path_file);
    archivo.clear();
    archivo << root; //(*root); pointer
    archivo.close();
}
