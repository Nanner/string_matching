#include "interface.h"

void mainMenu() {

	bool continueMenu = true;
	bool userChosen = false;
	int numberOfOptions = 3;

	vector<User*> users;

	while(continueMenu) {

		cout << endl << "Conference Alert" << endl;

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
			userMenu(users);
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

void userMenu(vector<User*> &users) {

		bool continueMenu = true;
		int numberOfOptions = 4;

		while(continueMenu) {

			cout << endl << "User menu" << endl;

			cout << endl << "0- Exit\n1- Edit user\n2- Add user\n"
					"3- Remove user\n4- Load users\n";

			int option = getOption(numberOfOptions);

			switch(option) {
			case 0:
				return;
				break;
			case 1:
			{
				cout << "Choose a user\nPress enter to continue" << endl;
				getchar();
				User* user = displayVector(users);
				editUserMenu(user);
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
			default:
				cout << "Invalid option!\n";
				break;
			}

		}
}

void editUserMenu(User* user) {

}

void editInterestsMenu() {

}

void addUserMenu() {

}

void removeUserMenu() {

}

void loadUsersMenu() {

}

bool loginMenu() {

	return false;

}

void emailMenu() {

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
