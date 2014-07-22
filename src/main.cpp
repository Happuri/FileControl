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
#include <unistd.h> 

using namespace std;

int main(int argc, char* argv[]) {
	// informations about file
	string filename=argv[2];
	string option=argv[1];
	if (option=="-A") {
		string author=getlogin();;
		int lvl=atoi(argv[3]);
		string desc=argv[4];
		cFile file1(filename, author, lvl, desc);
		cManager FileControl;
		FileControl.add(file1);
		FileControl.saveMapToFile(); 
		cout<<"Adding file: "<<file1.getName()<<" with checksum "<<FileControl.getInfo(file1)<<" with trust "<< file1.getTrustLvlFile() <<" by author "<<file1.getAuthor()<<endl;
		return 0;
	}
	else if (option=="-G") {
		string author="test_author";
		int lvl=0;
		string desc="0";
		cFile file1(filename, author, lvl, desc);
		cManager FileControl;
		cout<<"Checking file "<<filename<<" with checksum "<<FileControl.getInfo(file1)<<endl;
		FileControl.lookForFile(FileControl.getInfo(file1),filename);
	}
	// creating cFile
	// creating cManager and adding file1: two ways
	//cManager FIleControl(file1);

	return 0;
}
