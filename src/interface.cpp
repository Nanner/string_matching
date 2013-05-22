#include "interface.h"

void mainMenu() {

	bool continueMenu = true;
	bool userChosen = false;
	int numberOfOptions = 3;

	while(continueMenu) {

		cout << endl << "Conference Alert" << endl;

		if(userChosen)
			cout << "Logged in as: " << loggedInUser.getName() << endl;

		cout << endl << "0- Exit\n1- User menu\n2- User login\n3- Load emails\n";
		if(userChosen) {
			cout << "4- Start search" << endl;
			numberOfOptions = 4;
		}
		else {
			cout << "Don't forget you need to login in order to search for emails!" << endl;
			numberOfOptions = 3;
		}

		int option = getOption(numberOfOptions);

		switch(option) {
		case 0:
			return;
			break;
		case 1:
			userMenu();
			break;
		case 2:
			userChosen = loginMenu();
			break;
		case 3:
			emailMenu();
			break;
		case 4:
			searchMenu();
			break;
		default:
			cout << "Invalid option!\n";
			break;
		}

	}
}

void userMenu() {

	bool continueMenu = true;
	int numberOfOptions = 5;

	while(continueMenu) {

		cout << endl << "User menu" << endl;

		cout << endl << "0- Exit\n1- Edit user\n2- Add user\n"
				"3- Remove user\n4- Load users\n5- Save users\n";

		int option = getOption(numberOfOptions);

		switch(option) {
		case 0:
			return;
			break;
		case 1:
		{
			if(users.empty()) {
				cout << "No users currently exist!" << endl << "Press enter to continue" << endl;
				getchar();
			}
			else {
				cout << "Choose a user\nPress enter to continue" << endl;
				getchar();
				User* user = displayVector(users);
				if(user == NULL)
					break;
				editUserMenu(user);
			}
		}
		break;
		case 2:
			addUserMenu();
			break;
		case 3:
			removeUserMenu();
			break;
		case 4:
			loadUsersMenu();
			break;
        case 5:
            saveUsersMenu();
            break;
		default:
			cout << "Invalid option!\n";
			break;
		}

	}
}

void editUserMenu(User* user) {

	bool continueMenu = true;
	int numberOfOptions = 2;

	while(continueMenu) {

		cout << endl << "Edit user" << endl;

		cout << endl << "0- Exit\n1- Edit name\n2- Edit topics of interest\n";

		int option = getOption(numberOfOptions);

		switch(option) {
		case 0:
			return;
			break;
		case 1:
		{
			cout << "Current name: " << user->getName() << endl;
			string newName;
			cout << "New name?" << endl << "> ";
			getline(cin, newName);
			user->setName(newName);
			cout << "Name changed!" << endl << "Press enter to continue" << endl;
			getchar();
		}
		break;
		case 2:
			editInterestsMenu(user);
			break;
		default:
			cout << "Invalid option!\n";
			break;
		}

	}

}

void editInterestsMenu(User* user) {

	bool continueMenu = true;
	int numberOfOptions = 2;

	while(continueMenu) {

		cout << endl << "Edit interests" << endl;

		cout << endl << "0- Exit\n1- Add interest\n2- Remove interest\n";

		int option = getOption(numberOfOptions);

		switch(option) {
		case 0:
			return;
			break;
		case 1:
		{
			string interest;
			cout << "Please type in interest and press enter" << endl << "> ";
			getline(cin, interest);
			user->addInterest(interest);
			cout << "Added interest, press enter to continue" << endl;
			getchar();
		}
		break;
		case 2:
		{
			if(user->getInterests().empty()) {
				cout << "This user currently has no interests!" << endl;
			}
			else {
				cout << "Choose the interest you wish to remove: " << endl;
				vector<string> interests = user->getInterests();
				string* interest = displayVector(interests);
				if(interest == NULL)
					break;
				if(user->removeInterest(*interest)) {
					cout << "Removed the selected interest!" << endl;
				}
				else {
					cout << "That interest does not exist!" << endl;
				}
			}
			cout << "Press enter to continue" << endl;
			getchar();
		}
		break;
		default:
			cout << "Invalid option!\n";
			break;
		}
	}
}

