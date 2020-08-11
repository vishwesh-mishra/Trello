#pragma once
#include<iostream>
#include<map>
#include "../Models/List.h"
#include "CardService.h"

class ListService {
public:
	int listId;
	ListService() {
		this->listId = 1;
	}
	map<int, List*> listTable; // key will be list id
	void createList(List* l);
	void deleteList(int listId, CardService* cardService);
	void createCardAndInList(Card* c, CardService* cardService);
	void deleteCardAndFromList(int cId, CardService* cardService);
	void moveCard(int cId, int fromListId, int toListId, CardService* cardService);
	void modifyAttribute(int listId, string attribute, string value);
	void showList(int listId);
};

