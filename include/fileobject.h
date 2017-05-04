#ifndef H_FILEOBJECT
#define H_FILEOBJECT

#include <string>
#include <iostream>
#include <algorithm>


class FileObject
{
private:
    std::string m_name;

public:
    FileObject(std::string name): m_name(name) {};

    void setName(std::string name) { m_name = name; };
    std::string getName() const { return m_name; };

    bool operator<(FileObject &other) const { return m_name < other.getName(); };
    bool operator<(const FileObject &other) const { return m_name < other.getName(); };
    bool operator>(FileObject &other) const { return m_name > other.getName(); };
    bool operator>(const FileObject &other) const { return m_name > other.getName(); };

    std::string path_pop(std::string &path)
    {
        size_t pos = path.find('/');
        if (pos == -1)
        {
            std::string front = path;
            path = "";
            return front;
        }
        size_t start = 0;
        if (pos == 0)
        {
            start = 1; 
            pos = path.find(1, '/');
            if (pos == -1)
            {
                std::string front = path; 
                path = "";
                return front;
            }
        }
        std::string front = path.substr(start, pos);
        path = path.substr(pos, path.size());
        return front;
    };

    size_t path_length(std::string &path)
    {
        size_t n = std::count(path.begin(), path.end(), '/');
        if (path.find('/') == 0)
            --n;
        return n;
    }
};

#endif
