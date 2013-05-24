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

vector<vector<Match> > Result::getSameLineMatches(){
    vector<vector<Match> > allSameLineMatches;    
    vector<Match>::iterator match;
    int lastLine = 0;
    vector<Match>::iterator last = matches.end();

    vector<Match> sameLineMatches;
    for (match = matches.begin(); match != matches.end(); ++match) {
        if (match->getLine() == lastLine){
            sameLineMatches.push_back(*last);
            sameLineMatches.push_back(*match);
            allSameLineMatches.push_back(sameLineMatches);
            sameLineMatches.clear();
        }
        last = match;
        lastLine = last->getLine();
    }
    
    for (int i = 0; i < allSameLineMatches.size(); i++) {
        for (int j = 0; j < allSameLineMatches.at(i).size(); j++) {
            cout << allSameLineMatches.at(i).at(j).getFoundString() << " " <<
            allSameLineMatches.at(i).at(j).getLine() << " ";
        }
        cout << endl;
    }
    
    return allSameLineMatches;
}

void Result::printMatches() {
	vector<Match> tmpMatches = matches;
	vector<Match>::iterator it = tmpMatches.begin();
	vector<Match>::iterator it2 = tmpMatches.begin() + 1;

	if(tmpMatches.empty()) {
		cout << "There were no matches for this interest." << endl;
	}

	for(; it != tmpMatches.end(); it++) {
		cout << "Found the keyword " << it->getFoundString() << " at line(s):" << endl;
		cout << it->getLine();
		for(it2 = it + 1; it2 != tmpMatches.end(); ) {
			if(it->getFoundString().compare(it2->getFoundString()) == 0) {
				cout << ", " << it2->getLine();
				it2 = tmpMatches.erase(it2);
			}
			else {
				++it2;
			}
		}
		cout << endl;
	}
}