void addUserMenu() {

	string newName;
	cout << "New user name?" << endl;
	getline(cin, newName);

	for(unsigned int i = 0; i < users.size(); i++) {
		if(users[i]->getName().compare(newName) == 0) {
			cout << "A user with that name already exists!" << endl << "Press enter to continue" << endl;
			getchar();
			return;
		}
	}

	User* newUser = new User(newName);

	users.push_back(newUser);
}

void removeUserMenu() {

	string name;
	cout << "Name of user to delete?" << endl;
	getline(cin, name);

	vector<User*>::iterator it = users.begin();

	for(; it != users.end(); it++) {
		if((*it)->getName().compare(name) == 0) {
			it = users.erase(it);
			cout << "Removed user!" << endl << "Press enter to continue" << endl;
			getchar();
			return;
		}
	}

	cout << "User not found!" << endl << "Press enter to continue" << endl;
	getchar();
}

void loadUsersMenu() {
    loadUsers(USER_FILE);
}

void saveUsersMenu(){
    saveUsers(USER_FILE);
}

bool loginMenu() {

	cout << "Choose a user to log in as: " << endl;
	User* user = displayVector(users);

	if(user == NULL) {
		return false;
	}
	else {
		cout << "Logged in as: " << user->getName() << endl;
		loggedInUser = *user;
		return true;
	}

}

void emailMenu() {
	bool continueMenu = true;
	int numberOfOptions = 4;

	while(continueMenu) {

		cout << endl << "Email menu" << endl;

		cout << endl << "0- Back\n1- Load single email\n2- Remove email\n"
				"3- Batch load emails\n";

		int option = getOption(numberOfOptions);

		switch(option) {
		case 0:
			return;
			break;
		case 1:
			//TODO add exception for email not found
		{
			cout << "Email filename?" << endl << "> ";
			string filename;
			getline(cin, filename);
			emails.push_back(Parser::parseEmailToObject(filename));
		}
			break;
		case 2:
			break;
		case 3:
            // TODO get first and last number here
            // TODO warning that mails must be formatted "1.txt", "2.txt"
            batchLoad(1, 10);
            cout << "lock and loaded" << endl;
			break;
		default:
			cout << "Invalid option!\n";
			break;
		}

	}
}

void searchMenu() {

}

int getOption(int maxOption) {
	string input = "";
	int option;

	do {
		cout << PROMPT;
		getline(cin, input);
		stringstream stream(input);

		if (stream >> option && option >= 0 && option <= maxOption)
			break;

		cout << "Please enter a valid option" << endl;
	} while(true);

	return option;
}

void batchLoad(int firstEmailNumber, int lastEmailNumber){
    for (int i = firstEmailNumber; i < lastEmailNumber+1; i++) {
        stringstream filename;
        filename << i << MAIL_FILE;
        emails.push_back(Parser::parseEmailToObject(filename.str()));
    }
}

bool loadUsers(const string& filename){
    ifstream file;
    file.open(filename.c_str());
    
    if (!file.is_open())
        return false;
    
    string line;
    User * currentUser = NULL;
    
    while( getline( file, line ) )
    {
        istringstream iss(line);
        string object;
        if( getline(iss, object, EQUALS) )
        {
            if( object == USER )
            {
                string userName;
                getline(iss, userName);
                currentUser = new User(userName);
                users.push_back(currentUser);
            }
            
            if( object == INTEREST )
            {
                string interest;
                getline(iss, interest);
                currentUser->addInterest(interest);
            }
        }
    }
    return true;
}

bool saveUsers(const string& filename){
    ofstream file;
    file.open(filename.c_str(), fstream::trunc);
    vector<User*>::iterator user;
    vector<string>::iterator interest;
    for (user = users.begin(); user != users.end(); ++user) {
        file << USER << EQUALS << (*user)->getName() << endl;
        vector<string> interests = (*user)->getInterests();
        for (interest = interests.begin(); interest != interests.end(); ++interest) {
            file << INTEREST << EQUALS << (*interest) << endl;
        }
    }
    return true;
}

