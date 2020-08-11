#include "BoardService.h"

void BoardService::createBoard(Board* b) {
	boardTable[b->id] = b;
	cout << "Created board: " << b->id << endl;
	this->bId++;
}

void BoardService::deleteBoard(int bId, ListService* listService, CardService* cardService) {
	vector<int> lists = boardTable[bId]->lists;
	for (int i = 0;i < lists.size();i++) listService->deleteList(lists[i], cardService);
	boardTable.erase(bId);
}

void BoardService::createListAndInBoard(List* l, ListService* listService) {
	boardTable[l->bId]->lists.push_back(l->id);
	listService->createList(l);
}

void BoardService::deleteListAndFromBoard(int listId, ListService* listService, CardService* cardService) {
	int bId = listService->listTable[listId]->bId;
	for (int i = 0;i < boardTable[bId]->lists.size();i++) {
		if (boardTable[bId]->lists[i] == listId) {
			boardTable[bId]->lists.erase(boardTable[bId]->lists.begin() + i);
			break;
		}
	}
	listService->deleteList(listId, cardService);
}

void BoardService::addMember(int bId, string userId) {
	boardTable[bId]->members[userId] = true;
}

void BoardService::removeMember(int bId, string userId) {
	boardTable[bId]->members.erase(userId);
}

void BoardService::modifyAttribute(int bId, string attribute, string value) {
	if(attribute=="name") boardTable[bId]->name = value;
	else if(attribute=="privacy") boardTable[bId]->privacy = value;
}

void BoardService::showBoard(int bId) {
	if (boardTable.find(bId) == boardTable.end()) cout << "Board with id " << bId << " doesn't exist" << endl;
	else {
		Board* b = boardTable[bId];
		map<string, bool>::iterator it;
		cout << "Board Details: {id: " << b->id << ", name: " << b->name << ", privacy: " << b->privacy << ", url: " << b->url <<
			", members: [";
		for (it = b->members.begin();it != b->members.end();it++) {
			cout << "{" << it->first << "}, ";
		}
		cout<<"], lists: [";
		for (int i = 0;i < (b->lists).size();i++) {
			cout << "{" << b->lists[i] << "}, ";
		}
		cout << "]}" << endl;
	}
}

void BoardService::showAllBoards() {
	if (boardTable.size() == 0) cout << "No boards" << endl;
	else {
		map<int, Board*>::iterator it;
		cout << "[";
		for (it = boardTable.begin();it != boardTable.end();it++) {
			cout << "{" << endl;
			showBoard(it->first);
			cout << "}, ";
		}
		cout << "]" << endl;
	}
	cout << endl;
}