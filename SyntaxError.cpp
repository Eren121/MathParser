/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SyntaxError.cpp
 * Author: Raphaël
 * 
 * Created on 11 avril 2016, 15:08
 */

#include "SyntaxError.hpp"

SyntaxError::SyntaxError(const std::string& msg) throw():
	m_msg(msg) {
}

SyntaxError::~SyntaxError() throw() {
}

const char* SyntaxError::what() const throw() {
	std::string final_msg;
	
	if(m_msg.empty()) {
		final_msg = "Syntax error ";
	}
	else {
		final_msg = "Syntax error: " + m_msg;
	}
	
	return final_msg.c_str();
}

