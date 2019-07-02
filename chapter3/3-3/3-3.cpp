#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long int Uint;

int main(void)
{
	int t;

	cin >> t;
	for(int i = 0;i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		vector<Uint> x(n);
		x[0] = 0;
		vector<Uint> y(n-1);

		cin >> x[0];
		for(int j = 1;j < n; j++)
		{
			cin >> x[j];
			y[j-1] = x[j] - x[j-1];
		}

		sort(y.begin(), y.end());

		int max = 0;
		for(int j = 0;j < n-k; j++)
			max += y[j];
	
		cout << max << endl;
	}
	return 0;
}