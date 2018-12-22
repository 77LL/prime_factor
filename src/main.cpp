#include "Solver.h"

#include <iostream>
#include <vector>
#include <utility>
#include <chrono>

using namespace std;

template<class T>
class Div1 : public Solver<T> {
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
		output( Div1<type>(), val );
		cout << endl;
	}

	return 0;
}
