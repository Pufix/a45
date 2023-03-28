#pragma once
#include<string>
#include<typeinfo>
#include<fstream>
#include<iostream>
#include<random>
using namespace std;
template <class Type>
class dynamicVector {
private:
	int size;
	int capacity;
	Type* elements;
public:
	void append(Type element) {
		if (this->size == this->capacity) {
			this->capacity *= 2;
			Type* newElements = new Type[capacity];
			for (int i = 0; i < this->size; i++)
				newElements[i] = this->elements[i];
			delete(this->elements);
			this->elements = newElements;
		}
		this->elements[size] = element;
		this->size++;
	}
	int getSize() {
		return this->size;
	}
	void remove(int position) {
		for (int i = position; i < this->size - 1; i++) {
			this->elements[i] = this->elements[i + 1];
		}
		this->size--;
		if (this->size == this->capacity / 4) {
			this->capacity /= 2;
			Type* newElements = new Type[this->capacity];
			for (int i = 0; i < size; i++)
				newElements[i] = this->elements[i];
			delete(this->elements);
			this->elements = newElements;
		}
	}
	Type operator[](int index) {
		return this->elements[index];
	}
	dynamicVector() {
		this->size = 0;
		this->capacity = 10;
		this->elements = new  Type[10];
	}
};
class movie {
public:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
	string uuid;
	friend ofstream& operator<< (ofstream& file, movie& movie) {
		file << movie.title << endl;
		file << movie.genre << endl;
		file << movie.year << endl;
		file << movie.likes << endl;
		file << movie.trailer << endl;
		return file;
	}
	friend ifstream& operator>> (ifstream& file, movie& movie) {
		file >> movie.title;
		file >> movie.genre;
		file >> movie.year;
		file >> movie.likes;
		file >> movie.trailer;
		return file;
	}
	friend iostream& operator<< (iostream& file, movie& movie) {
		file << "Title: " << movie.title << endl;
		file << "Genre: " << movie.genre << endl;
		file << "Year: " << movie.year << endl;
		file << "Likes: " << movie.likes << endl;
		return file;
	}
	movie() {
		this->title = "";
		this->genre = "";
		this->trailer = "";
		this->likes = 0;
		this->year = 0;
	}
	movie(string title, string genre, int year, int likes, string trailer) {
		this->title = title;
		this->genre = genre;
		this->year = year;
		this->likes = likes;
		this->trailer = trailer;
	}
	void edit(string field, int value) {
		if (field == "year")
			this->year = value;
		if (field == "likes")
			this->likes = value;
	}
	void edit(string field, string value) {
		if (field == "title")
			this->title = value;
		if (field == "genre")
			this->genre = value;
		if (field == "trailer")
			this->trailer = value;
	}
	bool operator==(const movie a) {
		return a.title == this->title;
	}

	bool operator!=(const movie a) {
		return a.title != this->title;
	}
};
class user {
private:
	std::string password;
public:
	dynamicVector<string> watchlist;
	string uuid;
	string username;
	int privilegeLevel=-1;
	friend ofstream& operator<< (ofstream& file, user& user) {
		file << user.uuid << endl;
		file << user.username << endl;
		file << user.password << endl;
		file << user.privilegeLevel << endl;
		file << user.watchlist.getSize() << endl;
		for (int i = 0; i < user.watchlist.getSize(); i++) {
			file << user.watchlist[i] << endl;
		}
		return file;
	}
	friend ifstream& operator>> (ifstream& file, user& user) {
		file >> user.uuid;
		file >> user.username;
		file >> user.password;
		file >> user.privilegeLevel;
		int size;
		file >> size;
		for (int i = 0; i < size; i++) {
			string uuid;
			file >> uuid;
			user.watchlist.append(uuid);
		}
		return file;
	}
	friend iostream& operator<< (iostream& file, user& user) {
		file << "Username: " << user.username << endl;
		file << "Password: " << user.password << endl;
		file << "Privilege level: " << user.privilegeLevel << endl;
		return file;
	}
	user() {}
	void setPassword(string password) {
		this->password = password;
	}
	user(std::string usrname, std::string pasword) {
		this->username = usrname;
		this->password = pasword;
	}
	bool checkPassword(std::string pasword) {
		return pasword == this->password;
	}
	void addMovie(movie movie) {
		this->watchlist.append(movie.uuid);
	}
	void removeMovie(movie movie) {
		for (int i = 0; i < this->watchlist.getSize(); i++) {
			if (this->watchlist[i] == movie.uuid) {
				this->watchlist.remove(i);
				return;
			}
		}
	}
	dynamicVector<string>getWatchlist() {
		return this->watchlist;
	}
	bool operator==(const user user) {
		return user.uuid == this->uuid;
	}
};
string generateUUID() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);
	string uuid = "";
	for (int i = 0; i < 10; i++) {
		uuid += to_string(dis(gen));
	}
	return uuid;
}

