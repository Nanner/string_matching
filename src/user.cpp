#include "user.h"

User::User(string name): name(name) {}

User::User(string name, vector<string> interests): name(name), interests(interests) {}

string User::getName() {
	return name;
}

void User::setName(string name) {
	this->name = name;
}

vector<string> User::getInterests() {
	return interests;
}

void User::setInterests(vector<string> interests) {
	this->interests = interests;
}

void User::addInterest(string interest) {
	interests.push_back(interest);
}

bool User::removeInterest(string interest) {
    
	vector<string>::iterator it = interests.begin();
    
	for(; it != interests.end(); it++) {
		if((*it).compare(interest) == 0) {
			it = interests.erase(it);
			return true;
		}
	}
    
	return false;
    
}

ostream & operator << (ostream &out, User &u) {
    out << u.name << endl;
    if(!u.interests.empty()) {
        out << "Interests:" << endl;
        for(unsigned int i = 0; i < u.interests.size(); i++) {
            cout << u.interests[i] << endl;
        }
    }
    
    return out;
}
