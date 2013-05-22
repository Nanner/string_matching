#ifndef _user_h
#define _user_h

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class User {

	string name;
	vector<string> interests;

public:

	User() {}
	User(string name);
	User(string name, vector<string> interests);

	string getName();
	void setName(string name);
	vector<string> getInterests();
	void setInterests(vector<string> interests);
	void addInterest(string interest);
	bool removeInterest(string interest);
    friend ostream & operator << (ostream &out, User &u);

};


#endif
