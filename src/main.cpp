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
	cManager FileControl;
	if (option=="-A") {
		FileControl.addDatabase(argv[5]);
		string author=getlogin();
		int lvl=atoi(argv[3]);
		string desc=argv[4];
		cFile file1(filename, author, lvl, desc);
		FileControl.add(file1);
		FileControl.saveMapToFile(argv[5]);
		cout<<"Adding file: "<<file1.getName()<<" with checksum "<<FileControl.getInfo(file1)<<" with trust "<< file1.getTrustLvlFile() <<" by author "<<file1.getAuthor()<<endl;
	}
	else if (option=="-G") {
		string author="test_author";
		int lvl=0;
		string desc="0";
		cFile file1(filename, author, lvl, desc);
		cout<<"Checking file "<<filename<<" with checksum "<<FileControl.getInfo(file1)<<endl;		
		FileControl.lookForFile(FileControl.getInfo(file1),filename);
	}
	// creating cFile
	// creating cManager and adding file1: two ways
	//cManager FIleControl(file1);
	return 0;
}
