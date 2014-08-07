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
#include <vector>

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
		
		// Help
			if(argc!=6){
				cout << "[-A] nameOfFile level desc database" << endl;		
			}
		// Additional option (database)
			if(argc==6){
				FileControl.addDatabase(argv[5]);
			}
		
		// Assign argv to variables
		string filename=argv[2];
		int lvl=atoi(argv[3]);
		string desc=argv[4];
		string author=getlogin();										// obtain name of user (string)	

		// Add file to database
		cFile file1(filename, author, lvl, desc);
		FileControl.add(file1);
		FileControl.saveMapToFile(argv[5]);
		
		// Display info
		cout<<"Adding file: "<<file1.getName()<<" with checksum "<<FileControl.getInfo(file1)<<" with trust "<< file1.getTrustLvlFile() <<" by author "<<file1.getAuthor()<<endl;
		
	}
	
	/* 			Check the checksum of file			*/
	else if (option=="-G") {
		
	// Additional option (database)
		if (argc==4){
		FileControl.dataFile = argv[3];
	}
	
	// Add variable, obtain vector of files
		string filename=argv[2];
		FileControl.fConstructor(FileControl.dataFile);
		
		string author="test_author";
		int lvl=0;
		string desc="0";
		
		cFile file1(filename, author, lvl, desc);
	
	// Display info
		cout<<"Checking file "<<filename<<" with checksum "<<FileControl.getInfo(file1)<<endl;
		FileControl.lookForFile(FileControl.getInfo(file1),filename);
		
	}
	
	/*			Display vector of files			*/
	else if(option=="-M"){
		
		// Additional option (database)
		if(argc==3){
			FileControl.dataFile = argv[2];
		}
		
		// Obtain vector of files and display it
		FileControl.fConstructor(FileControl.dataFile);
		FileControl.displayMap();
		
	}
	
	/*			Add new database to database list			*/
	else if(option=="-DBA"){
		
		FileControl.dbName = argv[2];
		FileControl.dbAdd(FileControl.dbName);
		
	}
	
	/*			Display database list			*/
		else if(option=="-DBD"){
		
		cout << "List of databases: " << endl;
		FileControl.dbDisplay(FileControl.dbName);
		
	}
	
	
	
	// creating cFile
	// creating cManager and adding file1: two ways
	// cManager FIleControl(file1);
	
	return 0;
}
