#ifndef H_FILEOBJECT
#define H_FILEOBJECT

#include <string>
#include <iostream>
#include <algorithm>


class FileObject
{
private:
    std::string m_name;
    int m_size;

public:
    FileObject(std::string name, int size): m_name(name), m_size(size) {};

    void setName(std::string name) { m_name = name; };
    std::string getName() const { return m_name; };

    void setSize(int size) { m_size = size; };
    int getSize() const { return m_size; };

    bool operator<(FileObject &other) const { return m_name < other.getName(); };
    bool operator<(const FileObject &other) const { return m_name < other.getName(); };
    bool operator>(FileObject &other) const { return m_name > other.getName(); };
    bool operator>(const FileObject &other) const { return m_name > other.getName(); };

    std::string path_pop(std::string &path)
    {
        // find the first directory in the string, remove it, and return it
        // find the first slash
        size_t pos = path.find('/');
        // no slashes, return the entire string as the directory
        if (pos == -1)
        {
            std::string front = path;
            path = "";
            return front;
        }
        // see if the string starts with a slash
        size_t start = 0;
        if (pos == 0)
        {
            start = 1; 
            pos = path.find(1, '/');
            // return the string without the slash as the path
            if (pos == -1)
            {
                std::string front = path; 
                path = "";
                return front;
            }
        }
        // pull the first segment of the path
        std::string front = path.substr(start, pos);
        // remove the first segment of the path
        path = path.substr(pos, path.size());
        // return the first segment of the path
        return front;
    };

    size_t path_length(std::string &path)
    {
        // find how many directories are in the string
        size_t n = std::count(path.begin(), path.end(), '/');
        // subtract one if it starts with one
        if (path.find('/') == 0)
            --n;
        return n;
    }
};

#endif
