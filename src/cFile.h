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
	cFile(string &name, string &author, int trustLvlFile, string &desc);
	virtual ~cFile();

	string getName();

	const string& getAuthor() const {
		return author;
	}

	const string& getDesc() const {
		return desc;
	}

	int getTrustLvlFile() const {
		return trustLvlFile;
	}

private:
	string name;
	string author;
	int trustLvlFile;
	string desc;
	// TODO format in file
};

#endif /* CFILE_H_ */
