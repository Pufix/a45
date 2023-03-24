#include "domain.h"
class repository {
private:
	dynamicVector <user> users;
	dynamicVector <movie> movies;
public:
	repository() {

	}
	void addUser(user newUser) {
		users.append(newUser);
	}
	void addMovie(movie newMovie) {
		movies.append(newMovie);
	}
	user getUser(int index) {
		return users[index];
	}
	movie getMovie(int index) {
		return movies[index];
	}
	int counterUsers() {
		return users.getSize();
	}
	int counterMovies() {
		return movies.getSize();
	}
	void deleteUser(int index) {
		users.remove(index);
	}
	void deleteMovie(int index) {
		movies.remove(index);
	}
	dynamicVector<user> getAllUsers() {
		this->users;
	}
	dynamicVector<movie> getAllMovies() {
		this->movies;
	}
};