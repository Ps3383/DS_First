#include <iostream>
#include"LinkList.h"
#include"Singer.h"
#include"Song.h"
#include"SparseSet.h"
using namespace std;

int main()
{
	SparseSet set(100, 100);
	Singer* singers[100];
	int count_singers = 0;

	while (true)
	{
		cout << "Press 1 to add Singer\n";
		cout << "Press 2 to delete Singer\n";
		cout << "Press 3 to find a singer and print all information\n";
		cout << "Press 4 to print all information of Singers\n";
		cout << "Press 5 to delete everything !\n";
		cout << "Press 6 to add new Music \n";
		cout << "Press 7 to find a Music and print its information\n";
		cout << "Press 8 to delete a Music \n";


		cout << "Press 50 to exit\n";

		int n = 0;
		cin >> n;
		if (n == 1) {
			cout << "Enter name of the singer : ";
			string name;
			cin >> name;
			singers[count_singers] = new Singer(name);
			set.insert(singers[count_singers]);
			++count_singers;
		}
		else if (n == 2) {
			int del_id = -1;
			cout << "Enter ID of singer that you want to delete : ";
			cin >> del_id;
			set.erase(del_id);
		}
		else if (n == 3) {
			int show_id = -1;
			cout << "Enter ID of singer that you want see information : ";
			cin >> show_id;
			set.find_singer_print_info(show_id);
			puts("");
		}
		else if (n == 4) {
			set.print_all_singers();
		}
		else if (n == 5) {
			set.clear();
		}
		else if (n == 6) {
			string music_name;
			int year = 0;
			string text_s;
			string artist;
			cout << "Enter Music name : ";
			cin >> music_name;
			cout << "Enter year of music : ";
			cin >> year;
			cout << "Enter text of the song : ";
			cin >> text_s;
			cout << "Enter Artist of the song : ";
			cin >> artist;
			Singer * si = set.find_singer_byname(singers, count_singers, artist);
			if (si != nullptr) {
				Song song(music_name, year, text_s);
				si->get_songs().push_back((song));
				cout << "Song successfully added (:\n\n";
			}
		}
		else if (n == 7) {
			string name_music;
			cout << "Enter name of the Music : ";
			cin >> name_music;
			set.find_amusic_print(singers, count_singers, name_music);
		}
		else if (n == 8) {
			try {
				int id_music, id_singer;
				cout << "Enter ID of Music you want to delete(by space) : ";
				cin >> id_music >> id_singer;
				set.delete_music(singers, count_singers, id_music);
			}
			catch (...) {
				cout << "error";
			}
		}
		else if (n == 9) {
			break;
		}
		else if (n == 50) {
			break;
		}
	}
}

