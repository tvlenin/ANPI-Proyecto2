/*
 * Laguerre.h
 *
 *  Created on: Mar 27, 2017
 *      Author: tvlenin
 */

#ifndef SRC_LAGUERRE_H_
#define SRC_LAGUERRE_H_

#include <stdio.h>
#include "Pol.h"
#include <cmath>
#include <boost/math/tools/polynomial.hpp>
#include <iostream>
#include <complex>

using namespace boost::math::tools;
using namespace std;

class Laguerre{
public:
	Laguerre(){};
	int calc_Laguerre();
	virtual ~Laguerre(){};

	template<class T>
	void print_pol(polynomial<T> pol){
		for(int i=0;i<=pol.degree();i++){
			cout<<"+ "<<pol[i]<<"x^"<<i;
		}
		cout<<"\n";
	}
template <class T>
	polynomial<T> derive( polynomial<T> poly){
		polynomial<T> fd = poly;
		double n = poly.degree();
		T comp = 0;
		for(double i = 0; i < n; i++){// calcula la primera derivada
			if(i == 0){
				fd[0] = poly[1];
			}
			else if(i+1 == n){
				fd[i] = poly[i+1]*(i+1);
				fd[i+1] = comp;
			}
			else
				fd[i] = poly[i+1]*(i+1);

		}
		return fd;

	}

template <class T>
	polynomial<complex<T>> derive( polynomial<complex<T>> poly){
	polynomial<complex<T>> fd = poly;
		double n = poly.degree();
		complex<T> comp (0,0);
		for(double i = 0; i < n; i++){// calcula la primera derivada
			if(i == 0){
				fd[0] = poly[1];
			}
			else if(i+1 == n){
				fd[i] = poly[i+1]*(i+1);
				fd[i+1] = comp;
			}
			else
				fd[i] = poly[i+1]*(i+1);

		}
		return fd;

	}

	template<class T>
	T zero (polynomial<T>  poly,polynomial<T>  fd,polynomial<T>  sd){
		double m = poly.degree();
		T x;
		bool flag ;
		T G;
		T H;
		T a1;
		T a2;
		T comp = 0;
	 x=comp;
	 flag = true;

	 while(flag){
		 G = fd.evaluate(x)/poly.evaluate(x);
		 H = pow(G,2)-((sd.evaluate(x)/poly.evaluate(x)));
		 a1 = m / (G + sqrt((m-1)*(m*H-pow(G,2))));
		 a2 = m / (G - sqrt((m-1)*(m*H-pow(G,2))));
		 //cout<<"a1 : "<<a1<<endl;
		 //cout<<"a2 : "<<a2<<endl;
		 if (norm(a1) == norm(a1) && norm(a2) == norm(a2)){
			 if (min(norm(a1),norm(a2)) < 0.000000001 )
				 flag = false;
			 else if(norm(a1)>norm(a2))
				 x -= a2;
			 else
				 x -= a1;
		 }
		 else{
			 flag = false;
		 }
	 }
	 return x;

	}


	template<class T>
	complex<T> zero (polynomial<complex<T>>  poly,polynomial<complex<T>>  fd,polynomial<complex<T>>  sd){
			double m = poly.degree();
			complex<T> x;
			bool flag ;
			complex<T> G;
			complex<T> H;
			complex<T> a1;
			complex<T> a2;
			complex<T> comp (0,0);
		 x=comp;
		 flag = true;

		 while(flag){
			 G = fd.evaluate(x)/poly.evaluate(x);
			 H = pow(G,2)-((sd.evaluate(x)/poly.evaluate(x)));
			 a1 = m / (G + sqrt((m-1)*(m*H-pow(G,2))));
			 a2 = m / (G - sqrt((m-1)*(m*H-pow(G,2))));
			 //cout<<"a1 : "<<a1<<endl;
			 //cout<<"a2 : "<<a2<<endl;
			 if (norm(a1) == norm(a1) && norm(a2) == norm(a2)){
				 if (min(norm(a1),norm(a2)) < 0.000000001 )
					 flag = false;
				 else if(norm(a1)>norm(a2))
					 x -= a2;
				 else
					 x -= a1;
			 }
			 else{
				 flag = false;
			 }
		 }
		 return x;

		}




	template <class T>
	int calc_Laguerre(polynomial<T>  poly) {

		Pol *pol = new Pol();
		int cont = poly.degree();
		polynomial<T> fd;
		polynomial<T> sd;
		T x;
		while (cont > 0){
			fd = derive(poly);
			sd = derive(fd);
			x = zero(poly,fd,sd);
			 cout<<"un cero es : "<<x<<endl;
			 polynomial<T> raiz{{-x,1.0}};
			 polynomial<T> residuo{{0.0,0.0, 0.0,0.0}};
			 poly = pol->divide(poly,raiz,residuo);
			 cont--;
		}
		cout<<"Fin"<<endl;
		return 0;
	}

	template <class T>
	int calc_Laguerre(polynomial<complex<T>>  poly) {

		Pol *pol = new Pol();
		int cont = poly.degree();
		polynomial<complex<T>> fd;
		polynomial<complex<T>> sd;
		complex<T> x;
		while (cont > 0){
			fd = derive(poly);
			sd = derive(fd);
			x = zero(poly,fd,sd);
			 cout<<"un cero es : "<<x<<endl;
			 polynomial<complex<T>> raiz{{-x,1.0}};
			 polynomial<complex<T>> residuo{{0.0,0.0, 0.0,0.0}};
			 poly = pol->divide(poly,raiz,residuo);
			 cont--;
		}
		cout<<"Fin"<<endl;
		return 0;
	}
};



#endif /* SRC_LAGUERRE_H_ */
