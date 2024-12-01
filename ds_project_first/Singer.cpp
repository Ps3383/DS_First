#include "Singer.h"
int Singer::number_s = 1;

Singer::Singer(string name) {
	Name = name;
	ID = number_s;
	this->number_s += 2;
}


int Singer::get_id() {
	return this->ID;
}

string Singer::get_name() {
	return this->Name;
}

LinkedList<Song>& Singer::get_songs() {
	return this->songs;
}