/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasicOperation.hpp
 * Author: Raphaël
 *
 * Created on 12 avril 2016, 15:17
 */

#ifndef BASICOPERATION_HPP
#define BASICOPERATION_HPP

template<typename T>
class BasicOperation {
public:
	static double proceed(double a, double b);
};

template<typename T>
double BasicOperation<T>::proceed(double a, double b) {
	static T fctor;
	return fctor(a, b);
}

#endif /* BASICOPERATION_HPP */

