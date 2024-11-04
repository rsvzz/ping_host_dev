struct ItemFile
{
    /* data */
    char *host_name;
    int request;
};

struct AccessFile
{
    /* data */
    char *code;
    ItemFile *content;
};

class FileAccess
{
private:
    /* data */
public:
    FileAccess();
    ~FileAccess();
    AccessFile get_file_content(char *);
    bool save_file(char *, AccessFile);
};
