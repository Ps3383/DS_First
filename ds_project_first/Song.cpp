﻿#include "Song.h"

int Song:: number_so = 0;

string customSubstr(string str, int pos, int len);

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
	n = text.size();
    suffixArray = new int[n];
    buildSuffixArray();
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

int Song::compareSuffix(int i, int j) {
    while (i<n && j<n) {
        if (Text[i]<Text[j])
            return -1;
        if (Text[i] > Text[j])
            return 1;
        i++;
        j++;
    }
    return (j==n) - (i==n);
}

void Song::quickSort(int left, int right) {
    if (left >=right) 
        return;
    int pivotIndex =left;
    int pivotValue =suffixArray[pivotIndex];
    int i = left+1;
    int j =right;

    while (i <= j) {
        while (i <=j && compareSuffix(suffixArray[i],pivotValue)< 0)
            i++;
        while (i <=j && compareSuffix(suffixArray[j],pivotValue)> 0)
            j--;

        if (i <=j) {
            swap(suffixArray[i],suffixArray[j]);
            i++;
            j--;
        }
    }
    swap(suffixArray[left], suffixArray[j]);

    quickSort(left, j-1);
    quickSort(j+1,right);
}

void Song::buildSuffixArray() {
    for (int i =0; i <n; i++) {
        suffixArray[i] = i;
    }
    quickSort(0, n-1); 
}

int Song::binarySearch(string pattern) const {
    int m = pattern.size();
    int low = 0,high =n-1;

    while (low <= high) {
        int mid = (low + high)/2;
        int start = suffixArray[mid];
        string suffix = customSubstr(Text, start, m);

        if (suffix==pattern) {
            return start;
        }
        else if (suffix < pattern) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}

int Song::find_pattern(const string& pattern) {
    return binarySearch(pattern);
}

bool Song::compareSuffix(int i, const string& pattern) {
    int m = pattern.size();

    if (suffixArray[i] + m > n) {
        return false;
    }
    if (customSubstr(Text,suffixArray[i], m) ==pattern)
        return true;
    else 
        return false;
}

int Song::count_pattern(const string& pattern) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (compareSuffix(i, pattern)) {
            count++;
        }
    }
    return count;
}


ostream& operator<<(ostream& os, const Song& song) {
    os << "Music [ID: " << song.ID << ", Name: " << song.Name << ", Year: " << song.Year << ", Text: " << song.Text << "]";
    return os;
}



string customSubstr(string str, int pos, int len) {
    if (pos >= str.size()) {
        return "";
    }
    if (pos + len > str.size()) {
        len = str.size() - pos;
    }
    string result;
    for (int i = pos; i < pos + len; ++i) {
        result += str[i];
    }
    return result;
}