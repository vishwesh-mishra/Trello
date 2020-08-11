#pragma once
#include<string>
#include<vector>

using namespace std;

class List {
public:
	int id, bId;
	string name;
	vector<int> cards;
	List(int id, int bId, string name, vector<int> cards) {
		this->id = id;
		this->bId = bId;
		this->name = name;
		this->cards = cards;
	}
};
