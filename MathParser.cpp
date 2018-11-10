/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathParser.cpp
 * Author: Raphaël
 * 
 * Created on 11 avril 2016, 14:13
 */

#include "MathParser.hpp"

#include "BasicOperation.hpp"
#include "NullExpression.hpp"
#include "UnknownOperation.hpp"
#include "SyntaxError.hpp"
#include <functional>
#include <cstdlib>
#include <cmath>
#include <stdexcept>

MathParser::OperationsMap MathParser::getBasicOperations() {
	OperationsMap basicOps;
	
	basicOps['+'] = BasicOperation<std::plus<double>>::proceed;
	basicOps['-'] = BasicOperation<std::minus<double>>::proceed;
	basicOps['*'] = BasicOperation<std::multiplies<double>>::proceed;
	basicOps['/'] = BasicOperation<std::divides<double>>::proceed;
	
	return basicOps;
}

MathParser::MathParser(const std::string &expr):
	m_expr(expr), m_currentChar(0) {
}

double MathParser::parse(const std::string& expr) {
	m_expr = expr;
	return parse();
}

double MathParser::parse() {
	m_currentChar = m_expr.c_str();
	m_lastResult = 0;
	m_analyze = {0, 0, 0};
	
	if(*m_currentChar == 0) {
		throw NullExpression();
	}
	
	m_analyze.first_double = parseNextDouble();
	if(*m_currentChar == 0) {
		return m_analyze.first_double;
	}
	
	m_analyze.op = parseNextOperation();
	if(*m_currentChar == 0) {
		throw SyntaxError("operation without number");
	}
	
	m_analyze.second_double = parseNextDouble();
	if(*m_currentChar != 0) {
		throw SyntaxError("invalid characters");
	}
	
	m_lastResult = m_analyze.op(
		m_analyze.first_double,
		m_analyze.second_double);
	return m_lastResult;
}

double MathParser::parseNextDouble() {
	
	if(!isdigit(*m_currentChar) && *m_currentChar != '.') {
		throw SyntaxError("invalid number");
	}
	
	int intPartDigits(0), decPartDigits(0);
	int *currentDigits(&intPartDigits);
	const char *pointPosition(0);
	const char* const numberBegin(m_currentChar);
	double result(0.0);
	
	// Décompose le nombre
	
	while(1) {
		
		if(isdigit(*m_currentChar)) {
			
			(*currentDigits)++;
		}
		else if(*m_currentChar == '.') {
			
			if(pointPosition != 0)
				throw SyntaxError("invalid number");
			
			pointPosition = m_currentChar;
			currentDigits = &decPartDigits;
		}
		else {
			
			break;
		}
		
		m_currentChar++;
	}
	
	if(decPartDigits == 0) {
		pointPosition = 0;
	}
	
	// Construit le nombre
	
	const char *reversed(m_currentChar - 1);
	int isIntPart(pointPosition == 0);
	const char *sequenceBegin(isIntPart ? numberBegin - 1 : pointPosition);
	
	while(reversed >= numberBegin) {
		
		if(*reversed == '.') {
			
			sequenceBegin = numberBegin - 1;
			isIntPart = 1;
		}
		else {
			
			// Here, reversed is a digit

			char digit = *reversed - '0';
			int exponent(sequenceBegin - reversed + intPartDigits * isIntPart);
						
			result += digit * std::pow(10, exponent);
		}
		
		reversed--;
	}
	
	return result;
}

MathParser::operation_ptr MathParser::parseNextOperation() {
	OperationsMap::iterator it(BASIC_OPERATIONS.find(*m_currentChar));
	m_currentChar++;
	
	if(it == BASIC_OPERATIONS.end()) {
		throw UnknownOperation(it->first);
	}
	else {
		return it->second;
	}
}

std::map<char, MathParser::operation_ptr>
	MathParser::BASIC_OPERATIONS = MathParser::getBasicOperations();