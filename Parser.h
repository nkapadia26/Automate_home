// --- Parser.h ---

#ifndef PARSER_H_
#define PARSER_H_

//#include <iostream>
//#include <fstream>
//#include <utility>

using namespace std;

class Env;

class Parser {
protected:
	Env* _env;
public:
	Parser(Env* env); 
}; 

#endif
