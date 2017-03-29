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
#include <typeinfo>
#include "Pol.h"
#include "BoolHolder.h"

using namespace boost::math::tools; // for polynomial
using namespace std;



class Muller{
public:
	Muller(){};
	virtual ~Muller(){};


	template<class T>
	void findZeros(complex<T> px0, polynomial<complex<T>> Polinomio){
		findZerosAux(px0,Polinomio,false);
	}

	template<class T>
	void findZeros(T px0,polynomial<T> Polinomio){
		findZerosAux(px0,Polinomio,false);
	}


	template<class T>
	void findZerosAux(complex<T> px0, polynomial<complex<T>> Polinomio,bool iterationsPrint){
		Pol* zpol = new Pol();
		px0.real(px0.real()+1);
		double pd = 2;			//Scope for first 3 guesses
		double pe = 0.00000001; //Max Error Allowed
		int pn = 1000;			//Max number of iterations

		int polDegree = Polinomio.degree();

		complex<T> x;

		for(int i = 0; i < polDegree; i++){
			cout<<endl;
			if(i+1 == polDegree){
				x = -Polinomio[0];
				if(abs(x.real()) < 0.000001)
					x.real(0);
				if(abs(x.imag()) < 0.000001)
					x.imag(0);
				cout<<"Raíz: "<<i <<": " << x << endl;
				break;
			}

			x = calculateZero(px0,pd,pe,pn,Polinomio,iterationsPrint);
			if(abs(x.real()) < 0.000001)
				x.real(0);
			if(abs(x.imag()) < 0.000001)
				x.imag(0);

			cout << "Raíz "<< i << ": " << x << endl;
			polynomial<complex<T>> raiz{{-x,1.0}};
			polynomial<complex<T>> residuo{{0.0,0.0, 0.0,0.0}};
			Polinomio = zpol->divide(Polinomio,raiz,residuo);
		}
	}



	template<class T>
	void findZerosAux(T px0,polynomial<T> Polinomio,bool iterationsPrint){
		Pol* zpol = new Pol();
		px0++;
		double pd = 2;			//Scope for first 3 guesses
		double pe = 0.00000001; //Max Error Allowed
		int pn = 1000;			//Max number of iterations

		int polDegree = Polinomio.degree();

		T x;
		BoolHolder* hasComplexRoot = new BoolHolder(false);

		for(int i = 0; i < polDegree; i++){
			cout<<endl;
			if(i+1 == polDegree){
				x = -Polinomio[0];
				cout<<"Raíz: "<<i <<": " << x << endl;
				break;
			}

			x = calculateRealZero(px0,pd,pe,pn,Polinomio,hasComplexRoot,iterationsPrint);
			if(hasComplexRoot->GetState() == true){
				cout << "Error: The Polynomial has complex roots. Please, user complex<T> instead." <<endl;
				return;
			}
			cout << "Raíz "<< i << ": " << x << endl;
			polynomial<T> raiz{{-x,1.0}};
			polynomial<T> residuo{{0.0,0.0, 0.0,0.0}};
			Polinomio = zpol->divide(Polinomio,raiz,residuo);
		}
	}



	template<class T>
	T calculateZero(T px0, double pd, double pe, int pn,polynomial<T> Y,bool iterationsPrint) {
		T constA1(1.0000001,0);
		T constA2(0.0000001,0);
		T const4(4,0);
		T const2(-2,0);

		int k,n;
		T d,e,x,x0;
		T a1,b,c1,d1,e1,e2,e3,x1,x2,x3,xl,xl1;

		x0 = px0;
		e = pe;
		d = pd;
		n = pn;


		// Set up the three evaluation points
		k=1; x3=x0; x1=x3-d; x2=x3+d;
		// Calculate Mueller parameters and guard against divide by zero
		if (norm(x2-x1)==0)
			x2=x2*constA1;
		e100:
		if (norm(x2-x1)==0)
			x2=x2+constA2;

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
		b=a1*a1-const4*d1*c1*e3;

		// Test for complex root, meaning the parabola is inverted
		if (norm(b)<0){
			b=0.0;
		}
		// Choose closest root
		if (norm(a1)<0) a1=a1-sqrt(b);
		if (norm(a1)>0) a1=a1+sqrt(b);
		// Guard against divide by zero
		if (norm(a1)==0) a1=1e-7;
		xl=const2*d1*e3/a1;
		// Calculate next estimate
		x=x3+xl*(x3-x2);
		// Test for convergence
		if (norm(x-x3)<norm(e)){
			if(iterationsPrint == true)
				cout << "Number of Iterations: "<<k<<endl;
			return x;
		}
		// Test for number of iterations
		if (k>=n){
			if(iterationsPrint == true)
				cout << "Number of Iterations: "<<k<<endl;
			return x;
		}
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
	}

	template<class T>
	T calculateRealZero(T px0, double pd, double pe, int pn,polynomial<T> Y, BoolHolder* complex,bool iterationsPrint){
		int k,n;
		T d,e,x,x0;
		T a1,b,c1,d1,e1,e2,e3,x1,x2,x3,xl,xl1;

		x0 = px0;
		e = pe;
		d = pd;
		n = pn;

		// Set up the three evaluation points
		k=1; x3=x0; x1=x3-d; x2=x3+d;
		// Calculate Mueller parameters and guard against divide by zero
		if (x2-x1==0)
			x2=x2*1.0000001;
		e100:
		if (x2-x1==0)
			x2=x2+0.0000001;

		xl1=(x3-x2)/(x2-x1);
		d1=(x3-x1)/(x2-x1);
		if (k>1)
			goto e200;

		// Get values of function
		e1=Y.evaluate(x1); e2=Y.evaluate(x2);
		e200:
		e3=Y.evaluate(x3);
		a1=xl1*xl1*e1-d1*d1*e2+(xl1+d1)*e3;
		c1=xl1*(xl1*e1-d1*e2+e3);
		b=a1*a1-4.0*d1*c1*e3;

		// Test for complex root, meaning the parabola is inverted
		if (b<0){
			complex->SetState(true);
			return 0;
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
		if (fabs(x-x3)<e){
			if(iterationsPrint == true)
				cout << "Number of Iterations: "<<k<<endl;
			return x;
		}
		// Test for number of iterations
		if (k>=n){
			if(iterationsPrint == true)
				cout << "Number of Iterations: "<<k<<endl;
			return x;
		}
		// Otherwise, make another pass
		k++;
		// Some saving
		x1=x2; x2=x3; x3=x; e1=e2; e2=e3;
		goto e100;
	}


};



#endif /* SRC_MULLER_H_ */
