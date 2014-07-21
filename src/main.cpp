//============================================================================
// Name        : main.cpp
// Author      : happuri
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "cManager.h"
#include "cFile.h"
#include <iostream>

using namespace std;

int main() {

	string filename="example.txt";
	string author="abby";
	int lvl=100;
	string desc="just test";
	cFile file1(filename, author, lvl, desc);
	cManager FIleControl(file1);
	return 0;
}
