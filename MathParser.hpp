/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathParser.hpp
 * Author: Raphaël
 *
 * Created on 11 avril 2016, 14:13
 */

#ifndef MATHPARSER_HPP
#define MATHPARSER_HPP

#include <string>
#include <map>
#include "SyntaxError.hpp"

class MathParser {
public:
	MathParser(const std::string &expr = "");
	
	double parse(const std::string &expr);
	double parse();
	
	typedef double(*operation_ptr)(double, double);
	typedef std::map<char, operation_ptr> OperationsMap;
	
protected:
	static OperationsMap BASIC_OPERATIONS;
	
	double parseNextDouble();
	operation_ptr parseNextOperation();
	
	std::string m_expr;
	const char *m_currentChar;
	
	struct {
		double first_double;
		double second_double;
		operation_ptr op;
	} m_analyze;
	
	double m_lastResult;
	
private:
	static OperationsMap getBasicOperations();
};

#endif /* MATHPARSER_HPP */

