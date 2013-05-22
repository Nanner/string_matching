//
//  parser.cpp
//  Strings
//
//  Created by pedro on 5/19/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#include "parser.h"

string Parser::parseEmail(string filename){
    ifstream file;
    file.open(filename.c_str());
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
	string content = parseEmail(filename);
	Email email(filename, content);
	return email;
}
