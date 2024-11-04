#pragma once
#include "ReadFileJson.hpp"
#include "../model/ItemData.hpp"
class SaveInfo : public ReadFileJson<StFile>
{
private:
    /* data */
public:
    SaveInfo(string);
    ~SaveInfo();

    StFile* get_obj_file() override;
    void set_obj_file(StFile*) override;
};
