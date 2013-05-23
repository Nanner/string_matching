//
//  lcs.cpp
//  Strings
//
//  Created by pedro on 5/18/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#include "lcs.h"

string LCS::findCommonSequence(const string& S, const string& T){
    char * X = new char [S.length()+1];
    strcpy(X, S.c_str());
    
    char * Y = new char [T.length()+1];
    strcpy(Y, T.c_str());
    
    vector<char> result;
    
    findCommonSequence(X, strlen(X), Y, strlen(Y), result);
    string resultString(&result.front(), result.size());
    
    delete X; delete Y;
    return resultString;
}