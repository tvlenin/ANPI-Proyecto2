#include "Muller.h"
#include "Laguerre.h"
#include <iostream>

//using namespace boost::math::tools; // for polynomial
using namespace std;


int main() {
	//cout << std::setprecision(10) << endl;


	Muller* m = new Muller();
	Laguerre* g = new Laguerre();

	complex<double> z(0,0);

	//polynomial<complex<double>> Polinomio{{-8.0,-4.0,2.0,-1.0,1.0}}; //Pablo's Pol

	polynomial<complex<double>> Polinomio{{-60.0,-23.0,2.0,1.0}};		 //3 Raices Reales

	//polynomial<complex<double>> Polinomio{{36.0,-36.0,13.0,-4.0,1.0}}; //Raices Reales y Complejas

	cout<<"### Muller ###"<<endl;
	m->findZeros(z,1,0.00000001,10000,Polinomio);
	cout<<"### #### ###"<<endl;
	cout<<endl;

	cout<<"### Laguerre ###"<<endl;
	g->calc_Laguerre(Polinomio);
	cout<<"### #### ###"<<endl;
	cout<<endl;

  return 0;
}

// End of file Mueller.cpp

