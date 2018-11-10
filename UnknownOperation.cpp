/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UnknownOperation.cpp
 * Author: Raphaël
 * 
 * Created on 11 avril 2016, 15:35
 */

#include "UnknownOperation.hpp"
#include <string>

UnknownOperation::UnknownOperation(char c) {
	m_msg = "unknown operation: '";
	m_msg += c;
	m_msg += '\'';
}

UnknownOperation::~UnknownOperation() {
}