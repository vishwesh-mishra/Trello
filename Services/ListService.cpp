#include "ListService.h"

void ListService::createList(List* l) {
	this->listTable[l->id] = l;
	cout << "Created list: " << l->id << endl;
	this->listId++;
}

void ListService::deleteList(int listId, CardService* cardService) {
	vector<int> cards = listTable[listId]->cards;
	for (int i = 0;i < cards.size();i++) cardService->deleteCard(cards[i]);
	this->listTable.erase(listId);
}

void ListService::createCardAndInList(Card* c, CardService* cardService) {
	this->listTable[c->listId]->cards.push_back(c->id);
	cardService->createCard(c);
}

void ListService::deleteCardAndFromList(int cId, CardService* cardService) {
	int listId = cardService->cardTable[cId]->listId;
	for (int i = 0;i < listTable[listId]->cards.size();i++) {
		if (listTable[listId]->cards[i] == cId) {
			listTable[listId]->cards.erase(listTable[listId]->cards.begin() + i);
			break;
		}
	}
	cardService->deleteCard(cId);
}

void ListService::moveCard(int cId, int fromListId, int toListId, CardService* cardService) {
	for (int i = 0;i < listTable[fromListId]->cards.size();i++) {
		if (listTable[fromListId]->cards[i] == cId) {
			listTable[fromListId]->cards.erase(listTable[fromListId]->cards.begin() + i);
			break;
		}
	}
	listTable[toListId]->cards.push_back(cId);
	cardService->cardTable[cId]->listId = toListId;
}

void ListService::modifyAttribute(int listId, string attribute, string value) {
	this->listTable[listId]->name = value;
}

void ListService::showList(int listId) {
	if (listTable.find(listId) == listTable.end()) cout << "List with id " << listId << " doesn't exist" << endl;
	else {
		List* l = this->listTable[listId];
		cout << "List Details: {id: " << l->id << ", name: " << l->name << ", boardId: "<<l->bId<<", cards: [";
		for (int i = 0;i < (l->cards).size();i++) {
			cout << "{" << l->cards[i] << "}, ";
		}
		cout << "]}" << endl;
	}
	cout << endl;
}

