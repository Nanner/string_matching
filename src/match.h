//  match.h
//
//  Projeto 2 CAL
//
//  Turma 1 Grupo D
//
//  ei11089 - Diogo Santos
//  ei11122 - Pedro Fernandes
//  ei11132 - Daniel Pereira
//

#ifndef _match_h
#define _match_h

#include <string>

using namespace std;

#define EXACT_MATCH_WEIGHT 10
#define PARTIAL_MATCH_WEIGHT 2

/**
 * A match is a word that was found in a text that resembles or is equal to the keyword of a search.
 */
class Match {
    string found; /**< The string that was found that matches the search */
    int line; /**< The line where it was found */
    int distance; /**< The edit distance to the original search keyword */
    
public:
    /**
     * Constructor for a match.
     * @param found The found string.
     * @param line The line where it was found.
     * @param distance The distance to the search keyword.
     */
    Match(string found, int line, int distance);
    
    /**
     * @return The score of this match. If the match is exact, the score is higher.
     */
    int getScore() const;
    
    /**
     * @return The edit distance between the found string and the keyword.
     */
    int getDistance() const;
    
    /**
     * @return True if this is an exact match to the keyword.
     */
    bool isExact() const;
    
    /**
     * @return True if this is a partial match to the keyword.
     */
    bool isPartial() const;
    
    /**
     * @return The found string that matches the keyword.
     */
    string getFoundString() const;
    
    /**
     * @return The line where the match was found.
     */
    int getLine() const;

};

#endif
