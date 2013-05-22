//
//  matcher.cpp
//  cute
//
//  Created by pedro on 5/16/13.
//  Copyright (c) 2013 pedro. All rights reserved.
//

#include "matcher.h"

int Matcher::getExactMatches(const string& contents, const string& keywords){
    vector<int> matches = StringAlgorithms::KMP(contents, keywords);
    return (int)matches.size();
}

float avgStringMatching(const string& contents, const string& keyword){
    stringstream contentStream ( contents );
    string word;
    int words = 0; int total = 0;
    while (contentStream.good()) {
        contentStream >> word;
        total += StringAlgorithms::levenshtein_distance(word, keyword);
        words++;
    }
    return (float)total/words;
}

vector<Match> Matcher::approximateStringMatches(const string& contents, const string& keywords){
    stringstream contentStream ( contents );
    stringstream keywordStream ( keywords );
    string keyword;
    vector<string> keywordsVector;
    string word;
    int distance;
    
    vector<Match> matches;
    
    // parse all the keywords
    while ( keywordStream.good() ) {
        keywordStream >> keyword;
        keywordsVector.push_back(keyword);
    }
    
    while ( contentStream.good() ) {
        contentStream >> word;
        for (int i = 0; i < keywordsVector.size(); i++) {
            keyword = keywordsVector.at(i);
            distance = StringAlgorithms::levenshtein_distance(word, keyword);
            if (distance <= ceil(keyword.size() / 3) ){
                Match foundMatch(word, 0, distance);
                matches.push_back(foundMatch);
            }
            
        }
    }
    return matches;
}

vector<Match> Matcher::longestCommonSubsequence(const string& contents, const string& keywords){
    stringstream contentStream ( contents );
    stringstream keywordStream ( keywords );
    string keyword;
    vector<string> keywordsVector;
    string word;
    int distance;
    
    vector<Match> matches;
    
    // parse all the keywords
    while ( keywordStream.good() ) {
        keywordStream >> keyword;
        keywordsVector.push_back(keyword);
    }
    
    while ( contentStream.good() ) {
        contentStream >> word;
        for (int i = 0; i < keywordsVector.size(); i++) {
            
            char * X = new char [keyword.length()+1];
            strcpy(X, keyword.c_str());
            
            char * Y = new char [word.length()+1];
            strcpy (Y, word.c_str());
            
            vector<char> result;
            
            // run a LCS for each line
            LCS::findOne(X, strlen(X), Y, strlen(Y), result);
            string resultString(&result.front(), result.size());
            
            delete X; delete Y;

            distance = 0;
            
            if (distance <= ceil(keywordsVector.at(i).size() / 3) ){
                matches.push_back(Match(word, 10, distance));
            }
            
        }
    }
    return matches;
}

void Matcher::findMatches(Email &email, const string& keywords){
    // get a result for these keywords
    Result result(keywords);
    vector<Match> matches = approximateStringMatches(email.getContent(), keywords);
    for (int i = 0; i < matches.size(); i++) {
        // the result will contain all the matches for the keywords
        result.addMatch(matches.at(i));
    }
    email.addResult(result);
}
