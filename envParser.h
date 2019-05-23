// --- envParser.h ---

#ifndef ENVPARSER_H_
#define ENVPARSER_H_

//#include <iostream>
//#include <fstream>
#include "Parser.h"

using namespace std;

class Env;

class envParser : public Parser {
public:
	envParser(Env* env); 
	void readEnv();
	void dimCheck(int, int);
}; 

#endif
