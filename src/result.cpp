#include "result.h"

Result::Result(string query) {
	this->query = query;
}

string Result::getQuery() const {
	return query;
}

int Result::getExactMatches() const {
	return exactMatches;
}

int Result::getPartialMatches() const {
	return partialMatches;
}

int Result::getMatchScore() const {
	return (exactMatches * EXACT_MATCH_WEIGHT + partialMatches * PARTIAL_MATCH_WEIGHT);
}
