//  matcher.h
//
//  Projeto 2 CAL
//
//  Turma 1 Grupo D
//
//  ei11089 - Diogo Santos
//  ei11122 - Pedro Fernandes
//  ei11132 - Daniel Pereira
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

#if defined __APPLE__ || defined linux || defined (__CYGWIN32__)
#define USE_TIMER
#endif

#ifdef USE_TIMER
#include <sys/time.h>
#include <unistd.h>
#define WAGNER_FISCHER 1
#define LONGEST_COMMON_SUBSEQUENCE 2
#define RUNS 100
#endif

using namespace std;
/**
 * The matcher class will handle receiving contents and matching them with certain keywords, using the best string matching algorithms for the given situation.
 */
class Matcher {
    static bool performanceMode;
    
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
    
    /**
     * Activates benchmark to test the string matching algorithms performance times.
     * @param performanceOn If the performance mode will be switched on.
     */
    static void setPerformanceMode(bool performanceOn);

#ifdef USE_TIMER
    /**
     * Starts a timer to measure performance time of a function.
     */
    static void startTimer();
    
    /**
     * Stops the timer started by startTimer() function.
     * @return The elapsed time between the start and stop.
     */
    static unsigned long stopTimer();
    
    /**
     * Checks the performance of a shortest path algorithm.
     * @param start The starting city.
     * @param algorithm The algorithm to test.
     * @return The average performance of the algorithm.
     */
    static unsigned long checkPerformance(int algorithm, Email &email, const string& keywords);
#endif
};

#endif
