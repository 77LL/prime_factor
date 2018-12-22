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
