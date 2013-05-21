//
//  matcher.cpp
//  cute
//
//  Created by pedro on 5/16/13.
//  Copyright (c) 2013 pedro. All rights reserved.
//

#include "matcher.h"

int Matcher::numStringMatching(string filename, string toSearch){

    string contents = Parser::parseEmail(filename);
    vector<int> results = StringAlgorithms::KMP(contents, toSearch);
    return (int)results.size();
}

float Matcher::avgStringMatching(string filename, string toSearch){
    stringstream contents ( Parser::parseEmail(filename) );
    string word;
    int words = 0; int total = 0;
    while (contents.good()) {
        contents >> word;
        total += StringAlgorithms::levenshtein_distance(word, toSearch);
        words++;
    }
    return (float)total/words;
}

int Matcher::approximateStringMatches(string filename, string toSearch){
    stringstream contents ( Parser::parseEmail(filename) );
    stringstream searches ( toSearch );
    string searchWord;
    vector<string> searchWords;
    string word;
    int min = INT_MAX;
    int distance;
    
    while ( searches.good() ) {
        searches >> searchWord;
        searchWords.push_back(searchWord);
    }
    
    while ( contents.good() ) {
        contents >> word;
        for (int i = 0; i < searchWords.size(); i++) {
            distance = StringAlgorithms::levenshtein_distance(word, searchWords.at(i));
            if (distance <= ceil(searchWords.at(i).size() / 3) ){
                cout << distance << " - " << word << endl;
            }
            if (distance < min)
                min = distance;
        }
    }
    return min;
}

string Matcher::longestCommonSubsequence(string filename, string toSearch){
    stringstream contents ( Parser::parseEmail(filename) );
    stringstream searches ( toSearch );
    string searchWord;
    vector<string> searchWords;
    
    // get all search words included in the toSearch string
    while (searches.good()) {
        searches >> searchWord;
        searchWords.push_back(searchWord);
    }
    
    string line;
    stringstream results;
    int lineCounter = 1;
    
    while (contents.good()) {
        getline(contents, line);
        lineCounter++;
        
        char * X = new char [toSearch.length()+1];
        strcpy(X, toSearch.c_str());
        
        char * Y = new char [line.length()+1];
        strcpy (Y, line.c_str());
        
        vector<char> result;
        
        // run a LCS for each line
        LCS::findOne(X, strlen(X), Y, strlen(Y), result);
        string resultString(&result.front(), result.size());
        
        delete X; delete Y;
        
        if (resultString.size() == 0) continue;
        
        // check if the resulting common string has any of the keywords
        int matches = 0;
        for (int i = 0; i < searchWords.size(); i++) {
            matches += StringAlgorithms::KMP(resultString, searchWords.at(i)).size();
        }
        
        if (matches == 0) continue;
        
        stringstream buffer;
        results << "line " << lineCounter << " " << resultString << endl;
    }
    
    return results.str();
}
