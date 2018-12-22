#include <iostream>
#include <vector>
#include <utility>
#include <chrono>

using namespace std;

template<class T>
class Solver {
public:
	virtual void solve(T num) =  0;
	void calc(T num){
		chrono::system_clock::time_point start, end;

    start = chrono::system_clock::now();
		solve(num);
		end = chrono::system_clock::now();

		time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) * 0.000001;
	}
	void show(ostream& os){
		for( auto &val : result ){
			os << "prim: " << val.first << ", order: " << val.second << endl;
		}
	}
	void showTime(ostream& os){
		os << "time: " << time << "[s]" << endl;
	}

protected:
	vector< pair< T, T > > result;
	double time;
};

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
int main(int argc, char *argv[])
{
	type N;
	cin >> N;

	Div1<type> sol1;

	sol1.calc(N);
	sol1.show(cout);
	sol1.showTime(cout);

	return 0;
}
