// --- Parser.h ---

#ifndef PARSER_H_
#define PARSER_H_

//#include <iostream>
//#include <fstream>
//#include <utility>

using namespace std;

class Env;

class Parser {
private:
	Env* _env;
public:
	Parser(Env* env); 
	void readFile();
}; 

#endif
