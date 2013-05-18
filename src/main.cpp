//
//  main.cpp
//  Strings
//
//  Created by pedro on 5/18/13.
//  Copyright (c) 2013 T1GD. All rights reserved.
//

#include "main.h"

int main(){
    string toSearch="traffic systems";
    
	string filename="1.txt";
    cout << longestCommonSubsequence(filename, toSearch) << endl;
    //cout << approximateStringMatches(filename, toSearch);
    return 0;
}