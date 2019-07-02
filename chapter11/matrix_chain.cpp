#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e14;

signed
main(){
		int n;
		cin >> n;
		vector<ll> p(n+1);
		for(int i=0;i<n;i++)
		{
				cin >> p[i] >> p[i+1];
		}
		vector<vector<ll> > m(n+1,vector<ll>(n+1, INF));

		for(int i=1;i<=n;i++)	m[i][i] = 0;

		for(int sa=1;sa<n;sa++)
		{
				for(int fi=1;fi<=n-sa;fi++)
				{
						int la = fi + sa;
						for(int medi=fi;medi<=la-1;medi++)
						{
								m[fi][la] = min(m[fi][la],m[fi][medi] + m[medi+1][la] + p[fi-1]*p[medi]*p[la]  );
						}
						
				}
		}

		cout << m[1][n] << endl;
}
