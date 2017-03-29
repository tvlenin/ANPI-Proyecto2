/*
 * TestFramework.h
 *
 *  Created on: Mar 28, 2017
 *      Author: fasm22
 */

#ifndef SRC_TESTFRAMEWORK_H_
#define SRC_TESTFRAMEWORK_H_

#include <boost/math/tools/polynomial.hpp>
#include <complex>
#include <chrono>
#include <iostream>

using namespace boost::math::tools; // for polynomial
using namespace std;

class TestFramework{
public:
	TestFramework(){};
	virtual ~TestFramework(){};

	template<class F, class T>
	void testTime(F* pMethod, polynomial<T> pPoly, T initGuess){
		streambuf* orig_buf = cout.rdbuf();	//Retrieves cout buffer
		cout.rdbuf(NULL);					//Stops buffer output
		double numTests = 100;

		auto start = chrono::high_resolution_clock::now();
		for(double i = 0; i < numTests; i++){
			pMethod->findZeros(initGuess,pPoly);
		}
		auto end = chrono::high_resolution_clock::now();
		auto us = chrono::duration_cast<chrono::microseconds>(end-start).count();

		cout.rdbuf(orig_buf);				//Restores cout buffer
		pMethod->findZeros(initGuess,pPoly);
		cout<< endl;
		cout<< "Average Execution Time: " << static_cast<double>(us)/numTests << "us"<<endl;
		cout<< "Number of Tests: " << numTests << endl;
	}

	template<class F, class T>
	void testIterations(F* pMethod, polynomial<T> pPoly, T initGuess){
		pMethod->findZerosAux(initGuess,pPoly,true);
	}
};



#endif /* SRC_TESTFRAMEWORK_H_ */
