#pragma once
#include<iostream>
#include"LinkList.h"
#include"Singer.h"

using namespace std;

class SparseSet {
private:
    int* sparse;
    Singer* dense;
    int maxID;
    int capacity;
    int n;
public:
    SparseSet(int maxID, int capacity);
    ~SparseSet();
    void insert(Singer singer);
    void erase(int id);
    bool contains(int id) const;
    Singer& get(int id) const;
    void print_all_singers() const;
    void find_singer_print_info(int id) const;
    void clear();

};





