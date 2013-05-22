//
//  matcher.h
//  cute
//
//  Created by pedro on 5/16/13.
//  Copyright (c) 2013 pedro. All rights reserved.
//

#ifndef _matcher_h
#define _matcher_h

#include <iostream>
#include <string>
#include <math.h>
#include <limits.h>

#include "lcs.h"
#include "parser.h"
#include "stringAlgorithms.h"

using namespace std;

class Matcher {
    
public:

    static int numStringMatching(string filename, string toSearch);
    static float avgStringMatching(string filename, string toSearch);
    static int approximateStringMatches(string filename, string toSearch);
    static string longestCommonSubsequence(string filename, string toSearch);

};

#endif
