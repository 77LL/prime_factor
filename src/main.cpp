#include "Solver.h"

#include <iostream>
#include <vector>
#include <utility>
#include <chrono>
#include <cmath>

using namespace std;

template<class T>
class Div : public Solver<T> {
public:
	void solve(T num){
		for( T n=num, p=2; n > 1; p++ ){
			T cnt = 0;
			for( ; n%p == 0; cnt++ ){
				n /= p;
			}
			if( cnt == 0 ) continue;
			this->result.push_back(make_pair(p, cnt));
		}
	}
};

template<class T>
class DivSqrt : public Solver<T> {
public:
	void solve(T num){
		T n = num;
		for( T p=2; n > 1 && p < static_cast<T>(sqrt(num))+1; p++ ){
			T cnt = 0;
			for( ; n%p == 0; cnt++ ){
				n /= p;
			}
			if( cnt == 0 ) continue;
			this->result.push_back(make_pair(p, cnt));
		}
		if( n != 1 ){
			this->result.push_back(make_pair(n, 1));
		}
	}
};

template<class T>
class DivPrim : public Solver<T> {
public:
	void solve(T num){
		T snum = static_cast<T>(sqrt(num))+1;
		createPrimList(snum);
		T n = num;
		for( T n=num, p=2; n > 1 && p < snum; p++ ){
			if( !plist[p] ) continue;
			T cnt = 0;
			for( ; n%p == 0; cnt++ ){
				n /= p;
			}
			if( cnt == 0 ) continue;
			this->result.push_back(make_pair(p, cnt));
		}
		if( n != 1 ){
			this->result.push_back(make_pair(n, 1));
		}
	}

private:
	void createPrimList(T num){
		plist.resize(num, true);
		for( T i=4; i<num; i+=2 ) plist[i] = false;
		for( T i=3; i<num; i+=2 ){
			for( T j=i; j*i <= num; j++ ){
				plist[j*i] =  false;
			}
		}
	}

	vector<bool> plist;
};

typedef long long type;
template<class T>
void output(T sol, type num){
	sol.calc(num);
	sol.show(cout);
	sol.showTime(cout);
}

int main(int argc, char *argv[])
{
	vector<type> list = {12345,  1000000007, 5368709120, 12345678987654321};
	for( auto &val : list ){
		cout << "num: " << val << endl;
		output( Div<type>(), val );
		output( DivSqrt<type>(), val );
		output( DivPrim<type>(), val );
		cout << endl;
	}

	return 0;
}
