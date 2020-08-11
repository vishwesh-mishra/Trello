#include "CardService.h"

void CardService::createCard(Card* c) {
	cardTable[c->id] = c;
	cout << "Created card: " << c->id << endl;
	this->cId++;
}

void CardService::deleteCard(int cId) {
	cardTable.erase(cId);
}

void CardService::assignCard(int cId, string email) {
	cardTable[cId]->assignedUser = email;
}

void CardService::unassignCard(int cId) {
	cardTable[cId]->assignedUser = "";
}

void CardService::modifyAttribute(int cId, string attribute, string value) {
	if (attribute == "name") cardTable[cId]->name = value;
	else if (attribute == "description") cardTable[cId]->description = value;
}

void CardService::showCard(int cId) {
	if (cardTable.find(cId) == cardTable.end()) cout << "Card with id " << cId << " doesn't exist" << endl; 
	else {
		Card* c = cardTable[cId];
		cout << "Card Details: {id: " << c->id << ", name: " << c->name << ", description: " << c->description
			<< ", assignedTo: " << c->assignedUser << ", listId: " << c->listId << "}" << endl;
	}
	cout << endl;
}

