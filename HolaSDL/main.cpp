



#include <iostream>
#include "Game.h"
#include "Menu.h"
using namespace std;

using uint = unsigned int;


int main(int argc, char* argv[]) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

	try {
		Menu menu;
		menu.run();
	}
	catch (exception e) {
		cout << e.what();
	}
	return 0;
}
/*
problemas con la basura
excepciones 
*/