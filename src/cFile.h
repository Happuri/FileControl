/*
 * cFile.h
 *
 *  Created on: 19 lip 2014
 *      Author: abby
 */

#ifndef CFILE_H_
#define CFILE_H_

#include <iostream>
#include <string>

using namespace std;

class cFile {
public:
	cFile(string &name, string &author, string &hash);
	virtual ~cFile();

	string getName();

private:
	string name;
	string author;
	string hash;
	int trustLvlFile;
	string desc;
	// TODO format in file
};

#endif /* CFILE_H_ */
