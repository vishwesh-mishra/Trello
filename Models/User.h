#pragma once
#include<string>

using namespace std;

class User {
public:
	string userId, name, email;
	User(string userId, string name, string email) {
		this->userId = userId;
		this->name = name;
		this->email = email;
	}
};
