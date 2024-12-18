﻿#pragma once
#include<iostream>
using namespace std;

class Song
{
private:
	string Name;
	int ID;
	int Year;
	string Text;
	int* suffixArray;
	int n;   //text_size
	static int number_so;
	void buildSuffixArray();   
	void quickSort(int left, int right); 
	int compareSuffix(int i, int j);  
	int binarySearch(string pattern) const;
public:
	Song(string name = "", int year = -1, string text = "" );
	int get_year();
	int get_id();
	string get_text();
	string get_name();
	int find_pattern(const string& pattern);
	int count_pattern(const string& pattern);
	bool compareSuffix(int i, const string& pattern);
	friend ostream& operator<<(ostream& os, const Song& song);
};

