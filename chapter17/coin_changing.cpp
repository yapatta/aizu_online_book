#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(ll (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(ll (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define Rall(a) (a).rbegin(), (a).rend()
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
const ll INF=1e9+1;
using namespace std;
#define NOT_EXIST -1

//多分配列外にアクセスしたから, Run Time Errorが生じた
//配列内だけで、DPを完結する必要がある

int dy[]={1,-1,0,0,1,1,-1,-1,0};
int dx[]={0,0,1,-1,1,-1,1,-1,0};

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> c(m);
	for(int i=0;i<m;i++){
		cin >>c[i];
	}
	sort(All(c));
	//dp[i]: i円のときのコスト
	vector<int> dp(n+1,INF);
	dp[0] = 0;

	for(int i=0;i<=n;i++){
		for(int j=0;j<m;j++){
			int key = c[j];
			if(i-key>=0) dp[i] = min(dp[i], dp[i-key]+1);
			//cout << "dp[" << i+c[j] << "] = " << dp[ i+c[j] ] << endl;
		}
	}

	cout << dp[n] << endl;
}