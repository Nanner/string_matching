#include "result.h"

Result::Result(string query) {
	this->query = query;
}

string Result::getQuery() const {
	return query;
}

int Result::getExactMatches() const {
	int exactMatches = 0;
	for (unsigned int i = 0; i < matches.size(); i++) {
		if ( matches.at(i).isExact() ) {
			exactMatches++;
		}
	}
	return exactMatches;
}

int Result::getPartialMatches() const {
	int partialMatches = 0;
	for (unsigned int i = 0; i < matches.size(); i++) {
		if ( matches.at(i).isPartial() ) {
			partialMatches++;
		}
	}
	return partialMatches;
}

int Result::getMatchScore() const {
	int totalScore = 0;
	for (unsigned int i = 0; i < matches.size(); i++) {
		totalScore += matches.at(i).getScore();
	}
	vector<vector<Match> > sameLineMatches = getSameLineMatches();
	totalScore += SAME_LINE_BONUS * (int)sameLineMatches.size();
	return totalScore;
}

void Result::addMatch(Match newMatch){
	if(!isIgnoredWord(newMatch.getFoundString())) {
		matches.push_back(newMatch);
	}
}

vector<Match> Result::getMatches(){
	return matches;
}

bool Result::isIgnoredWord(string word) {

	vector<int> ignoreMatches = StringAlgorithms::KMP(Parser::ignoreList, word);
	if(!ignoreMatches.empty())
		return true;

	return false;
}

vector<vector<Match> > Result::getSameLineMatches() const{
	vector<vector<Match> > allSameLineMatches;
	vector<Match>::const_iterator match;
	int lastLine = 0;
	vector<Match>::const_iterator last = matches.end();

	vector<Match> sameLineMatches;
	for (match = matches.begin(); match != matches.end(); ++match) {
		if (match->getLine() == lastLine){
			// check if the same keyword is repeated in the line
			if (StringAlgorithms::levenshtein_distance(last->getFoundString(),match->getFoundString()) < match->getFoundString().size() / 3 )
				continue;
			sameLineMatches.push_back(*last);
			sameLineMatches.push_back(*match);
			match++;
			if (match == matches.end() ){
				allSameLineMatches.push_back(sameLineMatches);
				sameLineMatches.clear();
				break;
			}

			while (match->getLine() == lastLine) {
				sameLineMatches.push_back(*match);
				match++;
				if(match == matches.end()) break;
			}

			allSameLineMatches.push_back(sameLineMatches);
			sameLineMatches.clear();
			if (match == matches.end() ) break;
		}
		last = match;
		lastLine = last->getLine();
	}

	/* // acess example
    for (int i = 0; i < allSameLineMatches.size(); i++) {
        for (int j = 0; j < allSameLineMatches.at(i).size(); j++) {
            cout << allSameLineMatches.at(i).at(j).getFoundString() << " " <<
            allSameLineMatches.at(i).at(j).getLine() << " ";
        }
        cout << endl;
    }
	 */
	return allSameLineMatches;
}

void Result::printMatches() {
	vector<Match> tmpMatches = matches;
	vector<Match>::iterator it = tmpMatches.begin();
	vector<Match>::iterator it2 = tmpMatches.begin() + 1;

	if(tmpMatches.empty()) {
		cout << "There were no matches for this interest." << endl;
		return;
	}

	printf(MATCH_DISPLAY_FORMAT, "Keyword", "Hits", "Lines");

	for(; it != tmpMatches.end(); it++) {
		string keyword = it->getFoundString();
		string lines;
		lines = SSTR(it->getLine());
		int hits = 1;
		for(it2 = it + 1; it2 != tmpMatches.end(); ) {
			if(it->getFoundString().compare(it2->getFoundString()) == 0) {
				lines += ", " + SSTR(it2->getLine());
				hits++;
				it2 = tmpMatches.erase(it2);
			}
			else {
				++it2;
			}
		}

		printf(MATCH_DISPLAY_FORMAT_RESULT, keyword.c_str(), hits, lines.c_str());
	}


}
