/*
 * cManager.cpp
 *
 *  Created on: 19 lip 2014
 *      Author: abby
 */

#include "cManager.h"

cManager::cManager() :
		dataFile("data.txt") {
	cout << "--FileControl--" << endl; // prints tmp
	cout << DBG << dataFile << endl;
}

cManager::cManager(string filename) :
		dataFile("data.txt") {
	cout << DBG << "File to add:  " << filename << endl;

}

void cManager::displayMap() {
	cout << "---DISPLAYING MAP!!---" << endl;
	map<string, cFile>::iterator it = this->hashFiles.begin();
	for (it = this->hashFiles.begin(); it != this->hashFiles.end(); ++it)
		cout << "   " << it->first << endl;

//		cout << "   " << it->first << " => " << it->second.toString() << endl;
	cout << "------END MAP---------" << endl;
}

string cManager::getHash(string &filename) {
	CryptoPP::SHA1 sha1;
	string hash = "";
	fstream file;
	file.open(filename.c_str(), ios::in);

	CryptoPP::FileSource(file, true, new CryptoPP::HashFilter(sha1, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));
	cout << DBG << filename << "\t" << hash << endl;
	return hash;
}

string cManager::getHash(cFile file) {
	string filename = file.getName();
	return getHash(filename);
}
map<string, cFile> cManager::getMap() {
	return hashFiles;
}

bool cManager::addToMap(string &hash, cFile file) {
	map<string, cFile>::iterator it = this->hashFiles.find(hash);
	// if this file is arleady in map
	if (it != hashFiles.end()) {
		cout << DBG << "File is arleady in map" << endl;
		return false;
	}

	pair<map<string, cFile>::iterator, bool> ret;
	ret = this->hashFiles.insert(pair<string, cFile>(hash, file));
	return true;
}

bool cManager::add(string &filename, string &author) {
	string hash = getHash(filename);
	return false;
//	cFile toAdd(filename, author, hash);
//	return addToMap(filename, toAdd);
}

cManager::~cManager() {
	// TODO Auto-generated destructor stub
}

bool cManager::loadFromFileToMap() {
}

bool cManager::saveMapToFile() {
}

cFile cManager::generateCFile(string& filename) {
}
