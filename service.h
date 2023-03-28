#pragma once
#include "repository.h"
using namespace std;

class service {
private:
public:
	repository repo;
	user currentUser;
	bool Login(string userName, string password) {
		for (int i = 0; i < this->repo.getAllUsers().getSize(); i++)
			if (this->repo.getAllUsers()[i].checkPassword(password)) {
				this->currentUser = this->repo.getAllUsers()[i];
				return true;
			}
		return false;
	}
	service() {
		this->currentUser.privilegeLevel = -1;
	}
	string GetUsername() {
		if (this->currentUser.privilegeLevel == -1)
			return "Not logged in!";
		return this->currentUser.username;
	}
	user searchUser(string username) {
		int n = this->repo.counterUsers();
		for (int i = 0; i < n; i++)
			if (this->repo.getUser(i).username == username)
				return this->repo.getUser(i);
		return user();
	}
	int addUser(string username, string password) {
		if (this->searchUser(username) == user()) {
			user newuser;
			newuser.username = username;
			newuser.setPassword(password);
			newuser.uuid = generateUUID();
			newuser.privilegeLevel = 1;
			this->repo.addUser(newuser);
			return 0;
		}
		return -1;
	}
};