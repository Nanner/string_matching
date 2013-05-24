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

/**
 * Parses a text file (email message) to a string that can be used for matching purposes.
 */
class Parser {
    
public:
	static string ignoreList;

    /**
     * Opens a file and parses it's contents to a formatted string.
     * @param filename The name of the file with the contents.
     * @return String with the formatted contents.
     */
    static string parseEmail(string filename);
    
    /**
     * Parses a text file to an Email object.
     * @param filename The name of the file with the contents.
     * @return Email object with the contents of the file.
     */
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
