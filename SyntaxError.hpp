/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SyntaxError.hpp
 * Author: Raphaël
 *
 * Created on 11 avril 2016, 15:08
 */

#ifndef SYNTAXERROR_HPP
#define SYNTAXERROR_HPP

#include <exception>
#include <string>

class SyntaxError : public std::exception {
public:
	SyntaxError(const std::string& msg = "") throw();
	virtual ~SyntaxError() throw();
	
	virtual const char* what() const throw();
	
protected:
	std::string m_msg;
};

#endif /* SYNTAXERROR_HPP */

