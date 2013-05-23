//
//  match.cpp
//  Strings
//
//  Created by pedro on 5/22/13.
//  Copyright (c) 2013 feup. All rights reserved.
//

#include "match.h"

Match::Match(string found, int line, int distance){
    this->found = found;
    this->line = line;
    this->distance = distance;
}

int Match::getScore() const{
    if (distance == 0)
        return EXACT_MATCH_WEIGHT;
    else
        return PARTIAL_MATCH_WEIGHT;
}

int Match::getDistance() const{
    return distance;
}

bool Match::isExact() const{
    return (distance == 0);
}

bool Match::isPartial() const{
    return (distance != 0);
}

string Match::getFoundString(){
    return found;
}

int Match::getLine() const{
    return line;
}