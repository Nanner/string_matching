//
//  main.cpp
//  Strings
//
//  Created by pedro on 5/18/13.
//  Copyright (c) 2013 T1GD. All rights reserved.
//

#include "main.h"

int main(){
    string toSearch="intelligent";
    
	string filename="1.txt";
    cout << longestCommonSubsequence(filename, toSearch) << endl;
    return 0;
}