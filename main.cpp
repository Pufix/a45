#include<iostream>
#include<string>
#include<cstring>
#include "ui.h"
userInterface ui;
void run() {
	ui.startUp();
	bool running = true;
	do {
		running = ui.run();
	} while (running);
}
int main() {
	run();
	ui.serv.repo.movieDump();
	ui.serv.repo.userDump();
	return 0;
}