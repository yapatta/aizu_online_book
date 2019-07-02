#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed
main(){
		int N;
		cin >> N;
		vector<ll> a(N+1);
		for(int i=0;i<N;i++){
				cin >> a[i] >> a[i+1];
		}
	
		vector<vector<ll> > m(N+1, vector<ll>(N+1,INT_MAX));

		for(int i=0;i<=N;i++)
				m[i][i] = 0;
		for(int i=0;i<N;i++)
				m[i][i+1] = 0;


		for(int sa=2;sa<=N;sa++){
				for(int b=0;b<=N-sa;b++){
						int e = b + sa;
						for(int med=b;med<=e;med++){
								m[b][e] = min(m[b][e], m[b][med] + m[med][e] + a[b]*a[med]*a[e]);
						}
				}
		}
		cout << m[0][N] << endl;

}
