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
	// informations about file
	string filename="example.txt";
	string author="abby";
	int lvl=100;
	string desc="just test";

	// creating cFile
	cFile file1(filename, author, lvl, desc);

	// creating cManager and adding file1: two ways
	//cManager FIleControl(file1);

	cManager FileControl;
	FileControl.add(file1);
	return 0;
}
