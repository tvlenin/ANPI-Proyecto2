/*
 * Muller.h
 *
 *  Created on: Mar 27, 2017
 *      Author: fasm22
 */

#ifndef SRC_MULLER_H_
#define SRC_MULLER_H_

#include <stdio.h>
#include <cmath>
#include <boost/math/tools/polynomial.hpp>
#include <iostream>
#include <complex>

using namespace boost::math::tools; // for polynomial
using namespace std;

// global variables
bool isComplex = false;
int    k,n;
double d,e,x,x0;

class Muller{
public:
	Muller(){};
	virtual ~Muller(){};

	/*template<class T>
	void findZeros(polynomial<T> pol){

	}*/

	void findZeros(double px0, double pd, double pe, int pn){
		x0 = px0;
		e = pe;
		d = pd;
		n = pn;
		Mueller();
		cout << "Valor X Calculado: " << x << endl;
		cout << "is complex: " << isComplex << endl;
		cout << "Valor Y Asociado: " << Y(x) << endl;
		cout << "Numero de Pasos: " << k << endl;
	}

	void Mueller() {
		//Labels: e100,e200
	  double a1,b,c1,d1,e1,e2,e3,x1,x2,x3,xl,xl1;
	  // Set up the three evaluation points
	  k=1; x3=x0; x1=x3-d; x2=x3+d;
	  // Calculate Mueller parameters and guard against divide by zero
	  if (x2-x1==0) x2=x2*1.0000001;
	e100: if (x2-x1==0) x2=x2+0.0000001;
	  xl1=(x3-x2)/(x2-x1);
	  d1=(x3-x1)/(x2-x1);
	  if (k>1) goto e200;
	  // Get values of function
	  e1=Y(x1); e2=Y(x2);
	e200: e3=Y(x3);
	  a1=xl1*xl1*e1-d1*d1*e2+(xl1+d1)*e3;
	  c1=xl1*(xl1*e1-d1*e2+e3);
	  b=a1*a1-4.0*d1*c1*e3;
	  // Test for complex root, meaning the parabola is inverted
	  if (b<0){
		  b=0.0;
		  isComplex = true;
	  }
	  // Choose closest root
	  if (a1<0) a1=a1-sqrt(b);
	  if (a1>0) a1=a1+sqrt(b);
	  // Guard against divide by zero
	  if (a1==0) a1=1e-7;
	  xl=-2.0*d1*e3/a1;
	  // Calculate next estimate
	  x=x3+xl*(x3-x2);
	  // Test for convergence
	  if (fabs(x-x3)<e) return;
	  // Test for number of iterations
	  if (k>=n) return;
	  // Otherwise, make another pass
	  k++;
	  // Some saving
	  x1=x2; x2=x3; x3=x; e1=e2; e2=e3;
	  goto e100;
	} // Mueller()


private:
	//***************************************************
	//  Function subroutine
	double  Y(double  x) {
	  //return (x-2)*(x*x+4)*(x+1);
		//return (x+1)*(x+1)*(x+1)*(x+1)*(x+1);
		return (x*x) + (2*x) + 3 ;
	}
};



#endif /* SRC_MULLER_H_ */
