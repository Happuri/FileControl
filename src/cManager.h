/*
 * cManager.h
 *
 *  Created on: 19 lip 2014
 *      Author: abby, TheNaturat, marcin
 */

#ifndef CMANAGER_H_
#define CMANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <crypto++/files.h>

#include "cFile.h"

#define DBG __FUNCTION__<<":"<< __LINE__<<"\t"

using namespace std;

class cManager {
	
public:

	cManager();
	cManager(cFile); 							// constructor, add file to map
	virtual ~cManager();
	void displayMap(); 							// displays map
	void fConstructor(string dataFile); 		// code from constructor
	void addDatabase(string name);				// obtain map of files
	void dbAdd(string dbName);					// add database to dbList
	void dbDisplay(string dbName);				// display vector 
	bool add(cFile); 							// add new file, parsing
	bool saveMapToFile(char * name); 
	bool lookForFile(string checksum, string filename);	// check database
	map <string, cFile> getMap(); 				// returns map
	map <string, cFile> hashFiles; 				// map with cFile ang hash
	string dataFile; 							// name of file, where map is saved
	string dbName;								// name of database
	string getInfo(cFile file); 				//  show all information about one file
		
private:
		
	bool loadFiletoMap(std::ifstream & Database);
	bool addToMap(string &hash, cFile);
	vector<string> DataBases;					// list of files
	vector<string> dbList;						// list of databases
	string getHash(string &filename);			// returns hash from string
	string getHash(cFile file);					// returns hash from cFile
};

#endif /* CMANAGER_H_ */
