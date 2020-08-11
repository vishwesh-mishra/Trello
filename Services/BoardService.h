#pragma once
#include<iostream>
#include<map>
#include "../Models/Board.h"
#include "ListService.h"
#include "CardService.h"

class BoardService {
public:
	int bId;
	BoardService() {
		this->bId = 1;
	}
	map<int, Board*> boardTable; // key will be board id
	void createBoard(Board* b);
	void deleteBoard(int bId, ListService* listService, CardService *cardService);
	void createListAndInBoard(List* l, ListService* listService);
	void deleteListAndFromBoard(int listId, ListService* listService, CardService* cardService);
	void addMember(int bId, string userId);
	void removeMember(int bId, string userId);
	void modifyAttribute(int bId, string attribute, string value);
	void showBoard(int bId);
	void showAllBoards();
};

