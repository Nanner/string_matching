#ifndef _email_h
#define _email_h

#include <string>
#include <vector>

#include "result.h"
#include "parser.h"

class Result;

using namespace std;

class Email {
private:
	string fileName;
	string content;
	vector<Result> results;

public:
	Email();
	Email(string fileName);
	Email(string fileName, string content);
	string getFileName() const;
	string getContent() const;
	vector<Result> getResults() const;
	void addResult(Result result);
	int getNumberOfResults() const;
	int getTotalEmailScore() const;
	bool operator <(const Email &other) const;
};


#endif
