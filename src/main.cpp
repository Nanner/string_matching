//
//  main.cpp
//  Strings
//
//  Created by pedro on 5/18/13.
//  Copyright (c) 2013 T1GD. All rights reserved.
//

#include "main.h"

int main(){
    char X[] = "XMJYAUZ";
    char Y[] = "MZJAWXU";
    std::vector<char> result;
    
    LCS::findOne(X, strlen(X), Y, strlen(Y), result);
    std::string resultString(&result.front(), result.size());
    cout << resultString << endl;
    return 0;
}