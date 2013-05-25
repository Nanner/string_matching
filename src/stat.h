//  stat.h
//
//  Projeto 2 CAL
//
//  Turma 1 Grupo D
//
//  ei11089 - Diogo Santos
//  ei11122 - Pedro Fernandes
//  ei11132 - Daniel Pereira
//

#ifndef _stat_h
#define _stat_h

#include <vector>
#include <algorithm>

#include "user.h"
#include "email.h"
#include "matcher.h"

using namespace std;

/**
 * Statistics class. This will process every email and user interest and order the matching of the keywords in the emails' contents.
 */
class Stat {
private:
	vector<Email> emails; /**< User's emails that will be analyzed */
	User user; /**< The user with interests (keywords) */
	bool statsCalculated; /**< If the statistics were sucessfully calculated. */
public:
    /**
     * Constructor for stat.
     * @param emails The user's emails.
     * @param user The user.
     */
	Stat(vector<Email> &emails, User user);

    /**
     * @return The user's emails.
     */
	vector<Email> getEmails() const;

    /**
     * Adds a new mail to the email vectors.
     * @param email The new email.
     */
	void addEmail(Email email);
    
    /**
     * Orders the calculation of all the matches for each of the user's interests (keywords) and every email.
     */
	void calculateMatches();
    
    /**
     * Sorts emails by their relevance (an email is more relevant if it has more results)
     */
	void sortEmailsByRelevance();
};


#endif
