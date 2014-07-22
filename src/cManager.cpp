/*
 * cManager.cpp
 *
 *  Created on: 19 lip 2014
 *      Author: abby
 */

#include "cManager.h"

cManager::cManager() :
		dataFile("data.txt") {
//	cout << "--FileControl--" << endl; // prints tmp
//	cout << DBG << dataFile << endl;
loadFiletoMap();
}

cManager::cManager(cFile toAdd) :
		dataFile("data.txt") {
	bool ok = add(toAdd);
}

void cManager::displayMap() {
	cout << "---DISPLAYING MAP!!---" << endl;
	map<string, cFile>::iterator it = this->hashFiles.begin();
	for (it = this->hashFiles.begin(); it != this->hashFiles.end(); ++it)
		cout << "- " << it->first << " => " << it->second.getName() << endl;

//		cout << "   " << it->first << " => " << it->second.toString() << endl;
	cout << "------END MAP---------" << endl;
}

string cManager::getHash(string &filename) {
	CryptoPP::SHA512 sha512;
	string hash = "";
	fstream file;
	file.open(filename.c_str(), ios::in);

	CryptoPP::FileSource(file, true, new CryptoPP::HashFilter(sha512, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));
//	cout << DBG << filename << "\t" << hash << endl;
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
//		cout << DBG << "File is arleady in map" << endl;
		return false;
	}

	pair<map<string, cFile>::iterator, bool> ret;
	ret = this->hashFiles.insert(pair<string, cFile>(hash, file));
	return true;
}

bool cManager::add(cFile toAdd) {
//	cout << DBG << "File to add:  " << toAdd.getName() << endl;
	string hash = getHash(toAdd);
	if (!addToMap(hash, toAdd)) {
		cout << DBG << "Can't add to map " << toAdd.getName() << endl;
		return false;
	}
	//displayMap();
	return true;
}

cManager::~cManager() {
}

bool cManager::lookForFile(string checksum, string name) {
	ifstream Database("data_base.txt");
	bool isfound=false;
	string line;
	int samechecksum=0;
	int samechecksumandname=0;
	static int othername=0;
	int samename=0;
	for (map<string,cFile>::iterator it=this->hashFiles.begin(); it!=this->hashFiles.end(); ++it){
		if(it->first==checksum && it->second.getTrustLvlFile()>=50 && it->second.getName()==name) {
			cout<<"OK, found the checksum at good trust"<<it->second.getTrustLvlFile();
			isfound=true;
			samechecksum++;
			samechecksumandname++;
		}
		else  if(it->second.getName()!=name) {
			cout<<"OK, found the checksum at good trust"<<it->second.getTrustLvlFile();
			isfound=true;
			samechecksum++;
			othername++;
		}
		else if(it->second.getName()==name && it->first!=checksum ) {
			isfound=true;
			samename++;
		}
	}
	if(isfound==true) {
		cout<<"Same data (same checksum) : "<<samechecksum<<endl;
		cout<<"including same data (same checksum) and same name : "<<samechecksumandname<<endl;
		cout<<"including same data (same checksum) but other name : "<< othername<<endl;
		cout<<"Same name (just file name) : "<<samename<<endl;
	}
	else cout<<"Nothing found"<<endl;
	return isfound;
}

bool cManager::loadFiletoMap() {
	ifstream Database("data_base.txt");
	string line;
	if(!Database){
	while(getline(Database,line)) {
		string filename=line;
		getline(Database,line);
		int lvl=atoi(line.c_str());
		getline(Database,line);
		string author=line;
		getline(Database,line);
		string desc=line;
		cFile file1(filename, author, lvl, desc);
		getline(Database,line);
		this->hashFiles.insert(pair<string,cFile>(line,file1) );
	}
}
	return false;
}

bool cManager::saveMapToFile() {
	ofstream Database("data_base.txt",ios::out | ios::app);
	if(Database.good()){
	for (map<string,cFile>::iterator it=this->hashFiles.begin(); it!=this->hashFiles.end(); ++it){
		Database<<it->second.getName()<<endl;
		Database<< it->second.getTrustLvlFile()<<endl;
		Database<<it->second.getAuthor()<<endl;
		Database<<it->second.getDesc()<<endl;
		Database<<this->getInfo(it->second)<<endl;
	}
}
	return true;
}

string cManager::getInfo(cFile file) {
	return getHash(file);
}
