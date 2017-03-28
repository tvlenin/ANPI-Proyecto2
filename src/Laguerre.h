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

// global variables


class Laguerre{
public:
	Laguerre(){};
	int calc_Laguerre();
	//virtual ~Laguerre(){};
/*
	template<class T>
	void print_pol(polynomial<T> pol){
		for(int i=0;i<=pol.degree();i++){
			cout<<"+ "<<pol[i]<<"x^"<<i;
		}
		cout<<"\n";
	}*/


	template <class T>
	int calc_Laguerre(polynomial<T>  poly) {
		double m = poly.degree();
		int n = m+1;
		Pol *pol = new Pol();
		int cont = m;
		polynomial<T>  fd;
		polynomial<T>  sd;
		T x;
		bool flag ;
		for (int j = 0; j < m ;j++){
		//while (cont != 0){
			cout<<m<<endl;

			fd= poly;
			sd= poly;
			for(double i = 0; i < n; i++){// calcula la primera derivada
				if(i == 1)
					fd[0] = poly[1];
				if(i == n-1){
					fd[i-1] = poly[i]*i;
					fd[n-1] = 0;
				}
				else
					fd[i-1] = poly[i]*i;
			}
			for(double i = 0; i < n; i++){//calcula la segunda derivada
				if(i == 2){
					sd[0] = fd[1];
				}
				if(i == n-1){
					sd[i-1] = fd[i]*i;
					sd[n-1] = 0;
					sd[n-2] = 0;
				}
				else
					sd[i-1] = fd[i]*i;
			}


		 	x=0;
		 	flag = true;
		 	while(flag){
		 	//for (int i = 0; i < 10 ; i++){
		 	//cout<<"x : "<<x<<endl;
		 	T G = fd.evaluate(x)/poly.evaluate(x);
	 	 	T H = pow(G,2)-((sd.evaluate(x)/poly.evaluate(x)));
	 	 	T a1 = m / (G + sqrt((m-1)*(m*H-pow(G,2))));
	 	 	T a2 = m / (G - sqrt((m-1)*(m*H-pow(G,2))));
		 	//cout<<"a1 : "<<a1<<endl;
		 	//cout<<"a2 : "<<a2<<endl;
		 	if (norm(a1) == norm(a1) && norm(a2) == norm(a2)){
			 	if (min(norm(a1),norm(a2)) < 0.000000001 )
			 	 	flag = false;
			 	else if(norm(a1)>norm(a2))
			 		x -= a2;
			 	else
			 	  x -= a1;
			}else
				flag =false;
		}


	 cout<<"un cero es : "<<x<<endl;
   polynomial<T> raiz{{-x,1.0}};
   polynomial<T> residuo{{0.0,0.0, 0.0,0.0}};
	poly = pol->divide(poly,raiz,residuo);
	 //cont--;

	}
	cout<<"Fin de la vara "<<endl;

return 0;
}


private:

};



#endif /* SRC_LAGUERRE_H_ */
