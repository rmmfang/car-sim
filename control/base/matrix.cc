#include "matrix.h"
#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>
//#include "../../test/sprintf.h"

using namespace std;



template <typename T>
void
Matrix<T>::concatenate_r(Matrix<T>& ap) {

	assert(c == ap.size_c());
        
//	cout << "mtx_r = " << mtx.size() << endl;
	for(int i = 0; i < ap.r; i++) {

		mtx.push_back(ap[i]);
	//	cout << mtx.size() << endl;
	}

	r = mtx.size();

}

template <typename T>
void
Matrix<T>::concatenate_c(Matrix<T>& ap) {

        assert(this -> r == ap.size_r());
	vector<T> a =  {1,1,1,1,1};
	typename vector<T>::iterator it = ap[0].end();
        for(int i = 0; i < ap.size_r(); i++) {

		/* err record: if use ap[i].begin() to insert into mtx, there will be err
		 * 'terminate called after ...', because the operator[] return a temporary variable,
		 * we need to redefine it */
		vector<T> a = ap[i];
	       	mtx[i].insert(mtx[i].end(), a.begin(), a.end());

        }

	c = mtx[0].size();
}

template <typename T>
Matrix<T>&
Matrix<T>::concatenate_eye(Matrix<T>& ap) {

	int ar = ap.r, ac = ap.c;
	vector<T> cp(ac, 0);
	vector<T> rp(this -> c, 0);

        for(int i = 0; i < r; i++) {
                        this -> mtx[i].insert(this -> mtx[i].end(), cp.begin(), cp.end());
        }

	for(int i = 0; i < ar; i++) {
		this -> mtx.push_back(rp);
	}

	for(int i = r; i < r + ar; i++) {
		vector<T> a = ap[i - r];
		this -> mtx[i].insert(this -> mtx[i].end(), a.begin(), a.end());
	}

	c = mtx[0].size();
	r = mtx.size();

        return *this;
}

template <typename T>
Matrix<T>
Matrix<T>::transpose() {

	Matrix<T> Tm(c,r);

	for(int i = 0; i < c; i++) {
		for(int j = 0; j < r; j++) {
			Tm[i][j] = mtx[j][i];
		}
	}

	return Tm;
}


template <typename T>
Matrix<T>
Matrix<T>::inverse() {

	Matrix<T> b(r,c,1.0);
        Matrix<T> t = *this;
	float max, temp;
	int i,j,k;
        if (t.r != t.c)
        {
                cout << "uninversable" << endl;
        }

        int N = t.size_r();

	for(int i = 0; i < N; i++) {
		
		max = t[i][i];
		k = i;
		
		for (j = i + 1; j < N; j++)
		{
			if (fabs(t[j][i]) > fabs(max))
			{
				max = t[j][i];
				k = j;
			}
		}
		//cout<<"the max number is "<<max<<endl;

		if (k != i)
		{
			// 进行行交换
			for (j = 0; j < N; j++)
			{
				temp = t[i][j];
				t.mtx[i][j] = t[k][j];
				t.mtx[k][j] = temp;
				// 伴随矩阵B也要进行行交换
				temp = b.mtx[i][j];
				b.mtx[i][j] = b.mtx[k][j];
				b.mtx[k][j] = temp;
			}
		}
		if (t.mtx[i][i] == 0)
		{
			cout << "\nthe matrix does not exist inverse matrix\n";
			break;
		}
		// 获取列主元素
		temp = t[i][i];
		// diag the main element
		//cout<<"\nthe temp is "<<temp<<endl;
		for (j = 0; j < N; j++)
		{
			t.mtx[i][j] = t.mtx[i][j] / temp;
			b.mtx[i][j] = b.mtx[i][j] / temp;
	 	}
		for (j = 0; j < N; j++)
		{
			if (j != i)
			{
				temp = t[j][i];
				//消去该列的其他元素
				for (k = 0; k < N; k++)
				{
					t.mtx[j][k] = t.mtx[j][k] - temp * t.mtx[i][k];
					b.mtx[j][k] = b.mtx[j][k] - temp * b.mtx[i][k];

//					cout << b[j][k] << " ";
				}
			}
 
		}
	}

	return b;
}

template class Matrix<int>;
template class Matrix<float>;

