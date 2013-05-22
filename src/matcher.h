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
#include "result.h"

using namespace std;

class Matcher {
    
public:

    static int getExactMatches(const string& contents, const string& keywords);
    static float avgStringMatching(const string& contents, const string& keyword);
    static vector<Match> approximateStringMatches(const string& contents, const string& keywords);
    static vector<Match> longestCommonSubsequence(const string& contents, const string& keywords);

    static void findMatches(Email &email, const string& keywords);

};

#endif
