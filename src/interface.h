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
#define USER_FILE "users.txt"

#define DISPLAY_FORMAT "%-6s | %-14s | %-6s | %-8s \n"
#define DISPLAY_FORMAT_RESULT "%-6d | %-14s | %-6d | %-8.2f\n"

/*
 *
 * Interface
 *
 * 1- User menu
 *    1a- Edit user -- Choose user
 *        1aa- Edit name
 *        1ab- Edit topics of interest
 *             1aba- Add interest
 *             1abb- Remove interest
 *    1b- Add user
 *    1c- Remove user
 *    1d- Load users
 *
 * 2- User "login"
 *
 * 3- Load emails
 *    3a- Load single email
 *    3b- Remove single email
 *    3c- Batch load -- inform load format
 *
 * 4- Start search -- Show results
 *
 */

class Interface {
    User loggedInUser;
    vector<User*> users;
    vector<Email> emails;
    vector<Email> analyzedEmails;
    
public:
    int getOption(int maxOption);
    
    int getOption();
    
    void mainMenu();
    
    void userMenu();
    
    void editUserMenu(User* user);
    
    void editInterestsMenu(User* user);
    
    void addUserMenu();
    
    void removeUserMenu();
    
    void loadUsersMenu();
    
    void saveUsersMenu();
    
    bool loginMenu();
    
    void emailMenu();
    
    void removeEmailMenu();
    
    void searchMenu();
    
    void displayResults();
    
    void displayEmailResults(Email email);
    
    void batchLoad(int firstEmailNumber, int lastEmailNumber);
    
    bool loadUsers(const string& filename);
    
    bool saveUsers(const string& filename);
    
};

#endif

