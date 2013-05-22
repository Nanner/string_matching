#include "stat.h"

Stat::Stat(vector<Email> emails) {

	this->emails = emails;

	comparator = findComparator(emails);



}

vector<Email> Stat::getEmails() const {
}

Email Stat::getComparator() const {
}

void Stat::addEmail(Email email) {
}

Email Stat::findComparator(vector<Email> emails) {
}

void Stat::calculateScores() {
}
