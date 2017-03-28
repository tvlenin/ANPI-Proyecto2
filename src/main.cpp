/*
 * main.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: fasm22
 */


/****************************************************
*     Program to demonstrate Mueller's method       *
* ------------------------------------------------- *
* Reference: BASIC Scientific Subroutines, Vol. II  *
* By F.R. Ruckdeschel, BYTE/McGRAWW-HILL, 1981 [1]. *
*                                                   *
*                C++ version by J-P Moreau, Paris.  *
*                       (www.jpmoreau.fr)           *
* ------------------------------------------------- *
* Example:  Find a real root of f(x)=(x+1)^5        *
*                                                   *
* Sample run:                                       *
*                                                   *
* Input the initial guess:                          *
*    X0 = 0                                         *
* What is the bond of this guess: 3                 *
* Error criterion: 1e-6                             *
* Maximum number of iterations: 100                 *
*                                                   *
* The calculated zero is X = -1.000476              *
* The associated value is Y =  0.000000             *
* The number of steps was: 47                       *
*                                                   *
****************************************************/

#include "Muller.h"
#include <iostream>

//using namespace boost::math::tools; // for polynomial
using namespace std;


int main() {
	/*Pol* n = new Pol();

	polynomial<double> const b{{-2.0, 1.0}};

	n->print_pol(b);*/

	Muller* m = new Muller();

	m->findZeros(0,3,0.00000001,1000);

  return 0;
}

// End of file Mueller.cpp

