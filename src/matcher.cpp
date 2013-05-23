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
    istringstream contentStream ( contents );
    istringstream keywordStream ( keywords );
    string keyword, word, line;
    vector<string> keywordsVector;
    int distance, lineNumber = 0;
    vector<Match> matches;
    
    // parse all the keywords
    while ( keywordStream.good() ) {
        keywordStream >> keyword;
        keywordsVector.push_back(keyword);
    }
    
    while ( getline(contentStream, line) ) {
        lineNumber++;
        istringstream lineStream (line);
        while ( lineStream >> word ) {
            for (int i = 0; i < keywordsVector.size(); i++)
            {
                keyword = keywordsVector.at(i);
                distance = StringAlgorithms::levenshtein_distance(word, keyword);
                if (distance <= ceil(keyword.size() / 3) )
                {
                    matches.push_back(Match(word, lineNumber, distance));
                }
            }
        }
    }
    return matches;
}

vector<Match> Matcher::longestCommonSubsequence(const string& contents, const string& keywords){
    istringstream contentStream ( contents );
    istringstream keywordStream ( keywords );
    string keyword, word, line;
    vector<string> keywordsVector;
    int distance, lineNumber = 0;
    
    vector<Match> matches;
    
    // parse all the keywords
    while ( keywordStream.good() ) {
        keywordStream >> keyword;
        keywordsVector.push_back(keyword);
    }
    
    while ( getline(contentStream, line) ) {
        lineNumber++;
        istringstream lineStream (line);
        while ( lineStream >> word ) {
            for (int i = 0; i < keywordsVector.size(); i++) {
                
                keyword = keywordsVector.at(i);
                
                char * S = new char [keyword.length()+1];
                strcpy(S, keyword.c_str());
                
                char * T = new char [word.length()+1];
                strcpy(T, word.c_str());
                
                vector<char> result;
                
                // run a LCS for each word found
                LCS::findOne(T, strlen(T), S, strlen(S), result);
                string resultString(&result.front(), result.size());
                
                delete S; delete T;
                
                /*
                 The minimum edit distance to transform S into T is achieved by doing
                 |S| - LCS(S,T) deletes and |T| - LCS(S,T) inserts.
                 
                 Substitutions are not accounted.
                 */
                
                distance  = (int) ( keyword.size() - resultString.size() );
                distance += (int) (    word.size() - resultString.size() );
                
                if (distance <= ceil(keywordsVector.at(i).size() / 3) ){
                    matches.push_back(Match(word, lineNumber, distance));
                }
                
            }
            
        }
    }
    return matches;
}

void Matcher::findMatches(Email &email, const string& keywords){
    // get a result for these keywords
    Result result(keywords);
    //vector<Match> matches = approximateStringMatches(email.getContent(), keywords);
    vector<Match> matches = longestCommonSubsequence(email.getContent(), keywords);
    for (int i = 0; i < matches.size(); i++) {
        // the result will contain all the matches for the keywords
        result.addMatch(matches.at(i));
    }
    email.addResult(result);
}
