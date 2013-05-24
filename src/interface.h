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

