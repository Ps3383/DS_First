#pragma once
#include<iostream>
#include"LinkList.h"
#include"Singer.h"
using namespace std;

int partition(Song* songs, int low, int high);
void quick_sort(Song* songs, int low, int high);

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
    void erase(T* singers[] , int id);
    bool valid(int id) const;
    void print_all_singers() const;
    void find_singer_print_info(int id) const;
    void clear();
    T* find_singer_byname(T * singers[] , int numbers , string name);
    void find_amusic_print(T * singers[] ,int numbers ,string name);
    void delete_music(T* singers[], int numbers, int id , int idp);
    T* find_playlist_byID(T* playlists[], int numbers, int id);
    Song findAmusic_forAddtoPlaylist(T* playlists[], int numbers, int id);
    void print_all_playlists() const;
    void print_one_playlist(int id)const;
    void find_amusic_print_play(T* playlists[], int numbers, int id , int idp);
    void find_playlist_print_info(int id) const;
    void delete_musicFrom_play(T* playlists[], int numbers, int idm, int ids);
    void delete_musicFrom_ALLplay(T* playlists[], int numbers, int idm);
    T& find_playlist_return(int id);
    void find_patternIN_music(T* singers[], int numbers, int idm, int ids, string pat);
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
    if (singer->get_id() > maxID || n >= capacity || valid(singer->get_id())) {
        cout << "something has problem !\n";
    }
    else {
        dense[n] = singer;
        sparse[singer->get_id()] = n;
        n++;
    }
}

template <typename T>
void SparseSet<T>::erase(T* singers[] ,int id) {
    if (id > maxID || !valid(id))
        cout << "ID is out of range !\n";
    else {

        int index = sparse[id];
        LinkedList<Song>& l = singers[index]->get_songs();
        for (int j = l.size_of_list() - 1; j >= 0; --j) {
            l.erase_index(j);
        }
        T* lastSinger = dense[n - 1];

        dense[index] = lastSinger;
        sparse[lastSinger->get_id()] = index;
        sparse[id] = -1;

        n--;
        cout << "singer with ID = " << id << " successfully deleted !\n\n";
    }
}

template <typename T>
bool SparseSet<T>::valid(int id) const {
    return id <= maxID && sparse[id] != -1 && sparse[id] < n;
}

//template <typename T>
//T* SparseSet<T>::get(int id) const {
//    if (!contains(id))
//        throw runtime_error("Singer not found!");
//    return dense[sparse[id]];
//}


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
    if (valid(id)) {
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
        cout << "Music with name = " << name << " does not exist !\n";
}


template <typename T>
void SparseSet<T>::delete_music(T* singers[], int numbers, int idm , int ids) {
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song>& l = singers[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song& s = l.index(j);
            if (s.get_id() == idm && singers[i]->get_id()==ids) {
                l.erase_index(j);
                cout << "Music with ID = " << idm << " has been deleted !\n\n";
                return;
            }
        }
    }
    cout << "Music or Singer does not exist !\n\n";
}


template <typename T>
T* SparseSet<T>::find_playlist_byID(T* playlists[], int numbers, int id) {
    int low = 0;
    int high = numbers-1;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (playlists[middle]->get_id() == id) {
            return playlists[middle];
        }
        else if (playlists[middle]->get_id() < id) {
            low = middle + 1;
        }
        else {
            high = middle - 1; 
        }
    }
    cout << "PlayList with ID = " << id << " does not exist ! \n\n";
    //cout << "Unsuccessful to add this Music to PlayList ):\n\n";
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
        cout << "Music with ID = " << id << " does not exist !\n\n";
    Song re("null");
    return re;
}

