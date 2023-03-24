#pragma once
#include "domain.h"
class repository {
public:
	repository();
	void addMovie(movie newMovie);
	void addUser(user newUser);
	user getUser(int index);
	movie getMovie(int index);
	int counterUsers();
	int counterMovies();
	void deleteUser(int index);
	void deleteMovie(int index);
	dynamicVector<user> getAllUsers();
	dynamicVector<movie> getAllMovies();
};