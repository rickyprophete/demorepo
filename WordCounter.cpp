#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

typedef std::map<std::string, int> StrIntMap;

std::vector <std::string> validwords
{ "JAVA","C++","GIT","GITHUB","GIT/GITHUB","JAVASCRIPT","C#","C",
"PYTHON","SQL","JQUERY", "EXCEL","GO","ALGORITHMS","FLEXIBLE","R","DATA",
"LEARNING","MACHINE","DEVOPS","4","2","CSS","SWIFT","HTML" };	// words to be added to the map

bool validWord(std::string s) {
	for (auto& x : validwords) {
		if (s == x) return true;
	}
	return false;
}

void countWords(std::istream& in, StrIntMap& words) {
	std::string s;
	while (in >> s) {
		char* str = new char[s.length() + 1];
		strcpy(str, s.c_str());

		for (int i = 0; i < s.length(); i++)
			str[i] = toupper(str[i]);

		char delim[] = " -,.:;/&(){}[]";
		char* ptr = strtok(str, delim);

		while (ptr != NULL) {
			if (validWord(ptr))
				++words[ptr];

			ptr = strtok(NULL, delim);
		}
	}
}

bool sortHighToLow(const std::pair<std::string, int>& a,const std::pair<std::string, int>& b)	// utility comparator function to pass to the sort() module
{
	return (a.second > b.second);
}

void display(std::vector< std::pair<std::string, int> >& v) {
	for (auto& x : v)
		std::cout << x.first << "\t" << x.second << std::endl;
}

int main() {
	std::string filename{ "jobs.csv" };	// file where raw data is pulled from
	std::ifstream fin;
	fin.open(filename);

	StrIntMap wordlist;		// map where words and their counts are stored 
	countWords(fin, wordlist);

	std::vector< std::pair<std::string, int> > vec;	// create a empty vector of pairs

	StrIntMap::iterator iterator;	// copy key-value pairs from the map to the vector

	for (iterator = wordlist.begin(); iterator != wordlist.end(); iterator++)	
		vec.push_back(make_pair(iterator->first, iterator->second));	// fill vec with pairs of str & int

	std::sort(vec.begin(), vec.end(), sortHighToLow);// sort the vector high to low using pair's second value

	display(vec);	// print the vector
}