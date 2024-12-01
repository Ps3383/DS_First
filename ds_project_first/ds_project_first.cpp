#include <iostream>
#include"LinkList.h"
#include"Singer.h"
#include"Song.h"
#include"SparseSet.h"
using namespace std;

int main()
{
	SparseSet set(100, 100);

	cout << "press 1 to add singer\n";
	cout << "press 2 to delete singer\n";
	cout << "press 2 to add singer\n";
	cout << "press 3 to add singer\n";
	cout << "press 4 to add singer\n";
	cout << "press 5 to add singer\n";

	int n = 0;
	cin >> n;
	if (n == 1) {
		cout << "Enetr name of the singer\n";
		string name;
		cin >> name;
		Singer singer1(name);
		set.insert(singer1);
	}
	else if (n == 2) {
		int del_id = -1;
		cout << "Enter id of singer that you want to delete\n";
		cin >> del_id;
		set.erase(del_id);
	}
	else if (n == 3) {

	}
	else if (n == 3) {

	}
	else if (n == 3) {

	}
	else if (n == 3) {

	}
}

