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
#include "Pol.h"

using namespace boost::math::tools; // for polynomial
using namespace std;



class Muller{
public:
	Muller(){};
	virtual ~Muller(){};

	/*template<class T>
	void findZeros(polynomial<T> pol){

	}*/

	void findZeros(complex<double> px0, double pd, double pe, int pn){
		Pol* zpol = new Pol();



		//polynomial<complex<double>> Polinomio{{-1.0,1.0, 1.0,1.0}};

		polynomial<complex<double>> Polinomio{{5.0,1.0, 1.0,1.0,1.0}};


		int polDegree = Polinomio.degree();

		complex<double> x;
		for(int i = 0; i < polDegree-1; i++){
			x = calculateZero(px0,pd,pe,pn,Polinomio);
			cout << "Raíz "<< i << ": " << x << endl;
			polynomial<complex<double>> raiz{{-x,1.0}};
			polynomial<complex<double>> residuo{{0.0,0.0, 0.0,0.0}};
			Polinomio = zpol->divide(Polinomio,raiz,residuo);
		}

		cout<< "Raiz: " << polDegree-1 << " " << -Polinomio[0] << endl;
		/*
		zpol->print_pol(Polinomio);
		complex<double> x = calculateZero(px0,pd,pe,pn,Polinomio);
		cout << "Raíz "<< 1 << ": " << x << endl;
		polynomial<complex<double>> raiz{{-x,1.0}};
		polynomial<complex<double>> residuo{{0.0,0.0, 0.0,0.0}};
		polynomial<complex<double>> result = zpol->divide(Polinomio,raiz,residuo);

		cout<<endl;

		zpol->print_pol(result);
		complex<double> x2 = calculateZero(px0,pd,pe,pn,result);
		cout << "Raíz "<< 1 << ": " << x2 << endl;
		polynomial<complex<double>> raiz2{{-x2,1.0}};
		polynomial<complex<double>> residuo2{{0.0,0.0, 0.0,0.0}};
		polynomial<complex<double>> result2 = zpol->divide(Polinomio,raiz2,residuo2);

		cout << endl;

		zpol->print_pol(result2);
		complex<double> x3 = calculateZero(px0,pd,pe,pn,result2);
		cout << "Raíz "<< 1 << ": " << x3 << endl;*/


	}

	complex<double> calculateZero(complex<double> px0, double pd, double pe, int pn,polynomial<complex<double>> Y) {
		int k,n;
		complex<double> d,e,x,x0;
		complex<double> a1,b,c1,d1,e1,e2,e3,x1,x2,x3,xl,xl1;

		x0 = px0;
		e = pe;
		d = pd;
		n = pn;


		// Set up the three evaluation points
		k=1; x3=x0; x1=x3-d; x2=x3+d;
		// Calculate Mueller parameters and guard against divide by zero
		if (norm(x2-x1)==0)
			x2=x2*1.0000001;
		e100:
		if (norm(x2-x1)==0)
			x2=x2+0.0000001;

		xl1=(x3-x2)/(x2-x1);
		d1=(x3-x1)/(x2-x1);

		if (k>1)
			goto e200;
		// Get values of function
		e1=Y.evaluate(x1);
		e2=Y.evaluate(x2);

		e200:
		e3=Y.evaluate(x3);
		a1=xl1*xl1*e1-d1*d1*e2+(xl1+d1)*e3;
		c1=xl1*(xl1*e1-d1*e2+e3);
		b=a1*a1-4.0*d1*c1*e3;

		// Test for complex root, meaning the parabola is inverted
		if (norm(b)<0){
			b=0.0;
		}
		// Choose closest root
		if (norm(a1)<0) a1=a1-sqrt(b);
		if (norm(a1)>0) a1=a1+sqrt(b);
		// Guard against divide by zero
		if (norm(a1)==0) a1=1e-7;
		xl=-2.0*d1*e3/a1;
		// Calculate next estimate
		x=x3+xl*(x3-x2);
		// Test for convergence
		if (norm(x-x3)<norm(e)) return x;
		// Test for number of iterations
		if (k>=n) return x;
		// Otherwise, make another pass
		k++;
		// Some saving
		x1=x2;
		x2=x3;
		x3=x;
		e1=e2;
		e2=e3;
		goto e100;
		return 0;
	} // Mueller()

	//polynomial<complex<double>> const Y{{-26.0,3.0,0.0, 1.0}};
};



#endif /* SRC_MULLER_H_ */
