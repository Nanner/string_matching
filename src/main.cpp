//
//  main.cpp
//  Strings
//
//  Created by pedro on 5/18/13.
//  Copyright (c) 2013 T1GD. All rights reserved.
//

#include "main.h"

int main(){
    
    string interest = "traffic systems";
    
	string filename = "1.txt";
    Email email = Parser::parseEmailToObject(filename);
    Matcher::findMatches(email, interest);
    
    vector<Match> matches ( email.getResults().at(0).getMatches() );

    for (int i = 0; i < matches.size(); i++) {
        cout << matches.at(i).getFoundString() << " " << matches.at(i).getDistance() << " " << matches.at(i).getLine() << endl;
    }
    
    Result result = email.getResults().at(0);
    result.getSameLineMatches();
     
	mainMenu();
    return 0;
}
