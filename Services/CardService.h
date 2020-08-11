#pragma once
#include<iostream>
#include<map>
#include "../Models/Card.h"

class CardService {
public:
	int cId;
	CardService() {
		this->cId = 1;
	}
	map<int, Card*> cardTable; // key will be card id
	void createCard(Card* c);
	void deleteCard(int cId);
	void assignCard(int cId, string email);
	void unassignCard(int cId);
	void modifyAttribute(int cId, string attribute, string value);
	void showCard(int cId);
};
