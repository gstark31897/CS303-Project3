#include "folder.h"
#include <iostream>

using namespace std;


int main()
{
    Folder *folder = new Folder("root", 0);
    cout << "Making root/folder2" << endl;
    folder->add_folder("root", "folder2");
    cout << "Making root/folder2/folder3" << endl;
    folder->add_folder("root/folder2", "folder3");

    folder->delete_folder("root/folder2", "folder3");

    std::cout << *folder << std::endl;

    return 0;
}
