#pragma once
#include <string>
using namespace std;
template <class Type>
class dynamicVector{
public:
	dynamicVector();
	void append(Type);
	Type operator[](int index);
	int getSize();
	void remove(int position);
};
class movie{
public:
	movie();
	movie(string title, string genre, int year, int likes, string trailer);
	void edit(string field, int value);
	void edit(string field, string value);
	bool operator==(const movie a);
};
class user{
public:
	string username;
	int privilegeLevel;
	user(string usrname, string pasword);
	bool checkPassword(std::string pasword);
	void addMovie(movie movie);
	void removeMovie(movie movie);
	dynamicVector<movie>getWatchlist();
};