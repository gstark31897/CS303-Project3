#include "folder.h"

#include <iostream>
#include <string>

using namespace std;


void Folder::add_folder(string path, string name)
{
    get_folder(path, 0)->m_folderTree.insert(new Folder(name, 0));
}


Folder* Folder::get_folder(string path, size_t depth)
{
    if (path_length(path) == depth)
        return this;
    if (path == "")
    {
        cout << "No path, inserting here" << endl;
        return this;
    }
    else
    {
        string front = path_pop(path);
        if (front == getName())
        {
            cout << "Myself, inserting to self: " << path << endl;
            front = path_pop(path);
            return get_folder(path, 0);
        }
        else
        {
            cout << "Looking for folder: " << path << endl;
            return m_folderTree.find(new Folder(front, 0));
        }
    }
}


File* Folder::get_file(string path, string file_name)
{
    return get_folder(path, 0)->m_fileTree.find(new File(file_name, 0));
}


void Folder::delete_folder(string path, string name)
{
    Folder *temp = get_folder(path, 1);
    string front = path_pop(path);
    temp->m_folderTree.erase(new Folder(front, 0));
}


std::ostream& operator<<(std::ostream &out, const Folder &folder)
{
    return out << folder.getName();
}


void Folder::add_file(string path, string file_name, int size)
{
    get_folder(path, 0)->m_fileTree.insert(new File(file_name, size));
}


std::list<File*> Folder::get_files(std::string path, std::string file_name)
{
    Folder *folder = get_folder(path, 0);
    list<File*> file_list;
    folder->get_files_inside(file_name, folder->m_fileTree, file_list);
    return file_list;
}


void Folder::get_files_inside(std::string file_name, AVL_Tree<File*> tree, std::list<File*> &file_list)
{
    if (tree.is_null())
        return;
    if (tree.get_data()->getName().find(file_name) == 0)
        file_list.push_back(tree.get_data());
    get_files_inside(file_name, tree.get_left_subtree(), file_list);
    get_files_inside(file_name, tree.get_right_subtree(), file_list);
}


void Folder::delete_file(string path, string file_name)
{
    Folder *temp = get_folder(path, 0);
    string front = path_pop(path);
    temp->m_fileTree.erase(new File(front, 0));
}

