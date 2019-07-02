#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n, r;
	while(cin >> n >> r && n!=0 && r != 0)
	{	
		vector<int> A(n);
		for(int i = 0;i < n; i++)
		{
			A[i] = n - i;
		}

		int p, c;

		for(int i = 0; i < r; i++)
		{
			cin >> p >> c;

			if(c != n && ( (p + c - 1) != n ) )
				rotate(&A[0], &A[0] + n - p, &A[0] + n - p + c);
			else if( (p + c - 1) == n ) 
				rotate( &A[0], &A[0] + n - c, &A[n]);

		}
		cout << A[0] << endl;
	}
	return 0;
}