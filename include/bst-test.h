//
//  Project : Collections I
//  File    : bst-test.h
//  Desc.   : tests for bst class
//  Author  : Nathan Standiford <ns@byu.edu>
//

#ifndef BST_TEST_H
#define BST_TEST_H
#include <UnitTest.h>
#include "BST.h"
#include <string>
using namespace std;
/******** Constants for expData[] ********/
const int ALPHA    = 0;
const int BETA     = 1;
const int DELTA    = 3;
const int EPISOLON = 4;
const int ETA      = 5;
const int GAMMA    = 2;
const int THETA    = 7;
const int ZETA     = 6;

string testData[] = {"alpha","beta","gamma","delta","episolon","zeta","eta","theta"};
string expData[]  = {"alpha","beta","gamma","delta","episolon","eta","zeta","theta"};

const int TEST_DATA_SIZE = 8;

#endif
