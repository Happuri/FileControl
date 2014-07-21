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
}


cFile::~cFile() {
	// TODO Auto-generated destructor stub
}

string cFile::getName() {
	return this->name;
}

