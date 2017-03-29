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
#include "Laguerre.h"
#include "Muller.h"
#include <iostream>
#include <boost/math/tools/polynomial.hpp>
#include <complex>

//using namespace boost::math::tools; // for polynomial
using namespace std;
using namespace boost::math::tools;


int main() {
	/*Pol* n = new Pol();

	polynomial<double> const b{{-2.0, 1.0}};

	n->print_pol(b);*/
	//polynomial<double> const b{{4.0, 1.0,-2.0,3.0,2.0}};
  //polynomial<double> const b{{6.0,-5.0,1}};
	//polynomial<complex<double>> const b{{36.0, -27.0,-13.0,3.0,1.0}};
	//polynomial<complex<double>> b{{5.0, 1.0,1.0,1.0,1.0}}; //4 complejas
	//polynomial<complex<double>> b{{36, -36.0,13.0,-4.0,1.0}};
	polynomial<double> b{{-8.0, -4.0,2.0,-1.0,1.0}}; //// 2 reales y 2 complejas
	//polynomial<complex<double>> b{{-60.0, -23.0,2.0, 1.0}};/////3 soluciones reales
	//polynomial<complex<double>> fd{{-23.0, 4.0,3.0, 0.0}};
	//polynomial<complex<double>> sd{{4.0, 6.0,0.0, 0.0}};
	Laguerre *lag = new Laguerre();
	lag->findZeros(0.0,b);
	//cout << "b = " << formula_format(b) << "\n\n";
/*
	Muller* m = new Muller();

	m->findZeros(1,3,0.00000000001,500);
*/

cout << "b = " <<endl;
  return 0;
}

// End of file Mueller.cpp
