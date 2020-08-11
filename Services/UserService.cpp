#include "UserService.h"

void UserService::addUser(User* u) {
	userTable[u->userId] = u;
}

