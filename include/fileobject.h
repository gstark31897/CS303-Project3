#ifndef H_FILEOBJECT
#define H_FILEOBJECT

#include <string>


class FileObject
{
private:
    std::string m_name;

public:
    FileObject(std::string name): m_name(name) {};

    std::string getName() { return m_name; };

    bool operator<(FileObject &other) { return m_name < other.getName(); };
    bool operator>(FileObject &other) { return m_name > other.getName(); };
    
    std::string parse_path(std::string path)
    {
        int pCount = 0; 
    
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/')
            {
                pCount++;
            }
        }
    
        pCount += 1;
        std::string pArray[pCount]; 
        pArray[0] = path; 
    
        for(int j = 0; j < pCount; j++)
        {
            int position = pArray[j].find('/');
            pArray[j+1] = substr(position, pArray[j].size());
        }
        
        return pArray[pCount - 1]; 
    }
};

#endif
