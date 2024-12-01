#include "Singer.h"


int Singer::number_singer = -199;

Singer::Singer(string name) {
	Name = name;
	ID = number_singer;
	this->number_singer += 2;
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