#ifndef _result_h
#define _result_h

#include <string>
#include <vector>

#include "match.h"
#include "parser.h"
#include "stringAlgorithms.h"

#include <iostream>

using namespace std;

class Result {
private:
    string query;
    vector<Match> matches;

public:
    Result(string query);
    string getQuery() const;
    int getExactMatches() const;
    int getPartialMatches() const;
    int getMatchScore() const;
    void addMatch(Match newMatch);
    vector<Match> getMatches();
    vector<vector<Match> > getSameLineMatches();
    bool isIgnoredWord(string word);
    void printMatches();

};

#endif
