/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NullExpression.hpp
 * Author: Raphaël
 *
 * Created on 11 avril 2016, 14:58
 */

#ifndef NULLEXPRESSION_HPP
#define NULLEXPRESSION_HPP

#include <exception>
#include "SyntaxError.hpp"

class NullExpression : public SyntaxError {
public:
	NullExpression() throw();
	virtual ~NullExpression() throw();
	
private:
	static const char* const MSG;
};

#endif /* NULLEXPRESSION_HPP */

