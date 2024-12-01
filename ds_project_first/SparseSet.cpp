#include "SparseSet.h"


SparseSet::SparseSet(int maxID, int capacity)
    : maxID(maxID), capacity(capacity), n(0) {
    sparse = new int[maxID + 1];
    dense = new Singer[capacity];
    for (int i = 0; i <= maxID; i++)
        sparse[i] = -1;
}

SparseSet::~SparseSet() {
    delete[] sparse;
    delete[] dense;
}

void SparseSet::insert(Singer singer) {
    if (singer.get_id() > maxID || n >= capacity || contains(singer.get_id())) {
        cout<<"something has problem !\n";
    }
    else {
        dense[n] = singer;
        sparse[singer.get_id()] = n;
        n++;
        cout << "singer successfully added !\n";
        puts("");
    }
}

void SparseSet::erase(int id) {
    if (id > maxID || !contains(id))
        cout<<"ID is out of range !\n";
    else {
        int index = sparse[id];
        Singer lastSinger = dense[n - 1];

        dense[index] = lastSinger;
        sparse[lastSinger.get_id()] = index;
        sparse[id] = -1;
        n--;
        cout << "singer with ID = " << id << " successfully deleted !\n";
    }
}

bool SparseSet::contains(int id) const {
    return id <= maxID && sparse[id] != -1 && sparse[id] < n;
}

Singer& SparseSet::get(int id) const {
    if (!contains(id))
        throw runtime_error("Singer not found!");
    return dense[sparse[id]];
}


void SparseSet::print_all_singers() const {
    for (int i = 0; i < n; i++) {
        puts("");
        cout << dense[i] << endl;
        if (dense[i].get_songs().empty()) {
            cout << "this singer does not have any songs ):\n";
        }
        else {
            dense[i].get_songs().display();
        }
    }
    puts("");
}

void SparseSet::find_singer_print_info(int id) const {
    int index = id;
    if (contains(id)) {
        puts("");
        cout << dense[index] << endl;
        if (dense[index].get_songs().empty()) {
            cout << "this singer does not have any songs ):\n";
        }
        else {
            dense[index].get_songs().display();
        }
    }
    else {
        puts("no found");
    }
}

void SparseSet::clear() {
    n = 0;
    cout << "everything was deleted ! \n\n";
}