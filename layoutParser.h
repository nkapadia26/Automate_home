// --- layoutParser.h ---

#ifndef LAYOUTPARSER_H_
#define LAYOUTPARSER_H_

//#include <iostream>
//#include <fstream>
//#include <utility>
#include "Parser.h"
using namespace std;

class Env;

class layoutParser : public Parser {
public:
	layoutParser(Env* env); 
	void readLayout();
}; 

#endif
