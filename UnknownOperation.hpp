/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UnknownOperation.hpp
 * Author: Raphaël
 *
 * Created on 11 avril 2016, 15:35
 */

#ifndef UNKNOWNOPERATION_HPP
#define UNKNOWNOPERATION_HPP

#include "SyntaxError.hpp"

class UnknownOperation: public SyntaxError {
public:
	UnknownOperation(char c);
	virtual ~UnknownOperation();
};

#endif /* UNKNOWNOPERATION_HPP */

