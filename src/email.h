#ifndef _email_h
#define _email_h

#include <string>
#include <vector>

#include "result.h"
#include "parser.h"

using namespace std;

/**
 * An email holds the contents of a CFP announcement message.
 * This class also contains the results of any number of searches in it's contents,
 * and any other useful information about the email itself.
 */
class Email {
private:
	string fileName; /**< The name of the text file which the email was loaded from. */
	string content; /**< The message contents of the email. */
	vector<Result> results; /**< Results of any query to the contents of the email. */

public:
    /**
     * Email constructor.
     */
	Email();
    
    /**
     * Email constructor.
     * @param fileName The file name of the email text file.
     */
	Email(string fileName);
    
    /**
     * Email constructor
     * @param fileName The file name of the email text file.
     * @param content The email message contents.
     */
	Email(string fileName, string content);
    
    /**
     * @return The name of the email text file.
     */
	string getFileName() const;
    
    /**
     * @return The contents of the email.
     */
	string getContent() const;
    
    /**
     * @return Results of all the matches on the contents of the email.
     */
	vector<Result> getResults() const;
    
    /**
     * Adds result of a search to this email.
     * @param result The result of a match to the contents of the email.
     */
	void addResult(Result result);
    
    /**
     * @return Number of all the query results done to the email contents.
     */
	int getNumberOfResults() const;
    
    /**
     * @return The total score of all the results given by the matches to the email contents.
     */
	int getTotalEmailScore() const;
    
    /**
     * Compares two emails. An email is bigger if it has more results than another. If both emails have the same number of results, the bigger is the one with biggest result score.
     * @param other The other email to compare to.
     * @return True if the email has a lesser score than the other.
     */
	bool operator <(const Email &other) const;
};


#endif
