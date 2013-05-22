#include "email.h"

Email::Email() {
	relativeScore = 0;
}

Email::Email(string fileName) {
	this->fileName = fileName;
	relativeScore = 0;
}

Email::Email(string fileName, string content) {
	this->fileName = fileName;
	this->content = content;
	relativeScore = 0;
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
		for(int i = 0; i < results.size(); i++) {
			score += results[i].getMatchScore();
		}
	}

	return score;
}

int Email::getRelativeScore() const {
	return relativeScore;
}

void Email::setRelativeScore(int relativeScore) {
	this->relativeScore = relativeScore;
}
