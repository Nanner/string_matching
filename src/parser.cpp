//
//  parser.cpp
//  Strings
//
//  Created by pedro on 5/19/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#include "parser.h"

string Parser::ignoreList = Parser::parseIgnoreList(IGNORE_LIST);

string Parser::parseEmail(string filename) {
	ifstream file;
	file.open(filename.c_str());
	if(!file.is_open()) {
		throw(FileNotFound(filename));
	}
	string contents;
	string line;
	while (file.good()) {
		getline(file, line);
		contents += line;
		contents += '\n';
        contents.erase(remove_if(contents.begin(), contents.end(), (int(*)(int))ispunct), contents.end());
	}
	transform(contents.begin(), contents.end(), contents.begin(), ::tolower);
	file.close();
	return contents;
}

string Parser::parseIgnoreList(string filename) {
	ifstream file;
	file.open(filename.c_str());
	if(!file.is_open()) {
		throw(FileNotFound(filename));
	}
	string contents;
	string line;
	while (file.good()) {
		getline(file, line);
		contents += line;
		contents += '\n';
	}
	transform(contents.begin(), contents.end(), contents.begin(), ::tolower);
	file.close();
	return contents;
}

//TODO exception
Email Parser::parseEmailToObject(string filename) {
	string content;
	try {
		content = parseEmail(filename);
	}
	catch(FileNotFound& nf) {
		throw;
	}

	return Email(filename, content);
}
