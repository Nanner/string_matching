#ifndef _stat_h
#define _stat_h

#include <vector>

#include "email.h"

using namespace std;

class Stat {
private:
	vector<Email> emails;
	Email comparator;

public:
	Stat(vector<Email> emails);

	vector<Email> getEmails() const;
	Email getComparator() const;

	void addEmail(Email email);
	Email findComparator(vector<Email> emails);
	void calculateScores();

};


#endif
