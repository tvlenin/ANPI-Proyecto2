#include "Muller.h"
#include "Laguerre.h"
#include "TestFramework.h"
#include <iostream>
#include <complex>
#include <boost/math/tools/polynomial.hpp>

using namespace boost::math::tools; // for polynomial
using namespace std;


int main() {
	//cout << std::setprecision(10) << endl;


	TestFramework* testF = new TestFramework();
	Muller* m = new Muller();
	Laguerre* g = new Laguerre();

	//complex<double> z(0,0);
	double z = 0;

	//polynomial<complex<double>> Polinomio{{-60.0,-23.0,2.0,1.0}};		 	//3 Raices Reales
	polynomial<double> Polinomio{{-60.0,-23.0,2.0,1.0}};		 			//3 Raices Reales

	//polynomial<complex<double>> Polinomio{{36.0,-36.0,13.0,-4.0,1.0}}; 	//Raices Reales y Complejas
	//polynomial<complex<double>> Polinomio{{36.0,-36.0,13.0,-4.0,1.0}}; 	//Raices Reales y Complejas

	//polynomial<complex<double>> Polinomio{{-8.0,-4.0,2.0,-1.0,1.0}}; 		//Pablo's Pol
	//polynomial<double> Polinomio{{-8.0,-4.0,2.0,-1.0,1.0}}; 				//Pablo's Pol


	cout<<"### Muller ###"<<endl;
	//testF->testTime(m,Polinomio,z);
	testF->testIterations(m,Polinomio,z);
	cout<<"### #### ###"<<endl;
	cout<<endl;

	cout<<"### Laguerre ###"<<endl;
	//testF->testTime(g,Polinomio,z);
	//testF->testIterations(g,Polinomio,z);
	cout<<"### #### ###"<<endl;
	cout<<endl;



	//g->calc_Laguerre(Polinomio);

  return 0;
}
// End of file Mueller.cpp
