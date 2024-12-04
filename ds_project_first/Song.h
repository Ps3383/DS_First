#pragma once
#include<iostream>
using namespace std;

class Song
{
private:
	string Name;
	int ID;
	int Year;
	string Text;
	static int number_so;
public:
	Song(string name = "", int year = -1, string text = "");
	~Song();
	int get_year();
	int get_id();
	string get_text();
	string get_name();
	friend ostream& operator<<(ostream& os, const Song& song) {
		os << "Song [ID: " << song.ID << ", Name: " << song.Name << ", Year: " << song.Year << ", Text: " << song.Text << "]";
		return os;
	}
};



