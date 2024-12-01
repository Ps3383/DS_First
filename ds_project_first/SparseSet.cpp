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
    if (singer.get_id() > maxID || n >= capacity || contains(singer.get_id()))
        return;

    dense[n] = singer;
    sparse[singer.get_id()] = n;
    n++;
}

void SparseSet::erase(int id) {
    if (id > maxID || !contains(id))
        return;

    int index = sparse[id];
    Singer lastSinger = dense[n - 1];

    dense[index] = lastSinger;
    sparse[lastSinger.get_id()] = index;
    sparse[id] = -1;
    n--;
}

bool SparseSet::contains(int id) const {
    return id <= maxID && sparse[id] != -1 && sparse[id] < n;
}

Singer& SparseSet::get(int id) const {
    if (!contains(id))
        throw runtime_error("Singer not found!");
    return dense[sparse[id]];
}

void SparseSet::print() const {
    for (int i = 0; i < n; i++) {
        cout << dense[i] << endl;
        dense[i].get_songs().display();
    }
}
void SparseSet::clear() {
    n = 0;
}