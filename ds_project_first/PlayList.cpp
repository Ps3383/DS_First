#include "PlayList.h"

int PlayList::number_playlist = 1000;

PlayList::PlayList(string name) {
		Name = name;
		ID = number_playlist;
		this->number_playlist += 2;
}

int PlayList::get_id() {
	return this->ID;
}

string PlayList::get_name() {
	return this->Name;
}

LinkedList<Song>& PlayList::get_songs() {
	return this->songs;
}

bool PlayList::operator==(const PlayList& other) const {
	return (ID == other.ID);
}

ostream& operator<<(ostream& os, const PlayList& playlist) {
	os << "PlayList [ID: " << playlist.ID << ", Name: " << playlist.Name << "]";
	return os;
}