#include <cstdlib>

#include "MathParser.hpp"
#include "BasicOperation.hpp"
#include <iostream>

using namespace std;

void test(const char *expr) {
	
	try {
		MathParser parser(expr);
		cout << parser.parse() << endl;
	}
	catch(const SyntaxError& er) {
		cout << er.what() << endl;
	}
}
int main(int argc, char** argv) {
	
	test("12356789");
	test("333.444");
	test("111.111+222.222");
	test("10/3");
	test("88888888888888888888888888888888888888888888888888888888888888");
	test("12500-250");
	test("23890*289.229");
	
	return 0;
}
