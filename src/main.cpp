//============================================================================
// Name        : main.cpp
// Author      : happuri, marcin, TheNaturat
// Version     :
// Copyright   : 
// Description : FileControl, cheking checksum of file and compare them with database
//============================================================================

#include "cManager.h"
#include "cFile.h"
#include <iostream>
#include <unistd.h> 

#include <fstream>
#include <string>
#include <map>

#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <crypto++/files.h>

#include "cFile.h"

using namespace std;

int main(int argc, char* argv[]) {


		/* argv[1] - option (string)	
		 * argv[2] - name of file	(string)
		 * argv[3] - level of trust (int)
		 * argv[4] - description of file (string)
		 * argv[5] - name of database (string)
		 */
		 
		 
	string option=argv[1];		// obtain option
	
	cManager FileControl;
	
	/*			Add file to the database			*/
	if (option=="-A") {
		
			if(argc!=6){
				cout << "[-A] nameOfFile level desc database" << endl;
			}
			
			if(argc==6){
				FileControl.addDatabase(argv[5]);
			}
			
		string filename=argv[2];
		int lvl=atoi(argv[3]);
		string desc=argv[4];
		//FileControl.addDatabase(argv[5]);
		string author=getlogin();										// obtain name of user (string)	
		
		cFile file1(filename, author, lvl, desc);
		FileControl.add(file1);
		FileControl.saveMapToFile(argv[5]);
		
		cout<<"Adding file: "<<file1.getName()<<" with checksum "<<FileControl.getInfo(file1)<<" with trust "<< file1.getTrustLvlFile() <<" by author "<<file1.getAuthor()<<endl;
		
	}
	
	/* 			Check the checksum of file			*/
	else if (option=="-G") {
		
		if (argc==4){
		FileControl.dataFile = argv[3];
	}
	
		string filename=argv[2];
		FileControl.fConstructor(FileControl.dataFile);
		
		string author="test_author";
		int lvl=0;
		string desc="0";
		
		cFile file1(filename, author, lvl, desc);
		
		cout<<"Checking file "<<filename<<" with checksum "<<FileControl.getInfo(file1)<<endl;
		FileControl.lookForFile(FileControl.getInfo(file1),filename);
		
	}
	
	/*			Display Map			*/
	else if(option=="-M"){
		
		if(argc==3){
			FileControl.dataFile = argv[2];
		}
		
		FileControl.fConstructor(FileControl.dataFile);
		FileControl.displayMap();
		
	}
	
	
	
	
	// creating cFile
	// creating cManager and adding file1: two ways
	// cManager FIleControl(file1);
	
	return 0;
}
