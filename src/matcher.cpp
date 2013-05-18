//
//  matcher.cpp
//  cute
//
//  Created by pedro on 5/16/13.
//  Copyright (c) 2013 pedro. All rights reserved.
//

#include "matcher.h"

int numStringMatching(string filename, string toSearch){
    ifstream file;
    file.open(filename.c_str());
    string contents;
    string line;
    while (file.good()) {
        getline(file, line);
        contents += line;
        contents += '\n';
    }
    file.close();
    
    vector<int> results = KMP(contents, toSearch);
    return (int)results.size();
}

float numApproximateStringMatching(string filename, string toSearch){
    ifstream file;
    file.open(filename.c_str());
    string word;
    unsigned int words,total;
    words = 0; total = 0;
    while (file.good()) {
        file >> word;
        total += levenshtein_distance(word, toSearch);
        words++;
    }
    file.close();
    return (float)total/words;
}


//----------------------------
//Returns a vector containing the zero based index of
//  the start of each match of the string K in S.
//  Matches may overlap
//----------------------------
vector<int> KMP(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
    vector<int> matches;
    
    if(K.size() == 0)
    {
        matches.push_back(0);
        return matches;
    }
    for(int i = 1; i <= K.size(); i++)
    {
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }
    
    int sp = 0;
    int kp = 0;
    while(sp < S.size())
    {
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == K.size()) matches.push_back(sp - K.size());
    }
    
    return matches;
}