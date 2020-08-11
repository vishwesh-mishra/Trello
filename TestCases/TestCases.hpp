#include "../Services/UserService.h"
#include "../Services/BoardService.h"
#include "../Services/ListService.h"
#include "../Services/CardService.h"

class TestCases {
public:
	void tc1();
	void tc2();
};

void TestCases::tc1() {
	UserService* userService = new UserService();
	userService->addUser(new User("u1", "Vishwesh", "vishwesh@trello.com"));

	BoardService* boardService = new BoardService();
	boardService->createBoard(new Board(boardService->bId, "Board1", "PUBLIC", "board/" + to_string(boardService->bId), {}, {}));
	boardService->showBoard(1);

	ListService* listService = new ListService();
	boardService->createListAndInBoard(new List(listService->listId, 1, "List1", {}), listService);
	listService->showList(1);
	boardService->showBoard(1);

	CardService* cardService = new CardService();
	listService->createCardAndInList(new Card(cardService->cId, 1, "Card1", "Card1 Description", ""), cardService);
	cardService->showCard(1);
	listService->showList(1);

	listService->createCardAndInList(new Card(cardService->cId, 1, "Card2", "Card2 Description", ""), cardService);
	cardService->showCard(2);
	listService->showList(1);

	listService->deleteCardAndFromList(1, cardService);
	cardService->showCard(1);
	listService->showList(1);
	cardService->showCard(2);

	/*listService->deleteList(1, cardService);
	listService->showList(1);
	cardService->showCard(1);
	cardService->showCard(2);*/

	listService->createCardAndInList(new Card(cardService->cId, 1, "Card3", "Card3 Description", ""), cardService);
	listService->showList(1);

	boardService->createListAndInBoard(new List(listService->listId, 1, "List2", {}), listService);
	boardService->showBoard(1);
	listService->moveCard(3, cardService->cardTable[3]->listId, 2, cardService);
	listService->showList(1);
	listService->showList(2);

	boardService->deleteBoard(1, listService, cardService);
	boardService->showBoard(1);
	listService->showList(1);
	listService->showList(2);
	cardService->showCard(1);
	cardService->showCard(2);
	cardService->showCard(3);
}

void TestCases::tc2() {
	UserService* userService = new UserService();
	userService->addUser(new User("user1", "Gaurav Chandak", "gaurav@workat.tech"));
	userService->addUser(new User("user2", "Demo", "demo@workat.tech"));
	userService->addUser(new User("user3", "Sagar Jain", "sagar@workat.tech"));

	BoardService* boardService = new BoardService();
	ListService* listService = new ListService();
	CardService* cardService = new CardService();

	cout << "1." << endl;
	boardService->showAllBoards();

	cout << "2." << endl;
	boardService->createBoard(new Board(boardService->bId, "work@tech", "PUBLIC", "board/" + to_string(boardService->bId), {}, {}));

	cout << "3." << endl;
	boardService->showBoard(1);

	cout << "4." << endl;
	boardService->showAllBoards();

	cout << "5." << endl;
	boardService->modifyAttribute(1, "name", "worat.tech");
	boardService->modifyAttribute(1, "privacy", "PRIVATE");
	boardService->showBoard(1);

	cout << "6." << endl;
	boardService->createBoard(new Board(boardService->bId, "workat", "PUBLIC", "board/" + to_string(boardService->bId), {}, {}));

	cout << "7." << endl;
	boardService->showAllBoards();

	cout << "8." << endl;
	boardService->addMember(1, "user1");
	boardService->addMember(1, "user2");
	boardService->addMember(1, "user3");
	boardService->removeMember(1, "user2");
	boardService->showBoard(1);

	cout << "9." << endl;
	boardService->deleteBoard(2, listService, cardService);
	boardService->showBoard(2);

	cout << "10." << endl;
	boardService->showAllBoards();

	cout << "11." << endl;
	boardService->createListAndInBoard(new List(listService->listId, 1, "Mock Interviews", {}), listService);

	cout << "12." << endl;
	listService->showList(1);

	cout << "13." << endl;
	listService->modifyAttribute(1, "name", "Mock Interviews - Applied");
	listService->showList(1);

	cout << "14." << endl;
	boardService->createListAndInBoard(new List(listService->listId, 1, "Mock Interviews - Scheduled", {}), listService);

	cout << "15." << endl;
	boardService->showBoard(1);

	cout << "16. " << endl;
	listService->createCardAndInList(new Card(cardService->cId, 1, "abcd@gmail.com", "Card1 Description", ""), cardService);

	cout << "17. " << endl;
	listService->createCardAndInList(new Card(cardService->cId, 1, "abcda@gmail.com", "Card2 Description", ""), cardService);

	cout << "18. " << endl;
	listService->showList(1);

	cout << "19. " << endl;
	cardService->modifyAttribute(2, "name", "abcde@gmail.com");
	cardService->modifyAttribute(2, "description", "At 7PM");
	listService->showList(1);

	cout << "20. " << endl;
	cardService->assignCard(1, "gaurav@workat.tech");
	cardService->showCard(1);

	cout << "21. " << endl;
	listService->moveCard(1, cardService->cardTable[1]->listId, 2, cardService);
	listService->showList(1);

	cout << "22. " << endl;
	listService->showList(2);

	cout << "23. " << endl;
	cardService->unassignCard(1);
	cardService->showCard(1);
}