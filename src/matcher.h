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

/**
 * The matcher class will handle receiving contents and matching them with certain keywords, using the best string matching algorithms for the given situation.
 */
class Matcher {
    
public:

    /**
     * Returns the number of exact matches of the keywords in the given contents.
     * @param contents The contents of the message.
     * @param keywords All the keywords to match.
     * @return Number of perfect matches for each keyword.
     */
    static int getExactMatches(const string& contents, const string& keywords);
    
    /**
     * Returns the average distance of a keyword to all the words in the contents.
     * @param contents The contents of the message.
     * @param keyword The keyword to match.
     * @return Average in float.
     */
    static float avgStringMatching(const string& contents, const string& keyword);
    
    /**
     * Matches all the keywords in the given contents. This will pick up any exact or partial match, using the Wagner–Fischer algorithm to find the Levenshtein distance (edit distance) of the matching words.
     * @param contents The contents of the message.
     * @param keywords All the keywords to match.
     * @return A vector containing all the found matches.
     */
    static vector<Match> getAllStringMatches(const string& contents, const string& keywords);
    
    /**
     * Matches all the keywords in the given contents. This will pick up any exact or partial match, using the Longest Common Subsequence algorithm to find the Levenshtein distance (edit distance) of the matching words. 
     * @param contents The contents of the message.
     * @param keywords All the keywords to match.
     * @return A vector containing all the found matches.
     */
    static vector<Match> getAllStringMatchesLCS(const string& contents, const string& keywords);

    /**
     * Matches all the keywords in an email.
     * The results will be stored in the given email.
     * @param email The email to be analyzed.
     * @param keywords The keywords to match.
     */
    static void findMatches(Email &email, const string& keywords);

};

#endif
