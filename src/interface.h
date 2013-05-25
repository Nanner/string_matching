//
//  interface.h
//  Strings
//
//  Created by Nanner on 5/21/13.
//  Copyright (c) 2013 mine. All rights reserved.
//

#ifndef _interface_h
#define _interface_h

#include <iostream>
#include <sstream>
#include <stdio.h>

#include "user.h"
#include "email.h"
#include "parser.h"
#include "stat.h"
#include "displayWithPages.h"

using namespace std;

#define PROMPT "> "
#define MAIL_FILE ".txt"
#define EQUALS '='
#define USER "USER"
#define INTEREST "INTEREST"

#define DISPLAY_FORMAT "%-6s | %-14s | %-6s | %-8s \n"
#define DISPLAY_FORMAT_RESULT "%-6d | %-14s | %-6d | %-8.2f\n"

/**
 * An interface shows the application user a set of commands to use the program's functionalities.
 * This class also manages the user input and outputs the results of his actions in a
 * readable way.
 */
class Interface {
	User loggedInUser; /**< The currently logged in user. */
	vector<User*> users; /**< The users currently loaded. */
	vector<Email> emails; /**< The emails loaded by the user. */
	vector<Email> analyzedEmails; /**< The emails analyzed in the last search. */

public:

	/**
	 * Asks for the user to input a number from 0 to maxOption. Checks if the input is valid.
	 *
	 * @param maxOption The maximum number that can be given by the user
	 * @return The option made by the user
	 */
	int getOption(int maxOption);

	/**
	 * Asks for the user to input a number from 0 to maxOption. Checks if the input is valid.
	 *
	 * @param maxOption The maximum number that can be given by the user
	 * @return The option made by the user
	 */
	int getOption();


	/**
	 * Main menu of the interface - Offers to open the user menu, user login and load email menu.
	 * If a user is logged in, shows its name.
	 * After the user logs in and loads up some emails, offers the option to start the email search.
	 */
	void mainMenu();

	/**
	 * User menu - Offers to edit, add or remove an user, load users from and save them to a file.
	 */
	void userMenu();

	/**
	 * User edit menu - Prompts the choice of an existing user (if users exist already) and offers options to
	 * edit that user information (name and topics of interest).
	 */
	void editUserMenu(User* user);

	/**
	 * Edit interests menu - Permits adding or removing user interests.
	 */
	void editInterestsMenu(User* user);

	/**
	 * Asks for the name of the new user and adds him to the user vector, if no user with the same name exists.
	 */
	void addUserMenu();

	/**
	 * Asks for the name of an user to remove. Informs if the remove was successful or if the user doesn't exist.
	 */
	void removeUserMenu();

	/**
	 * Asks for the name of the file where the users are saved and attempts to load it.
	 */
	void loadUsersMenu();

	/**
	 * Asks for the name of the file and saves the current users to it.
	 */
	void saveUsersMenu();

	/**
	 * Shows a list of current users (if any users exists) and permits the choice of one to log in.
	 * @return True if a user was logged in, false if not.
	 */
	bool loginMenu();

	/**
	 * Offers the options to load and remove a single email or load a batch of emails.
	 */
	void emailMenu();

	/*
	 * Removes the email indicated by the user. Informs if the email doesn't exist.
	 */
	void removeEmailMenu();

	/*
	 * Has options to run a search on the loaded emails or display the results, if
	 * a search has previously been run.
	 */
	void searchMenu();

	/*
	 * Displays general results of an email match search.
	 */
	void displayResults();

	/*
	 * Displays the results of an email with more detail and in a more readable format.
	 * @param email The email to display.
	 */
	void displayEmailResults(Email email);

	/*
	 * Loads a batch of emails in the form number.txt from the interval firstEmailNumber to lastEmailNumber
	 * @param firstEmailNumber Index for the first email in the email interval.
	 * @param lastEmailNumber Index for the last email in the email interval.
	 */
	void batchLoad(int firstEmailNumber, int lastEmailNumber);

	/*
	 * Loads user info from the file given in the filename.
	 * @param filename The file's filename
	 *
	 * @return True if successfully loaded, false otherwise.
	 */
	bool loadUsers(const string& filename);

	/*
	 * Saves the current user info to a file given by filename.
	 * @param filename The file's filename
	 *
	 * @return True if successfully saved, false otherwise.
	 */
	bool saveUsers(const string& filename);

	/*
	 * Checks if an email exists in the email vector given. That is, if an email with the same filename exists.
	 * @param email The email to check the existence of.
	 * @param emails The email vector to check at.
	 *
	 * @return True if an email with the same filename already exists, false otherwise.
	 */
	bool emailExists(const Email email, const vector<Email> emails);

};

#endif

