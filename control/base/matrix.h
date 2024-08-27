#ifndef __BASE_Matrix_H__
#define __BASE_Matrix_H__

#include <vector>
#include <cassert>
//#include "../../test/sprintf.h"
//
using namespace std;

template <typename T>
class Matrix {
	/* define Matrix<T> */
	public:
        	int r, c;

	public:

        	vector<vector<T>> mtx;  	

		vector<T> operator[](int i) const { return mtx[i]; };

		void concatenate_r(Matrix<T>&); // join Matrix<T> according to row,  return this point
	        void concatenate_c(Matrix<T>&); // join Matrix<T> according to col,  return this point	
		Matrix<T>& concatenate_eye(Matrix<T>&);
		Matrix<T> transpose();
		Matrix<T> inverse();

		/* get param */
		int size_r() const { return mtx.size(); };
		int size_c() const { return mtx[0].size(); };      	


		/* operator function */
		friend Matrix<T> operator+(const Matrix<T>& ad, const Matrix<T>& au) {
                	Matrix<T> sum(ad.r,ad.c);
			
                //	assert(this -> c == au.c && this -> r == au.r);
		        assert(ad.c == au.c && ad.r == au.r);
 
                	for(int i = 0; i < au.r; i++) {
	                	for(int j = 0; j < au.c; j++) {
			                sum.mtx[i][j] = ad[i][j] + au[i][j];
                 		//	this -> mtx[i][j] = this -> mtx[i][j] +  au[i][j];
	                 	}
                	}

                	return sum;
                };

		friend Matrix<T> operator-(const Matrix<T>& ad, const Matrix<T>& au) {
                	Matrix<T> sum(ad.r, ad.c);

                        assert(ad.c == au.c && ad.r == au.r);

                        for(int i = 0; i < ad.r; i++) {
                                for(int j = 0; j < ad.c; j++) {
                                        sum.mtx[i][j] = ad[i][j] - au[i][j];
                                }
                        }

                        return sum;
                };

		friend Matrix<T> operator*(const Matrix<T>& ad, const Matrix<T>& au) {
                	Matrix<T> mul(ad.r, au.c);

                	assert(ad.c == au.r);

                 	for(int i = 0; i < ad.r; i++){
                		for(int j = 0; j < au.c; j++){
                 			for(int k = 0; k < au.r; k++){
	                  			mul.mtx[i][j] = mul.mtx[i][j] + ad[i][k] * au[k][j];
	                     		}
                     		}
                 	}

                  	return mul;

                };

        	Matrix<T>& operator=(const Matrix<T>& ad) {

                   	assert(this -> c == ad.c && this -> r == ad.r);

                        for(int i = 0; i < r; i++) {
                                for(int j = 0; j < c; j++) {
                                        this -> mtx[i][j] = ad[i][j];
                                }
                        }

                        return *this;

                };


		Matrix(): r(1), c(1), mtx(r, vector<T>(c)) {};
		Matrix(int r): r(r), c(r), mtx(r, vector<T>(c)) {};
		Matrix(int r, int c): r(r), c(c), mtx(r, vector<T>(c)) {};

		Matrix(int r, int c, T d): r(r), c(c), mtx(r, vector<T>(c)) {

			if(r == c) {
			for(int i = 0; i < r; i++) {
                                for(int j = 0; j < r; j++) {
                                        if(i == j) {
                                                mtx[i][j] = d;
                                        }
                                        else {
                                                mtx[i][j] = 0;
                                        }
                                }
                        }
			}
			else {
				for(int i = 0; i < r; i++) {
                                for(int j = 0; j < c; j++) {
                                        
					mtx[i][j] = d;
                                }
				}
			}

		};
		
		Matrix(int r, vector<T>& data): r(r), c(r), mtx(r, vector<T>(c)) {

			for(int i = 0; i < r; i++) {
				for(int j = 0; j < r; j++) {
					if(i == j) {
						mtx[i][j] = data[i];
					}
					else {
						mtx[i][j] = 0;
					}
				}
			}

		};

	        Matrix(const Matrix<T> &m) : r(m.r), c(m.c), mtx(r, vector<T>(c)) {

        for(int i = 0; i < r; i++) {
	        for(int j = 0; j < c; j++) {
		        mtx[i][j] = m[i][j];
		}
	}	
};;

		~Matrix() {};
};



#endif
