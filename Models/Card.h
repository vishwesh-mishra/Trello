#pragma once
#include<string>

using namespace std;

class Card {
public:
	int id, listId;
	string name, description, assignedUser;
	Card(int id, int listId, string name, string description, string assignedUser) {
		this->id = id;
		this->listId = listId;
		this->name = name;
		this->description = description;
		this->assignedUser = assignedUser;
	}
};
