#pragma once
#include<iostream>
#include"LinkList.h"
#include"Singer.h"

using namespace std;

template <typename T>
class SparseSet {
private:
    int* sparse;
    T** dense;
    int maxID;
    int capacity;
    int n;
public:
    SparseSet(int maxID, int capacity);
    ~SparseSet();
    void insert(T *singer);
    void erase(int id);
    bool contains(int id) const;
    T* get(int id) const;
    void print_all_singers() const;
    void find_singer_print_info(int id) const;
    void clear();
    T* find_singer_byname(T * singers[] , int numbers , string name);
    void find_amusic_print(T * singers[] ,int numbers ,string name);
    void delete_music(T* singers[], int numbers, int id);
    T* find_playlist_byID(T* playlists[], int numbers, int id);
    Song findAmusic_forAddtoPlaylist(T* playlists[], int numbers, int id);
    void print_all_playlists() const;
    void find_playlist_print_info(int id) const;
};

template <typename T>
SparseSet<T>::SparseSet(int maxID, int capacity)
    : maxID(maxID), capacity(capacity), n(0) {
    sparse = new int[maxID + 1];
    dense = new T * [capacity];
    for (int i = 0; i <= maxID; i++)
        sparse[i] = -1;
}

template <typename T>
SparseSet<T>::~SparseSet() {
    delete[] sparse;
    delete[] dense;
}

template <typename T>
void SparseSet<T>::insert(T* singer) {
    if (singer->get_id() > maxID || n >= capacity || contains(singer->get_id())) {
        cout << "something has problem !\n";
    }
    else {
        dense[n] = singer;
        sparse[singer->get_id()] = n;
        n++;
    }
}

template <typename T>
void SparseSet<T>::erase(int id) {
    if (id > maxID || !contains(id))
        cout << "ID is out of range !\n";
    else {
        int index = sparse[id];
        T* lastSinger = dense[n - 1];

        dense[index] = lastSinger;
        sparse[lastSinger->get_id()] = index;
        sparse[id] = -1;
        n--;
        cout << "singer with ID = " << id << " successfully deleted !\n";
    }
}

template <typename T>
bool SparseSet<T>::contains(int id) const {
    return id <= maxID && sparse[id] != -1 && sparse[id] < n;
}

template <typename T>
T* SparseSet<T>::get(int id) const {
    if (!contains(id))
        throw runtime_error("Singer not found!");
    return dense[sparse[id]];
}


template <typename T>
void SparseSet<T>::print_all_singers() const {
    for (int i = 0; i < n; i++) {
        puts("");
        cout << *dense[i] << endl;
        if (dense[i]->get_songs().empty()) {
            cout << "this singer does not have any songs ):\n";
        }
        else {
            dense[i]->get_songs().display();
        }
    }
    puts("");
}


template <typename T>
void SparseSet<T>::find_singer_print_info(int id) const {
    int index = sparse[id];
    if (contains(id)) {
        puts("");
        cout << *dense[index] << endl;
        if (dense[index]->get_songs().empty()) {
            cout << "this singer does not have any songs ):\n";
        }
        else {
            dense[index]->get_songs().display();
        }
    }
    else {
        cout << "Singer with ID = " << id << " does not exist\n";
    }
}

template <typename T>
void SparseSet<T>::clear() {
    n = 0;
    cout << "everything was deleted ! \n\n";
}


template <typename T>
T* SparseSet<T>::find_singer_byname(T* singers[], int numbers, string name) {
    for (int i = 0; i < numbers; ++i) {
        if (singers[i]->get_name() == name) {
            return singers[i];
        }
    }
    cout << "Singer with name = " << name << " does not exist ! \n";
    cout << "Unsuccessful to add this Music ):\n\n";
    return nullptr;
}


template <typename T>
void SparseSet<T>::find_amusic_print(T* singers[], int numbers, string name) {
    bool find = false;
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song> l = singers[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song s = l.index(j);
            if (s.get_name() == name) {
                cout << s;
                puts("\n");
                find = true;
            }
        }
    }
    if(!find)
        cout << "Music with name = " << name << " does not exist\n";
}


template <typename T>
void SparseSet<T>::delete_music(T* singers[], int numbers, int id) {
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song>& l = singers[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song& s = l.index(j);
            if (s.get_id() == id) {
                l.erase_index(j);
                cout << "Music with ID = " << id << " has been deleted\n\n";
                return;
            }
        }
    }
    cout << "Music with ID = " << id << " does not exist\n\n";
}


template <typename T>
T* SparseSet<T>::find_playlist_byID(T* playlists[], int numbers, int id) {
    for (int i = 0; i < numbers; ++i) {
        if (playlists[i]->get_id() == id) {
            return playlists[i];
        }
    }
    cout << "PlayList with ID = " << id << " does not exist ! \n";
    cout << "Unsuccessful to add this Music to PlayList ):\n\n";
    return nullptr;
}



template <typename T>
Song SparseSet<T>::findAmusic_forAddtoPlaylist(T* singers[], int numbers, int id) {
    bool find = false;
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song> l = singers[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song s = l.index(j);
            if (s.get_id() == id) {
                return s;
                find = true;
            }
        }
    }
    if (!find)
        cout << "Music with ID = " << id << " does not exist\n\n";
    Song re("null");
    return re;
}


template <typename T>
void SparseSet<T>::print_all_playlists() const {
    for (int i = 0; i < n; i++) {
        puts("");
        cout << *dense[i] << endl;
        if (dense[i]->get_songs().empty()) {
            cout << "this playlist does not have any songs ):\n";
        }
        else {
            dense[i]->get_songs().display();
        }
    }
    puts("");
}



template <typename T>
void SparseSet<T>::find_playlist_print_info(int id) const {
    int index = sparse[id];
    if (contains(id)) {
        puts("");
        cout << *dense[index] << endl;
        if (dense[index]->get_songs().empty()) {
            cout << "this playlist does not have any songs ):\n";
        }
        else {
            dense[index]->get_songs().display();
        }
    }
    else {
        cout << "PlayList with ID = " << id << " does not exist\n\n";
    }
}