template <typename T>
void SparseSet<T>::find_amusic_print_play(T* playlists[], int numbers, int idm , int idp) {
    bool find = false;
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song> l = playlists[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song s = l.index(j);
            if (s.get_id() == idm && playlists[i]->get_id() == idp) {
                cout << s;
                puts("\n");
                find = true;
            }
        }
    }
    if (!find)
        cout << "Music with ID = " << idm << " or PlayList with ID = " << idp << " does not exist\n\n";
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
void SparseSet<T>::print_one_playlist(int id) const {
    if (id > maxID || !valid(id)) {
        cout << "PlayList with ID = " << id << " does not exist\n\n";
        return;
    }
    if (valid(id)) {
        int index = sparse[id];
        puts("");
        cout << *dense[index] << endl;
        if (dense[index]->get_songs().empty()) {
            cout << "this playlist does not have any songs ):\n";
        }
        else {
            dense[index]->get_songs().display();
        }   
        puts("");
    }

    else {
        cout << "PlayList with ID = " << id << " does not exist\n\n";
    }
}


template <typename T>
void SparseSet<T>::find_playlist_print_info(int id) const {
    if (id > maxID || !valid(id)) {
        cout << "PlayList with ID = " << id << " does not exist\n\n";
        return;
    }
    if (valid(id)) {
        int index = sparse[id];
        puts("");
        cout << *dense[index] << endl;
        if (dense[index]->get_songs().empty()) {
            cout << "this playlist does not have any songs ):\n";
        }
        else {
             LinkedList<Song> & l = dense[index]->get_songs();
             int size = l.size_of_list();
             Song* songArray = new Song[size];
             for (int i = 0; i < size; ++i) {
                 songArray[i] = l.index(i);
             }

             quick_sort(songArray, 0, size - 1);

             cout << "Songs in this playlist (sorted by year):\n";
             for (int i = 0; i < size; ++i) {
                 cout << "Song Name : "<<
                 songArray[i].get_name() 
                 << "\t "<<"Song Year : " << songArray[i].get_year()
                    <<"\t " << "Song Text : " << songArray[i].get_text() << endl;
             }
             cout << endl;
             delete[] songArray; 
        }
    }
    else {
        cout << "PlayList with ID = " << id << " does not exist\n\n";
    }
}


template <typename T>
void SparseSet<T>::delete_musicFrom_play(T* playlists[], int numbers, int idm, int idp) {
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song>& l = playlists[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song& s = l.index(j);
            if (s.get_id() == idm && playlists[i]->get_id() == idp) {
                l.erase_index(j);
                cout << "Music with ID = " << idm << " has been deleted\n\n";
                return;
            }
        }
    }
    cout << "Music with ID = " << idm << " or PlayList with ID = " << idp << " does not exist\n\n";
}

template <typename T>
void SparseSet<T>::delete_musicFrom_ALLplay(T* playlists[], int numbers, int idm) {
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song>& l = playlists[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song& s = l.index(j);
            if (s.get_id() == idm) {
                l.erase_index(j);
            }
        }
    }
}

template <typename T>
T& SparseSet<T>::find_playlist_return(int id) {
    int index = sparse[id];
    if (valid(id)) {
        return *dense[index];
    }
    else {
        cout << "PlayList with ID = " << id << " does not exist\n\n";
    }
}

template <typename T>
void SparseSet<T>::find_patternIN_music(T* singers[], int numbers, int idm, int ids,string pat) {
    for (int i = 0; i < numbers; ++i) {
        LinkedList<Song>& l = singers[i]->get_songs();
        for (int j = 0; j < l.size_of_list(); ++j) {
            Song& s = l.index(j);
            if (s.get_id() == idm && singers[i]->get_id() == ids) {
                int place = s.find_pattern(pat);
                if (place!= -1) {
                    cout << "Pattern = [" << pat <<"] was found at index = " 
                    << place <<endl<< endl;
                    return;
                }
                else {
                    cout << "Pattern = ["<< pat<<"] didnt find at music with ID = "
                       << idm << endl << endl;
                    return;
                }
            }
        }
    }
    cout << "Music or Singer does not exist !\n\n";
}




int partition(Song* songs, int low, int high) {
    int pivotYear = songs[high].get_year();
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (songs[j].get_year() <= pivotYear) {
            ++i;
            swap(songs[i], songs[j]);
        }
    }
    swap(songs[i + 1], songs[high]);
    return i + 1;
}
void quick_sort(Song* songs, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(songs, low, high);
        quick_sort(songs, low, pivotIndex - 1);
        quick_sort(songs, pivotIndex + 1, high);
    }
}
