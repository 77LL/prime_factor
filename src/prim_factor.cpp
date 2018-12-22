// プロコン用シンプル版
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;

ll N = 123456789;

int main(int argc, char *argv[])
{
	vector< pair<ll,ll> > pf;
	ll n = N;

	for( ll p=2; n > 1 && p*p <= n; p++ ){
		ll cnt = 0;
		for( ; n%p == 0; cnt++ ){
			n /= p;
		}
		if( cnt == 0 ) continue;
		pf.push_back(make_pair(p, cnt));
	}
	if( n != 1 ){
		pf.push_back(make_pair(n, 1));
	}

	for( auto &val : pf ){
		cout << "prim: " << val.first << ", order: " << val.second << endl;
	}
}
