#include "result.h"

Result::Result(string query) {
	this->query = query;
}

string Result::getQuery() const {
	return query;
}

int Result::getExactMatches() const {
    int exactMatches = 0;
	for (int i = 0; i < matches.size(); i++) {
        if ( matches.at(i).isExact() ) {
            exactMatches++;
        }
    }
    return exactMatches;
}

int Result::getPartialMatches() const {
    int partialMatches = 0;
	for (int i = 0; i < matches.size(); i++) {
        if ( matches.at(i).isPartial() ) {
            partialMatches++;
        }
    }
    return partialMatches;
}

int Result::getMatchScore() const {
    int totalScore = 0;
    for (int i = 0; i < matches.size(); i++) {
        totalScore += matches.at(i).getScore();
    }
    return totalScore;
}

void Result::addMatch(Match newMatch){
    matches.push_back(newMatch);
}

vector<Match> Result::getMatches(){
    return matches;
}
