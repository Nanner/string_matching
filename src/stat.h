#ifndef _stat_h
#define _stat_h

#include <vector>
#include <algorithm>

#include "user.h"
#include "email.h"
#include "matcher.h"

using namespace std;

class Stat {
private:
	vector<Email> emails;
	User user;
	bool statsCalculated;
public:
	Stat(vector<Email> &emails);

	vector<Email> getEmails() const;

	void addEmail(Email email);
	void calculateMatches();
	void sortEmailsByRelevance();
};


#endif
