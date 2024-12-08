#include "Song.h"


int Song:: number_so = 0;


Song::~Song() {

}

Song::Song(string name, int year, string text) {
	Name = name;
	if (year == -1) {
		ID = -12532551; 
	}
	else {
		ID = number_so;	
		number_so += 2;
	}
	Year = year;
	Text = text;
}


string Song::get_name() {
	return this->Name;
}

int Song::get_id() {
	return this->ID;
}

int Song::get_year() {
	return this->Year;
}

string Song::get_text() {
	return this->Text;
}