//
//  stringAlgorithms.h
//  Strings
//
//  Created by pedro on 5/19/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#ifndef _string_algorithms_h
#define _string_algorithms_h

#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

/**
 * A class containing all the string matching algorithms that are used.
 */
class StringAlgorithms {
    
public:
    /**
     * Returns a vector containing the zero based index of
     *  the start of each match of the string K in S.
     *  Matches may overlap
     * For more information, check
     * https://en.wikibooks.org/wiki/Algorithm_Implementation/String_searching/Knuth-Morris-Pratt_pattern_matcher
     */
    static vector<int> KMP(string S, string K);
    
    /**
     * This is an implementation of the Wagner–Fischer algorithm.
     * For more information, check 
     * https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance
     */
    template<class T>
    static unsigned int levenshtein_distance(const T &s1, const T & s2)
    {
        const size_t len1 = s1.size(), len2 = s2.size();
        vector<unsigned int> col(len2+1), prevCol(len2+1);
        
        for (unsigned int i = 0; i < prevCol.size(); i++)
            prevCol[i] = i;
        for (unsigned int i = 0; i < len1; i++) {
            col[0] = i+1;
            for (unsigned int j = 0; j < len2; j++)
                col[j+1] = min( min( 1 + col[j], 1 + prevCol[1 + j]),
                               prevCol[j] + (s1[i]==s2[j] ? 0 : 1) );
            col.swap(prevCol);
        }
        return prevCol[len2];
    }
};

#endif 
