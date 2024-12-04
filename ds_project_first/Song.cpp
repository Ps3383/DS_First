#include "Song.h"


int Song:: number_so = 0;


Song::~Song() {
	// در صورتی که نیاز به انجام کار خاصی باشد، اینجا می‌توانید کد بنویسید.
	// به عنوان مثال اگر منابعی به صورت پویا تخصیص داده شده باشد، می‌توانید آن‌ها را آزاد کنید.
}

Song::Song(string name, int year, string text) {
	Name = name;
	ID = number_so;
	Year = year;
	Text = text;
	number_so += 2;
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