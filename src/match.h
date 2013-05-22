//
//  match.h
//  Strings
//
//  Created by pedro on 5/22/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#ifndef _match_h
#define _match_h

#include <string>

using namespace std;

#define EXACT_MATCH_WEIGHT 10
#define PARTIAL_MATCH_WEIGHT 2

class Match {
    string found;
    int line;
    int distance;
    
public:
    Match(string found, int line, int distance);
    int getScore() const;
    int getDistance() const;
    bool isExact() const;
    bool isPartial() const;
    string getFoundString();

};

#endif
