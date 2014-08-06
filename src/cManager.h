/*
 * cManager.h
 *
 *  Created on: 19 lip 2014
 *      Author: abby
 */

#ifndef CMANAGER_H_
#define CMANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

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
	cManager(cFile); // constructor, add file to map
	virtual ~cManager();
	void displayMap(); // displays map
	bool add(cFile); // add new file, parsing
	map <string, cFile> getMap(); // returns map
	string getInfo(cFile file); //  show all information about one file
	bool saveMapToFile(char * name); 
	bool lookForFile(string checksum, string filename);
	map <string, cFile> hashFiles; // map with cFile ang hash
	void addDatabase(string name);
	string dataFile; // name of file, where map is saved
	void fConstructor(string dataFile);
	
	
private:
		
	bool loadFiletoMap(std::ifstream & Database);
	vector<string> DataBases;
	string getHash(string &filename);
	string getHash(cFile file); // returns hash from cFile
	bool addToMap(string &hash, cFile);
};

#endif /* CMANAGER_H_ */
