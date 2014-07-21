/*
 * cFile.cpp
 *
 *  Created on: 19 lip 2014
 *      Author: abby
 */

#include "cFile.h"

cFile::cFile(string& name, string& author, int trustLvlFile, string& desc) {
	this->name = name;
	this->author = author;
	this->trustLvlFile = trustLvlFile;
	this->desc = desc;
	printInfo();
}


cFile::~cFile() {
	// TODO Auto-generated destructor stub
}

void cFile::printInfo() {
	cout << "\n        ---------INFO---------" << endl;
	cout << "       name: " << this->name << endl;
	cout << "     author: " << this->author << endl;
	cout << "trust level: " << this->trustLvlFile << endl;
	cout << "description: " << this->desc << endl;
	cout << "        -------END INFO-------" << endl;

}

