#include "folder.h"
#include <iostream>


int main()
{
    Folder *folder = new Folder("root", 0);
    folder->add_folder("/root", "folder2");

    std::cout << folder << std::endl;

    return 0;
}
