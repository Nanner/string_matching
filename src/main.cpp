//
//  main.cpp
//  Strings
//
//  Created by pedro on 5/18/13.
//  Copyright (c) 2013 T1GD. All rights reserved.
//

#include "main.h"

int main(){
    string toSearch="intelligent vehicles";
    
	string filename="1.txt";
    cout << Matcher::longestCommonSubsequence(filename, toSearch) << endl;
    Matcher::approximateStringMatches(filename, toSearch);
    return 0;
}