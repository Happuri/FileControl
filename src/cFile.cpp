/*
 * cFile.cpp
 *
 *  Created on: 19 lip 2014
 *      Author: abby
 */

#include "cFile.h"

cFile::cFile(string &name, string &author, string &hash) {
	this->name = name;
	this->author = author;
	this->hash = hash;
}

cFile::~cFile() {
	// TODO Auto-generated destructor stub
}

string cFile::getName() {
	return this->name;
}
