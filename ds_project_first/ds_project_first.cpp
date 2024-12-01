#include <iostream>
#include"LinkList.h"
#include"Singer.h"
#include"Song.h"
#include"SparseSet.h"
using namespace std;

int main()
{
	SparseSet set(100, 100);


	while (true)
	{
		cout << "press 1 to add singer\n";
		cout << "press 2 to delete singer\n";
		cout << "press 3 to find a singer and print all information\n";
		cout << "press 4 to print all information of singers\n";
		cout << "press 5 to delete everything !\n";
		cout << "press 50 to exit\n";
		int n = 0;
		cin >> n;
		if (n == 1) {
			cout << "Enter name of the singer : ";
			string name;
			cin >> name;
			Singer singer1(name);
			set.insert(singer1);
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
		}
		else if (n == 4) {
			set.print_all_singers();
		}
		else if (n == 5) {
			set.clear();
		}
		else if (n == 50) {
			break;
		}
	}
}

