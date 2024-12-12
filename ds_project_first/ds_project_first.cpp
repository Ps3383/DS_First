#include <iostream>
#include"LinkList.h"
#include"Singer.h"
#include"Song.h"
#include"PlayList.h"
#include"SparseSet.h"
#include"myQueue.h"
using namespace std;

int main()
{
	SparseSet<Singer> set(100, 100);  // max id    capa
	SparseSet<PlayList> set_play(2000, 2000);
	myQueue<PlayList> queue(100);    // capa
	
	Singer* singers[100];
	PlayList* playlists[100];
	int count_singers = 0;
	int count_playlists = 0;

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
		cout << "Press 9 to build a PlayList \n";
		cout << "Press 10 to add a Music to PlayList \n";
		cout << "Press 11 to show All PlayLists information \n";
		cout << "Press 12 to find a PlayList and print its information \n";
		cout << "Press 13 to find a Music in Playlist \n";
		cout << "Press 14 to delete a Music from Playlist \n";
		cout << "Press 15 to add a Playlist to Queue (Enqueue) \n";
		cout << "Press 16 to delete a Playlist from Queue (Dequeue) \n";
		cout << "Press 17 to see Elements in Queue \n";

		cout << "Press 50 to exit\n";

		int n = 0;
		cin >> n;
		if (n == 1) {
			cout << "Enter name of the singer : ";
			string name;
			cin >> name;
			singers[count_singers] = new Singer(name);
			set.insert(singers[count_singers]);
			cout << "Singer successfully added !\n";
			puts("");
			++count_singers;
		}
		else if (n == 2) {
			int del_id = -1;
			cout << "Enter ID of singer that you want to delete : ";
			cin >> del_id;
			/*try {*/
				set.erase(singers, del_id);
			/*}*/
	/*		catch (...) {
				cout << "ridid\n\n\n";
			}*/
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
			set_play.clear();
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
				cout << "Enter ID of Music : ";
				cin >> id_music;
				cout << "Enter ID of Singer : ";
				cin >> id_singer;
				set.delete_music(singers, count_singers, id_music, id_singer);	
				set_play.delete_musicFrom_ALLplay(playlists, count_playlists, id_music);
			}
			catch (...) {
				cout << "Something has problem!\n\n";
			}
		}
		else if (n == 9) {
			cout << "Enter name of the PlayList : ";
			string name;
			cin >> name;
			playlists[count_playlists] = new PlayList(name);
			set_play.insert(playlists[count_playlists]);
			cout << "PlayList successfully added !\n";
			puts("");
			++count_playlists;
		}
		else if (n == 10) {
			int id_music;
			int id_playlist;
			cout << "Enter ID of music : ";
			cin >> id_music;
			cout << "Enter ID of PlayList : ";
			cin >> id_playlist;
			Song so = set.findAmusic_forAddtoPlaylist(singers, count_singers, id_music);
			PlayList* pl = set_play.find_playlist_byID(playlists, count_playlists, id_playlist);
			if (pl != nullptr && so.get_name()!= "null") {
				pl->get_songs().push_back(so);
				cout << "Song successfully added (:\n\n";
			}
		}
		else if (n == 11) {
			set_play.print_all_playlists();
		}
		else if (n == 12) {
			int id_pl;
			cout << "Enter ID of PlayList : ";
			cin >> id_pl;
			PlayList* pl = set_play.find_playlist_byID(playlists, count_playlists, id_pl);
			if (pl != nullptr) {
				set_play.find_playlist_print_info(id_pl);
			}
		}
		else if (n == 13) {
			int id_m;
			int id_pl;
			cout << "Enter ID of music : ";
			cin >> id_m;
			cout << "Enter ID of PlayList : ";
			cin >> id_pl;
			set_play.find_amusic_print_play(playlists, count_playlists, id_m ,id_pl);
		}
		else if (n == 14) {
			int id_m;
			int id_pl;
			cout << "Enter ID of music : ";
			cin >> id_m;
			cout << "Enter ID of PlayList : ";
			cin >> id_pl;
			set_play.delete_musicFrom_play(playlists, count_playlists, id_m, id_pl);
		}
		else if (n == 15) {
			int id_pl;
			cout << "Enter ID of PlayList : ";
			cin >> id_pl;
			PlayList ky = set_play.find_playlist_return(id_pl);
			queue.Push(ky);
			cout << "";
		}

		else if (n == 16) {
			try {
				queue.Pop();
			}
			catch (...) {
				cout << "Queue is Empty ! \n\n";
			}		
		}

		else if (n == 17) {
			queue.Display();
		}

		else if (n == 50) {
			break;
		}
	}
}

