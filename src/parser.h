//
//  parser.h
//  Strings
//
//  Created by pedro on 5/19/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#ifndef _parser_h
#define _parser_h

#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "email.h"

using namespace std;

#define IGNORE_LIST "ignoreList.txt"

class Email;

class Parser {
    
public:
	static string ignoreList;
    static string parseEmail(string filename);
    static Email parseEmailToObject(string filename);
    static string parseIgnoreList(string filename);
};

class FileNotFound {
	string filename;

public:
	FileNotFound(string filename): filename(filename){}
	string getName() {return filename;}
};

#endif 
