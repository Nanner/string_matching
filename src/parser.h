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

class Email;

class Parser {
    
    
public:
    static string parseEmail(string filename);
    static Email parseEmailToObject(string filename);
};

#endif 
