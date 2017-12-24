// --- Parser.h ---

#ifndef PARSER_H_
#define PARSER_H_

//#include <iostream>
//#include <fstream>
//#include <utility>
#include "Env.h"

using namespace std;

class Parser {
public:
	Parser();
	Env readFile();
}; 

#endif
