#pragma once
#include<iostream>
using namespace std;
#include"LinkList.h"
#include"Song.h"

class PlayList
{
private:
	string Name;
	int ID;
	LinkedList<Song> songs;
	static int number_playlist;
public:
	PlayList(string name);
	string get_name();
	int get_id();
	LinkedList<Song>& get_songs();
	friend ostream& operator<<(ostream& os, const PlayList& playlist) {
		os << "PlayList [ID: " << playlist.ID << ", Name: " << playlist.Name << "]";
		return os;
	}
};









