#include<string>
#include<typeinfo>
using namespace std;
template <class Type>
class dynamicVector {
private:
	int size;
	int capacity;
	Type* elements;
public:
	dynamicVector() {
		size = 0;
		capacity = 10;
		elements = new  Type[10];
	}
	void append(Type element) {
		if (size == capacity) {
			capacity *= 2;
			Type* newElements = new Type[capacity];
			for (int i = 0; i < size; i++)
				newElements[i] = elements[i];
			delete(elements);
			elements = newElements;
		}
		elements[size] = element;
		size++;
	}
	int getSize() {
		return size;
	}
	void remove(int position) {
		for (int i = position; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
		if (size == capacity / 4) {
			capacity /= 2;
			Type* newElements = new Type[capacity];
			for (int i = 0; i < size; i++)
				newElements[i] = elements[i];
			delete(elements);
			elements = newElements;
		}
	}
	Type operator[](int index) {
		return elements[index];
	}
};
class movie {
private:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
public:
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
		return a.title == title;
	}
};
class user {
private:
	std::string password;
	dynamicVector<movie> watchlist;
public:
	std::string username;
	int privilegeLevel;
	user(std::string usrname, std::string pasword) {
		username = usrname;
		password = pasword;
	}
	bool checkPassword(std::string pasword) {
		return pasword == password;
	}
	void addMovie(movie movie) {
		watchlist.append(movie);
	}
	void removeMovie(movie movie) {
		for (int i = 0; i < watchlist.getSize(); i++) {
			if (watchlist[i] == movie) {
				watchlist.remove(i);
				return;
			}
		}
	}
	dynamicVector<movie>getWatchlist() {
		return watchlist;
	}
};