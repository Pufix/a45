#pragma once
#include "service.h"
#include<iostream>

void removeSpaces(string& str) {
	int n = str.length();
	for (int i = n-1; i > 0; i--)
		if (str[i] == ' ')
			str.erase(i, 1);
		else
			return;
}
class userInterface {
public:
	service serv;
	void login() {
		bool loggedIn = false;
		string username;
		cout << "username: ";
		getline(cin, username);
		removeSpaces(username);
		cout << "password: ";
		string password;
		getline(cin, password);
		removeSpaces(username);
		loggedIn = this->serv.Login(username, password);
		if (!loggedIn)
			cout << "Wrong username or password!" << endl;
		else
			cout << "Succesfully logged in as " << this->serv.GetUsername() << endl;
	}
	void regist() {
		string username;
		cout << "Please enter username: ";
		getline(cin, username);
		removeSpaces(username);
		string password;
		cout << "Please enter password: ";
		getline(cin, password);
		removeSpaces(password);
		string password2;
		cout << "Please re-enter password: ";
		getline(cin, password2);
		if (password == password2) {
			int result = this->serv.addUser(username, password);
			if (result != -1)
				cout << "Succesfully registered!" << endl;
			else
				cout << "Username already taken!" << endl;
		}
		else
			cout << "Passwords don't match!" << endl;
	}
	void startUp() {
		do {
			cout << "If you already have an account type 'login' otherwise type 'register'." << endl;
			string command;
			getline(cin, command);
			removeSpaces(command);
			if (command == "login")
				this->login();
			else if (command == "register")
				this->regist();
			else
				cout << "Invalid command!" << endl;
			cout << endl << endl;
		} while (this->serv.currentUser.privilegeLevel == -1);
	}
	int commandRecognition(string command) {
		if (command == "exit"||command == "quit")
			return 0;
		if(strstr(command.c_str(), "add") == command.c_str())
			return 1;
		if(strstr(command.c_str(), "delete") == command.c_str())
			return 2;
		if(strstr(command.c_str(), "update") == command.c_str())
			return 3;
		if(strstr(command.c_str(), "list") == command.c_str())
			return 4;
		if(strstr(command.c_str(), "filter") == command.c_str())
			return 5;
		if (command == "help")
			return 6;
		return -1;
	}
	void addCommand(string command){
		//cout << "add <user> <username> <password>" << endl;
		command.erase(command.begin(), command.begin() + 3);
		if (command == "") {
			cout << "add <user> <username> <password>" << endl;
			return;
		}
		command.erase(command.begin(), command.begin()+1);
		string username;
		username = command;
		for (int i=0;i<=username.size();i++)
			if (i == username.size()) {
				cout << "Error: Invalid command!" << endl;
				return;
			}
			else if (username[i] == ' ') {
				username.erase(username.begin()+i, username.end());
				command.erase(command.begin(), command.begin() + i);
				break;
			}
		string password;
		password = command;
		while(!password.empty()&&password[0]==' ')
			password.erase(password.begin());
		if (username == "" || password == "") {
			cout << "Error: Invalid command!" << endl;
			return;
		}
		int result = this->serv.addUser(username,password);
		if (result == -1)
			cout << "Error: Username already exists!" << endl;
		else
			cout << "Succesfully added user " << username << endl;
	}
	void deleteCommand(){}
	void updateCommand(){}
	void listCommand(){}
	void filterCommand(){}
	void helpScreenAdmin() {
		cout << "add <user> <username> <password>" << endl;
		cout << "add <movie> <title> <year> <genre> <likes> <trailerLink>" << endl;
		cout << "delete <user> <username>"<<endl;
		cout << "delete <movie> <title>"<<endl;
		cout << "list <users/movies>" << endl;
	}
	void helpScreenUser(){}
	bool run() {
		string command;
		getline(cin, command);
		removeSpaces(command);
		int action = commandRecognition(command);
		switch (action) {
		case 0:
			return false;
		case 1:
			this->addCommand(command);
			break;
		case 2:	
			this->deleteCommand();
			break;
		case 3:
			this->updateCommand();
			break;
		case 4:
			this->listCommand();
			break;
		case 6:
			if (serv.currentUser.privilegeLevel==0)
				this->helpScreenAdmin();
			else
				this->helpScreenUser();
			break;
		default:
			cout << "Error: Invalid command!\n";
			break;
		}
		return true;
	}
};