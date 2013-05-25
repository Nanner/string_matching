//
//  matcher.cpp
//  cute
//
//  Created by pedro on 5/16/13.
//  Copyright (c) 2013 pedro. All rights reserved.
//

#include "matcher.h"

#ifdef USE_TIMER
static struct timeval clockStart, clockEnd; /**< Values that are used for timing performance. */
#endif

int Matcher::getExactMatches(const string& contents, const string& keywords){
    vector<int> matches = StringAlgorithms::KMP(contents, keywords);
    return (int)matches.size();
}

float avgStringMatching(const string& contents, const string& keyword){
    stringstream contentStream ( contents );
    string word;
    int words = 0; int total = 0;
    while (contentStream.good()) {
        contentStream >> word;
        total += StringAlgorithms::levenshtein_distance(word, keyword);
        words++;
    }
    return (float)total/words;
}

vector<Match> Matcher::getAllStringMatches(const string& contents, const string& keywords){
    istringstream contentStream ( contents );
    istringstream keywordStream ( keywords );
    string keyword, word, line;
    vector<string> keywordsVector;
    int distance, lineNumber = 0;
    vector<Match> matches;
    
    // parse all the keywords
    while ( keywordStream >> keyword ) {
        keywordsVector.push_back(keyword);
    }
    
    while ( getline(contentStream, line) ) {
        lineNumber++;
        istringstream lineStream (line);
        while ( lineStream >> word ) {
            for (unsigned int i = 0; i < keywordsVector.size(); i++)
            {
                keyword = keywordsVector.at(i);
                distance = StringAlgorithms::levenshtein_distance(word, keyword);
                if (distance <= ceil(keyword.size() / 3) )
                {
                    matches.push_back(Match(word, lineNumber, distance));
                }
            }
        }
    }
    return matches;
}

vector<Match> Matcher::getAllStringMatchesLCS(const string& contents, const string& keywords){
    istringstream contentStream ( contents );
    istringstream keywordStream ( keywords );
        
    string keyword, word, line;
    vector<string> keywordsVector;
    int distance, lineNumber = 0;
    
    vector<Match> matches;
    
    // parse all the keywords
    while ( keywordStream >> keyword ) {
        keywordsVector.push_back(keyword);
    }
    
    while ( getline(contentStream, line) ) {
        lineNumber++;
        istringstream lineStream (line);
        while ( lineStream >> word ) {
            for (unsigned int i = 0; i < keywordsVector.size(); i++) {
                
                keyword = keywordsVector.at(i);
                
                // run a LCS for each word found
                string resultString = LCS::findCommonSequence(word, keyword);
                /*
                 The minimum edit distance to transform S into T is achieved by doing
                 |S| - LCS(S,T) deletes and |T| - LCS(S,T) inserts.
                 
                 Substitutions are not accounted.
                 */
                
                distance  = (int) ( keyword.size() - resultString.size() );
                distance += (int) (    word.size() - resultString.size() );
                
                if (distance <= ceil(keywordsVector.at(i).size() / 3) ){
                    matches.push_back(Match(word, lineNumber, distance));
                }
                
            }
            
        }
    }
    return matches;
}

void Matcher::findMatches(Email &email, const string& keywords){
    // get a result for these keywords
    Result result(keywords);
    
    static unsigned long totalAvg1 = 0, totalAvg2 = 0;
    static unsigned int numberOfRuns = 0;
    
#ifdef USE_TIMER
    stringstream performance;
    unsigned long average1 = checkPerformance(WAGNER_FISCHER, email, keywords);
    unsigned long average2 = checkPerformance(LONGEST_COMMON_SUBSEQUENCE, email, keywords);
    performance << email.getFileName() << " keywords: " << keywords << endl;
    performance << "W-F performance: " << average1 << " microseconds" << endl;
    performance << "LCS performance: " << average2 << " microseconds" << endl;
    //cout << performance.str();
#endif
    totalAvg1 += average1; totalAvg2 += average2;
    numberOfRuns++;
    stringstream totals;
    totals << "W-F performance: " << totalAvg1 << " microseconds" << endl;
    totals << "LCS performance: " << totalAvg2 << " microseconds" << endl;
    totals << "Number of queries: " << numberOfRuns << endl;
    cout << totals.str();


//vector<Match> matches = getAllStringMatches(email.getContent(), keywords);
    vector<Match> matches = getAllStringMatchesLCS(email.getContent(), keywords);
    for (unsigned int i = 0; i < matches.size(); i++) {
        // the result will contain all the matches for the keywords
        result.addMatch(matches.at(i));
    }
    email.addResult(result);
}

#ifdef USE_TIMER
inline void Matcher::startTimer() {
    gettimeofday(&clockStart, NULL);
    return;
}

inline unsigned long Matcher::stopTimer(){
    gettimeofday(&clockEnd, NULL);
    unsigned long mtime, seconds, useconds;
    seconds  = clockEnd.tv_sec  - clockStart.tv_sec;
    useconds = clockEnd.tv_usec - clockStart.tv_usec;
    
    mtime = ((seconds) * 1000000 + useconds);
    return mtime;
}

unsigned long Matcher::checkPerformance(int algorithm, Email& email, const string& keywords){
    unsigned long time = 0;
    switch (algorithm) {
        case WAGNER_FISCHER:
        {
            unsigned long runs = RUNS;
            startTimer();
            for (unsigned long run = 0; run < runs; run++) {
                vector<Match> matches = getAllStringMatches(email.getContent(), keywords);
            }
            time = stopTimer();
            time /= runs;
            break;
        }
        case LONGEST_COMMON_SUBSEQUENCE:
        {
            unsigned long runs = RUNS;
            startTimer();
            for (unsigned long run = 0; run < runs; run++) {
                vector<Match> matches = getAllStringMatchesLCS(email.getContent(), keywords);
            }
            time = stopTimer();
            time /= runs;
            break;
        }
        default:
            break;
    }
    return time;
}
#endif
