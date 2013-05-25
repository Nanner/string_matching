//  user.h
//
//  Projeto 2 CAL
//
//  Turma 1 Grupo D
//
//  ei11089 - Diogo Santos
//  ei11122 - Pedro Fernandes
//  ei11132 - Daniel Pereira
//

#ifndef _user_h
#define _user_h

#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * A user contains a simple list of interests (keywords).
 */
class User {

	string name; /**< The user name. */
	vector<string> interests; /**< The user's list of interest */

public:
    /**
     * The user constructor.
     */
	User() {}
    
    /**
     * The user constructor.
     * @param name The user name.
     */
	User(string name);
    
    /**
     * The user constructor.
     * @param name The user name.
     * @param interests The list of interests.
     */
	User(string name, vector<string> interests);

    /**
     * @return The user name.
     */
	string getName();
    
    /**
     * Sets a new user name.
     * @param name The new user name.
     */
	void setName(string name);
    
    /**
     * @return The list of user's interests.
     */
	vector<string> getInterests();
    
    /**
     * Replaces the user's interest with a new list of interests.
     * @param interests The new user interests.
     */
	void setInterests(vector<string> interests);
    
    /**
     * Adds a new user interest.
     * @param interest The new interest.
     */
	void addInterest(string interest);
    
    /**
     * Removes a user interest.
     * @param interest The interest to be removed
     * @return True if successful, false if the interest doesn't exist.
     */
	bool removeInterest(string interest);
    
    /**
     * Prints a user and it's interests.
     * @param out The output stream.
     * @param u The user to output.
     * @return The modified output stream.
     */
    friend ostream & operator << (ostream &out, User &u);

};


#endif
