/*
 * Pol.h
 *
 *  Created on: Mar 27, 2017
 *      Author: abrahamon
 */

#ifndef POL_H_
#define POL_H_

class Pol {
public:
	Pol();
	virtual ~Pol();
	
	template<class T>
	void print_pol(polynomial<T> pol){
		for(int i=0;i<=pol.degree();i++){
			cout<<"+ "<<pol[i]<<"x^"<<i;
		}
		cout<<"\n";
	}
	
	template<class T>
	polynomial<T> divide( const polynomial<T>& n_t,
						const polynomial<T>&D,
						polynomial<T>& r){ //dividendo, divisor, residuo, return coeficiente. N/D=q N%D=r
		int dN = n_t.degree();//Degree of the vectors
		int dD = D.degree();
		int dr = dN - dD;
		int dq = dN - dD;
		int dd = dD;
		int unsigned i; //Iterator
		r = n_t;
		polynomial<T>N = n_t;
		polynomial<T>d = N;
		polynomial<T>q = N;
		for(i=0;i<dD;i++){
			q[i]=0;
			r[i]=0;
			d[i]=0;
		}
		if( dN >= dD ) {
			while(dN >= dD) {// d equals D shifted right
				for( i = 0 ; i < dN + 1 ; i++ ) {
					d[i] = 0;
				}
				for( i = 0 ; i < dD + 1 ; i++ ) {
					d[i+dN-dD] = D[i];
				}
				dd = dN;
				q[dN-dD] = N[dN]/d[dd];
				for( i = 0 ; i < dq + 1 ; i++ ) {
					d[i] = d[i] * q[dN-dD];
				}
				N=N-d;
				dN--;
			}
		}
		dr = dN;
		r=N;
		for(i=N.degree();i<=N.degree();i++){
			q[i]=0;
			r[i]=0;
		}
		return q;
	}

};

#endif /* POL_H_ */
