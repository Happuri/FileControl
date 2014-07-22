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

#define DBG __FUNCTION__<<":"<< __LINE__<<"\t"


using namespace std;

class cFile {
public:
	cFile(string &name, string &author, int trustLvlFile, string &desc);
	virtual ~cFile();

	void printInfo() ; // displays info
	string toString(); // returns all info about file as string TODO @marcin

	// getters
	const string& getAuthor() const {
		return author;
	}

	const string& getDesc() const {
		return desc;
	}

	int getTrustLvlFile() const {
		return trustLvlFile;
	}

	const string& getName() const {
		return name;
	}

private:
	string name;
	string author;
	int trustLvlFile;
	string desc;
};

#endif /* CFILE_H_ */
