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
	string getInfo(cFile); // TODO @marcin show all information about one file

private:
	map <string, cFile> hashFiles; // map with cFile ang hash
	string dataFile; // name of file, where map is saved

	string getHash(string &filename);
	string getHash(cFile file); // returns hash from cFile
	bool addToMap(string &hash, cFile);
	bool loadFromFileToMap(); // TODO
	bool saveMapToFile(); // TODO
};

#endif /* CMANAGER_H_ */
