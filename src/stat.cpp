#include "stat.h"

Stat::Stat(vector<Email> &emails) {

	if(emails.empty()) {
		statsCalculated = false;
	}
	else {
		this->emails = emails;
		calculateMatches();
		sortEmailsByRelevance();
	}
}

vector<Email> Stat::getEmails() const {
	return emails;
}

void Stat::addEmail(Email email) {
	emails.push_back(email);
}

void Stat::calculateMatches() {
	vector<string> userInterests = user.getInterests();

	if(!emails.empty() && !userInterests.empty()) {
		for(unsigned int i = 0; i < emails.size(); i++) {
			for(unsigned int j = 0; j < userInterests.size(); j++) {
				Matcher::findMatches(emails.at(i), userInterests.at(j));
			}
		}
	}
}

void Stat::sortEmailsByRelevance() {
	sort(emails.begin(), emails.end());
	reverse(emails.begin(), emails.end());
}
