#include "email.h"

Email::Email() {
}

Email::Email(string fileName) {
	this->fileName = fileName;
}

Email::Email(string fileName, string content) {
	this->fileName = fileName;
	this->content = content;
}

string Email::getFileName() const {
	return fileName;
}

string Email::getContent() const {
	return content;
}

vector<Result> Email::getResults() const {
	return results;
}

void Email::addResult(Result result) {
	results.push_back(result);
}

int Email::getNumberOfResults() const {
	if(results.empty()) {
		return 0;
	}

	return results.size();
}

int Email::getTotalEmailScore() const {
	int score = 0;

	if(!results.empty()) {
		for(unsigned int i = 0; i < results.size(); i++) {
			score += results[i].getMatchScore();
		}
	}

	return score;
}

bool Email::operator <(const Email& other) const {
	if(getNumberOfResults() == other.getNumberOfResults()) {
		return (getTotalEmailScore() < other.getTotalEmailScore());
	}
	else {
		return (getNumberOfResults() < other.getNumberOfResults());
	}
}
