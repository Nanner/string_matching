#ifndef _result_h
#define _result_h

#include <string>
#include <vector>

using namespace std;

#define EXACT_MATCH_WEIGHT 10
#define PARTIAL_MATCH_WEIGHT 2

class Result {
private:
    string query;
    int exactMatches;
    int partialMatches;
public:
    Result(string query);
    string getQuery() const;
    int getExactMatches() const;
    int getPartialMatches() const;
    int getMatchScore() const;
};

#endif
