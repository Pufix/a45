#pragma once
#include "domain.h"
using namespace std;
#include <fstream>
class repository {
private:
	dynamicVector <user> users;
	dynamicVector <movie> movies;
public:
	repository() {
		this->userLoad();
		this->movieLoad();
	}
	void addUser(user newUser) {
		this->users.append(newUser);
	}
	void addMovie(movie newMovie) {
		this->movies.append(newMovie);
	}
	user getUser(int index) {
		return this->users[index];
	}
	movie getMovie(int index) {
		return this->movies[index];
	}
	int counterUsers() {
		return this->users.getSize();
	}
	int counterMovies() {
		return this->movies.getSize();
	}
	void deleteUser(int index) {
		this->users.remove(index);
	}
	void deleteMovie(int index) {
		this->movies.remove(index);
	}
	dynamicVector<user>getAllUsers() {
		return this->users;
	}
	dynamicVector<movie>getAllMovies() {
		return this->movies;
	}
	void userDump() {
		ofstream fout("users.txt");
		for (int i = 0; i < this->users.getSize(); i++) {
			fout << this->users[i] << endl;
		}
	}
	void movieDump() {
		ofstream fout("movies.txt");
		for (int i = 0; i < this->movies.getSize(); i++) {
			fout << this->movies[i] << endl;
		}
	}
	void userLoad() {
		ifstream fin("users.txt");
		while (!fin.eof()) {
			user newUser;
			fin >> newUser;
			if(newUser == user())
				break;
			this->users.append(newUser);
		}
	}
	void movieLoad() {
		ifstream fin("movies.txt");
		while (!fin.eof()) {
			movie newMovie;
			fin >> newMovie;
			if (newMovie == movie())
				break;
			this->movies.append(newMovie);
		}
	}
	void deleteMovie(movie movieToDelete) {
		for (int i = 0; i < this->movies.getSize(); i++)
			if (this->movies[i] == movieToDelete) {
				this->movies.remove(i);
				return;
			}
	}
	void deleteUser(user userToDelete) {
		for (int i = 0; i < this->users.getSize(); i++)
			if (this->users[i] == userToDelete) {
				this->users.remove(i);
				return;
			}
	}
};