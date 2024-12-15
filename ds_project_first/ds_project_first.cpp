#include <iostream>
#include"LinkList.h"
#include"Singer.h"
#include"Song.h"
#include"PlayList.h"
#include"SparseSet.h"
#include"myQueue.h"
using namespace std;

bool isInteger(const string& s);
int toInteger(const string& str);

int main()
{
	SparseSet<Singer> set(100, 100);  // max id    capa
	SparseSet<PlayList> set_play(2000, 2000);
	myQueue<PlayList> queue(100);    // capa
	
	Singer* singers[100];
	PlayList* playlists[100];

	int count_singers = 0;
	int count_playlists = 0;

	string x;
	while (true) {
		puts("");
		cout << "Welcome to this Program\n";
		cout << "Press 1 to use a Menu\n";
		cout << "Press 2 to use Commands\n";
		cout << "Press 3 to Exit\n";
		cin >> x;
		if (x == "1") {
			while (true)
			{
				cout << "Press 1 to add Singer\n";
				cout << "Press 2 to delete Singer\n";
				cout << "Press 3 to find a singer and print all information\n";
				cout << "Press 4 to print all information of Singers\n";
				cout << "Press 5 to delete everything !\n";
				cout << "Press 6 to add new Music \n";
				cout << "Press 7 to find a Music and print its information\n";
				cout << "Press 8 to find a word in the Music Text\n";
				cout << "Press 9 to see count of a word in the Music Text\n";
				cout << "Press 10 to delete a Music \n";
				cout << "Press 11 to build a PlayList \n";
				cout << "Press 12 to add a Music to PlayList \n";
				cout << "Press 13 to show All PlayLists information \n";
				cout << "Press 14 to find a PlayList and print its information \n";
				cout << "Press 15 to find a PlayList and prints Musics(Sorted by year) \n";
				cout << "Press 16 to find a Music in Playlist \n";
				cout << "Press 17 to delete a Music from Playlist \n";
				cout << "Press 18 to add a Playlist to Queue (Enqueue) \n";
				cout << "Press 19 to delete a Playlist from Queue (Dequeue) \n";
				cout << "Press 20 to see Elements in Queue \n";
				cout << "Press 21 to Exit\n";

				string n;
				cin >> n;
				if (n == "1") {
					cout << "Enter a name of the singer : ";
					string name;
					cin >> name;
					singers[count_singers] = new Singer(name);
					set.insert(singers[count_singers]);
					cout << "Singer successfully added !\n";
					puts("");
					++count_singers;
				}
				else if (n == "2") {
					string id;
					int del_id;
					cout << "Enter ID of singer that you want to delete : ";
					cin >> id;
					if (isInteger(id)) {
						del_id = toInteger(id);
						set.erase(singers, del_id);
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "3") {
					string id;
					int show_id = -1;
					cout << "Enter ID of singer that you want see information : ";
					cin >> id;
					if (isInteger(id)) {
						show_id = toInteger(id);
						set.find_singer_print_info(show_id);
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
					puts("");
				}
				else if (n == "4") {
					set.print_all_singers();
				}
				else if (n == "5") {
					set.clear();
					set_play.clear();
				}
				else if (n == "6") {
					string music_name;
					string s_year;
					int year = -1;
					string text_s;
					string artist;
					cout << "Enter a Music name : ";
					cin >> music_name;
					cout << "Enter a year of music : ";
					cin >> s_year;
					cin.ignore();
					if (isInteger(s_year)) {
						year = toInteger(s_year);
						string songLyrics = "";
						string word;
						bool firstWord = true;
						cout << "Enter Text of the Music (press Enter twice to finish):" << endl;
						while (true) {
							char c;
							string line = "";
							while (cin.get(c)) {
								if (c == '\n') {
									break;
								}
								line += c;
							}
							if (line.empty()) {
								break;
							}
							if (!songLyrics.empty()) {
								songLyrics += "\n";
							}
							songLyrics += line;
						}
						text_s = songLyrics;

						cout << "Enter the Artist_Name of the music : ";
						cin >> artist;
						Singer* si = set.find_singer_byname(singers, count_singers, artist);
						if (si != nullptr) {
							Song song(music_name, year, text_s);
							si->get_songs().push_back((song));
							cout << "Music successfully added (:\n\n";
						}
					}
					else {
						cout << "Error ! You must enter Integer number for year !\n\n";
					}
					
				}
				else if (n == "7") {
					string name_music;
					cout << "Enter a name of the Music : ";
					cin >> name_music;
					set.find_amusic_print(singers, count_singers, name_music);
				}
				else if (n == "8") {
					string idm, ids;
					int id_m, id_s;
					cout << "Enter ID of the Music : ";
					cin >> idm;
					cout << "Enter ID of the Singer : ";
					cin >> ids;
					string word;
					cout << "Enter a word that you want to search in this music : ";
					cin >> word;
					if (isInteger(idm) && isInteger(ids)) {
						id_m = toInteger(idm);
						id_s = toInteger(ids);
						set.find_patternIN_music(singers, count_singers, id_m, id_s, word);
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "9") {
					string idm, ids;
					int id_m, id_s;
					cout << "Enter ID of the Music : ";
					cin >> idm;
					cout << "Enter ID of the Singer : ";
					cin >> ids;
					string word;
					cout << "Enter a word that you want to search in this music : ";
					cin >> word;
					if (isInteger(idm) && isInteger(ids)) {
						id_m = toInteger(idm);
						id_s = toInteger(ids);
						set.count_word_INmusic(singers, count_singers, id_m, id_s, word);
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "10") {
					try {
						int id_music, id_singer;
						string idmusic, idsinger;
						cout << "Enter ID of Music : ";
						cin >> idmusic;
						cout << "Enter ID of Singer : ";
						cin >> idsinger;
						if (isInteger(idsinger) && isInteger(idmusic)) {
							id_singer = toInteger(idsinger);
							id_music = toInteger(idmusic);
							set.delete_music(singers, count_singers, id_music, id_singer);
							set_play.delete_musicFrom_ALLplay(playlists, count_playlists, id_music);
						}
						else {
							cout << "Error ! You must enter Integer number for ID !\n\n";
						}
					}
					catch (...) {
						cout << "Something has a problem!\n\n";
					}
				}
				else if (n == "11") {
					cout << "Enter a name of the PlayList : ";
					string name;
					cin >> name;
					playlists[count_playlists] = new PlayList(name);
					set_play.insert(playlists[count_playlists]);
					cout << "PlayList successfully added !\n";
					puts("");
					++count_playlists;
				}
				else if (n == "12") {
					int id_music, id_playlist;
					string idmusic, idplaylist;
					cout << "Enter ID of Music : ";
					cin >> idmusic;
					cout << "Enter ID of PlayList : ";
					cin >> idplaylist;
					if (isInteger(idplaylist) && isInteger(idmusic)) {
						id_playlist = toInteger(idplaylist);
						id_music = toInteger(idmusic);
						Song so = set.findAmusic_forAddtoPlaylist(singers, count_singers, id_music);
						PlayList* pl = set_play.find_playlist_byID(playlists, count_playlists, id_playlist);
						if (pl != nullptr && so.get_name() != "null") {
							if (!set_play.playL_Has_Music(playlists, id_playlist, id_music)) {
								pl->get_songs().push_back(so);
								cout << "Music successfully added (:\n\n";
							}
							else {
								cout << "This Music has added before !\n\n";
							}
						}
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "13") {
					set_play.print_all_playlists();
				}
				else if (n == "14") {
					int id_pl;
					string idpl;
					cout << "Enter ID of PlayList : ";
					cin >> idpl;
					if (isInteger(idpl)) {
						id_pl = toInteger(idpl);
						set_play.print_one_playlist(id_pl);
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "15") {
					int id_pl;
					string idpl;
					cout << "Enter ID of PlayList : ";
					cin >> idpl;
					if (isInteger(idpl)) {
						id_pl = toInteger(idpl);
						PlayList* pl = set_play.find_playlist_byID(playlists, count_playlists, id_pl);
						if (pl != nullptr) {
							set_play.find_playlist_print_info(id_pl);
						}
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "16") {
					int id_m;
					int id_pl;
					string idm, idp;
					cout << "Enter ID of music : ";
					cin >> idm;
					cout << "Enter ID of PlayList : ";
					cin >> idp;
					if (isInteger(idm) && isInteger(idp)) {
						id_m = toInteger(idm);
						id_pl = toInteger(idp);
						set_play.find_amusic_print_play(playlists, count_playlists, id_m, id_pl);
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "17") {
					int id_m;
					int id_pl;
					string idm, idp;
					cout << "Enter ID of music : ";
					cin >> idm;
					cout << "Enter ID of PlayList : ";
					cin >> idp;
					if (isInteger(idm) && isInteger(idp)) {
						id_m = toInteger(idm);
						id_pl = toInteger(idp);
						set_play.delete_musicFrom_play(playlists, count_playlists, id_m, id_pl);
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "18") {
					int id_pl;
					string idp;
					cout << "Enter ID of PlayList : ";
					cin >> idp;
					if (isInteger(idp)) {
						id_pl = toInteger(idp);
						PlayList *ky = set_play.find_playlist_return(playlists,count_playlists,id_pl);
						if (ky != nullptr) {
							if (!queue.find(*ky)) 
								queue.Push(*ky);
							else 
								cout << "This PlayList has added before!\n\n";
						}
						else
							cout << "PlayList does not exist\n\n";
					}
					else {
						cout << "Error ! You must enter Integer number for ID !\n\n";
					}
				}
				else if (n == "19") {
					try {
						queue.Pop();
					}
					catch (...) {
						cout << "Queue is Empty ! \n\n";
					}
				}

				else if (n == "20") {
					queue.Display();
					puts("");
				}

				else if (n == "21") {
					break;
				}
				else {
					cout << "Invalid input !\n\n";
				}
			}
		}
		else if (x == "2") {
			while (true) {
				string command, argument;
				int number, number1;
				cout << "Enter a command: ";
				cin >> command;
				if (command == "adds") {
					cin >> argument;
					singers[count_singers] = new Singer(argument);
					set.insert(singers[count_singers]);
					cout << "Singer successfully added !\n";
					puts("");
					++count_singers;
				}
				else if (command == "dels") {
					cin >> number;
					set.erase(singers, number);
				}
				else if (command == "find") {
					cin >> number;
					set.find_singer_print_info(number);
					puts("");
				}
				else if (command == "prints") {
					set.print_all_singers();
				}
				else if (command == "cls") {
					set.clear();
					set_play.clear();
				}
				else if (command == "findm") {
					cin >> argument;
					set.find_amusic_print(singers, count_singers, argument);
				}
				else if (command == "delm") {
					cin >> number;
					cin >> number1;
					try {
						set.delete_music(singers, count_singers, number1, number);
						set_play.delete_musicFrom_ALLplay(playlists, count_playlists, number1);
					}
					catch (...) {
						cout << "Something has problem!\n\n";
					}
				}
				else if (command == "addms") {
					string musicname;
					cin >> musicname;
					string singername;
					int musicy;
					cin >> musicy;
					cin.ignore();
					cout << "Enter Text of the Music (press Enter twice to finish):" << endl;
					string songLyrics = "";
					string word;
					bool firstWord = true;
					while (true) {
						char c;
						string line = "";
						while (cin.get(c)) {
							if (c == '\n') {
								break;
							}
							line += c;
						}

						if (line.empty()) {
							break;
						}

						if (!songLyrics.empty()) {
							songLyrics += "\n";
						}
						songLyrics += line;
					}
					argument = songLyrics;

					cin >> singername;
					Singer* si = set.find_singer_byname(singers, count_singers, singername);
					if (si != nullptr) {
						Song song(musicname, musicy, argument);
						si->get_songs().push_back((song));
						cout << "Music successfully added (:\n\n";
					}
				}
				else if (command == "search") {
					int id_m, id_s;
					cin >> id_s;
					cin >> id_m;
					string word;
					cin >> word;
					set.find_patternIN_music(singers, count_singers, id_m, id_s, word);
				}
				else if (command == "countw") {
					int id_m, id_s;
					cin >> id_s;
					cin >> id_m;
					string word;
					cin >> word;
					set.count_word_INmusic(singers, count_singers, id_m, id_s, word);
				}
				else if (command == "addp") {
					cin >> argument;
					playlists[count_playlists] = new PlayList(argument);
					set_play.insert(playlists[count_playlists]);
					cout << "PlayList successfully added !\n";
					puts("");
					++count_playlists;
				}
				else if (command == "addmp") {
					cin >> number;
					cin >> number1;
					Song so = set.findAmusic_forAddtoPlaylist(singers, count_singers, number);
					PlayList* pl = set_play.find_playlist_byID(playlists, count_playlists, number1);
					if (pl != nullptr && so.get_name() != "null") {
						if (!set_play.playL_Has_Music(playlists, number1, number)) {
							pl->get_songs().push_back(so);
							cout << "Music successfully added (:\n\n";
						}
						else {
							cout << "This Music has added before !\n\n";
						}
					}
				}
				else if (command == "searchp") {
					cin >> number;
					set_play.print_one_playlist(number);
				}
				else if (command == "searchm") {
					cin >> number;
					cin >> number1;
					set_play.find_amusic_print_play(playlists, count_playlists, number1, number);
				}
				else if (command == "delmp") {
					cin >> number;
					cin >> number1;
					set_play.delete_musicFrom_play(playlists, count_playlists, number1, number);
				}
				else if (command == "showp") {
					cin >> number;
					PlayList* pl = set_play.find_playlist_byID(playlists, count_playlists, number);
					if (pl != nullptr) {
						set_play.find_playlist_print_info(number);
					}
				}
				else if (command == "addqp") {
					cin >> number;
					PlayList* ky = set_play.find_playlist_return(playlists, count_playlists, number);
					if (ky != nullptr) {
						if (!queue.find(*ky))
							queue.Push(*ky);
						else
							cout << "This PlayList has added before!\n\n";
					}
					else
						cout << "PlayList does not exist\n\n";
				}
				else if (command == "pop") {
					try {
						queue.Pop();
					}
					catch (...) {
						cout << "Queue is Empty ! \n\n";
					}
				}
				else if (command == "showq") {
					queue.Display();
				}
				else if (command == "exit") {
					break;
				}
				else {
					cout << "Invalid Command ! \n\n";
				}
			}
		}
		else if (x == "3") {
			break;
		}
		else {
			cout << "Invalid input !\n\n";
		}
	}
}



bool isInteger(const string& s) {
	size_t start = 0;
	if (s[0] == '-' || s[0] == '+')
		start = 1;
	for (size_t i = start; i < s.length(); ++i) {
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}
int toInteger(const string& str) {
	int result = 0, sign = 1;
	int i = 0;

	if (str[0] == '-') {
		sign = -1;
		i++;
	}
	else if (str[0] == '+') {
		i++;
	}
	for (; i < str.size(); i++) {
		result = result * 10 + (str[i] - '0');
	}

	return sign * result;
}
