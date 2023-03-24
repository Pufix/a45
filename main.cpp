#include<iostream>
#include<string>
#include "service.h"
using namespace std;
void login() {
	string username;
	cout<<"username: ";
	getline(cin,username);
	cout << "password: ";
	string password;
	getline(cin,password);
}
int main() {
	login();
	return 0;
}