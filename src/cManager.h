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
	cManager(cFile);
	virtual ~cManager();
	void displayMap(); // displays map
	bool add(string &filename, string &author); // add new file, parsing
	map <string, cFile> getMap(); // returns map

private:
	map <string, cFile> hashFiles;
	string dataFile;

	string getHash(string &filename);
	string getHash(cFile file);
	bool addToMap(string &hash, cFile);
	bool loadFromFileToMap(); // TODO
	bool saveMapToFile(); // TODO
	cFile generateCFile(string &filename);
};

#endif /* CMANAGER_H_ */
