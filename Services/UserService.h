#pragma once
#include<map>
#include "../Models/User.h"

class UserService {
public:
	map<string, User*> userTable; // key will be userId
	void addUser(User* u);
};