
#include "Muller.h"
#include "Laguerre.h"
#include <iostream>
#include <boost/math/tools/polynomial.hpp>
#include <complex>

//using namespace boost::math::tools; // for polynomial
using namespace std;
using namespace boost::math::tools;


int main() {
	//cout << std::setprecision(10) << endl;



	//polynomial<double> const b{{4.0, 1.0,-2.0,3.0,2.0}};
  //polynomial<double> const b{{6.0,-5.0,1}};
	//polynomial<complex<double>> const b{{36.0, -27.0,-13.0,3.0,1.0}};
	//polynomial<complex<double>> b{{5.0, 1.0,1.0,1.0,1.0}};
	//polynomial<complex<double>> b{{36, -36.0,13.0,-4.0,1.0}};
	//polynomial<complex<double>> b{{-60.0, -23.0,2.0, 1.0}};
	//Laguerre *lag = new Laguerre();
	//lag->calc_Laguerre(b);

	polynomial<complex<double>> b{{-60.0, -23.0,2.0, 1.0}};
	cout<<"### Laguerre ###"<<endl;
	Laguerre *g = new Laguerre();
	g->calc_Laguerre(b);
	cout<<"### #### ###"<<endl;
	cout<<endl;


cout << "b = " <<endl;
  return 0;
}

// End of file Mueller.cpp
