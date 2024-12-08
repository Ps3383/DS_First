#pragma once
#include<iostream>
using namespace std;
#include"LinkList.h"
#include"Song.h"

class Singer
{
private:
	string Name;
	int ID;
	LinkedList<Song> songs;
	static int number_singer;

public:
	Singer(string name);
	string get_name();
	int get_id();
	LinkedList<Song>& get_songs();
	friend ostream& operator<<(ostream& os, const Singer& singer) {
		os << "Singer [ID: " << singer.ID << ", Name: " << singer.Name << "]";
		return os;
	}
};







