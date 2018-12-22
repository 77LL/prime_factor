#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<class T>
class Solver {
public:
	virtual void calc(T num) =  0;
	void show(ostream& os){
		for( auto &val : result ){
			os << "prim: " << val.first << ", order: " << val.second << endl;
		}
	}

protected:
	vector< pair< T, T > > result;
};

template<class T>
class Div1 : public Solver<T> {
public:
	Div1(T num){ calc(num); }

	void calc(T num){
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
int main(int argc, char *argv[])
{
	type N;
	cin >> N;

	Div1<type> sol1(N);
	sol1.show(cout);

	return 0;
}
