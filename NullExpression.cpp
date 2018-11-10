/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NullExpression.cpp
 * Author: Raphaël
 * 
 * Created on 11 avril 2016, 14:58
 */

#include "NullExpression.hpp"
#include <string>

const char* const NullExpression::MSG = "cant parse null expression";

NullExpression::NullExpression() throw():
	SyntaxError(MSG) {
}

NullExpression::~NullExpression() throw() {
}