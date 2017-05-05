#include "folder.h"

#include <iostream>
#include <string>

using namespace std;


void Folder::add_folder(string path, string name)
{
    get_folder(path, 0, 0)->m_folderTree.insert(new Folder(name, 0));
}


Folder* Folder::get_folder(string path, size_t depth, int size)
{
    // this directory is the deepest we want to go, return it
    if (path_length(path) == depth)
        return this;
    // no path, this is the directory we're looking for
    if (path == "")
    {
        return this;
    }
    else
    {
        // get the first segment of the path
        string front = path_pop(path);
        // call our own method with an empty string if this is us
        if (front == getName())
        {
            front = path_pop(path);
            return get_folder(path, 0, size);
        }
        else
        {
            // find the corresponding folder and call this method on it (with the reduced path)
            Folder *findFolder = new Folder(front, 0);
            Folder *folder = m_folderTree.find(findFolder);
            delete findFolder;
            return folder;
        }
    }
}


File* Folder::get_file(string path, string file_name)
{
    // find the folder we're looking for
    File *findFile = new File(file_name, 0);
    // find the file inside and return it
    File *file = get_folder(path, 0, 0)->m_fileTree.find(findFile);
    delete findFile;
    return file;
}


void Folder::delete_folder(string path, string name)
{
    // get the folder that we're looking for
    Folder *temp = get_folder(path, 0, 0);
    // get its size
    int size = temp->getSize();
    // get the folder above the one we want to delete and reduce the sizes while we're at it
    temp = get_folder(path, 1, -1*size);
    // erase the folder
    string front = path_pop(path);
    Folder *findFolder = new Folder(front, 0);
    temp->m_folderTree.erase(findFolder);
    delete findFolder;
}


void Folder::add_file(string path, string file_name, int size)
{
    // find the folder, add a new file to it, increment the folder sizes while we find the folder
    get_folder(path, 0, size)->m_fileTree.insert(new File(file_name, size));
}


std::list<File*> Folder::get_files(std::string path, std::string file_name)
{
    // get the folder
    Folder *folder = get_folder(path, 0, 0);
    // get the files in the folder
    list<File*> file_list;
    folder->get_files_inside(file_name, folder->m_fileTree, file_list);
    // return the files
    return file_list;
}


void Folder::get_files_inside(std::string file_name, AVL_Tree<File*> tree, std::list<File*> &file_list)
{
    // is the tree null? return
    if (tree.is_null())
        return;
    // add the item to the list if it's name matches
    if (tree.get_data()->getName().find(file_name) == 0)
        file_list.push_back(tree.get_data());
    // do the same for the left and right subtrees
    get_files_inside(file_name, tree.get_left_subtree(), file_list);
    get_files_inside(file_name, tree.get_right_subtree(), file_list);
}


void Folder::delete_file(string path, string file_name)
{
    // find the folder
    Folder *temp = get_folder(path, 0, 0);
    string front = path_pop(path);
    // get the file and check its size
    File *findFile = new File(front, 0);
    int size = temp->m_fileTree.find(findFile)->getSize();
    delete findFile;
    // remove the file
    temp->m_fileTree.erase(new File(front, 0));
    // iterate over the folders again, but decrement their size
    temp = get_folder(path, 0, -1*size);
}


std::ostream& operator<<(std::ostream &out, const Folder &folder)
{
    return out << folder.getName();
}

