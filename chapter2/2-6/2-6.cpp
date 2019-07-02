#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t;

	cin >> t;

	for(int i= 0; i < t; i++)
	{
		int ar[9];
		char ar2[9];
		vector<int> R(9);
		vector<int> G(9);
		vector<int> B(9);

		int counter = 0;

		for(int i = 0; i < 9; i++)
			cin >> ar[i];

		for(int i = 0; i < 9; i++)
			cin >> ar2[i];

		for(int i = 0; i < 9; i++)
		{
			if(ar2[i] == 'R')
				R[ar[i]-1]++;
			else if(ar2[i] == 'G')
				G[ar[i]-1]++;
			else	//Bのとき
				B[ar[i]-1]++;
		}

		for(int i = 0; i < 9; i++)
		{
			if(R[i] >= 3)
			{
				counter++;
				R[i] -= 3;
			}
			if(G[i] >= 3)
			{
				counter++;
				G[i] -= 3;
			}
			if(B[i] >= 3)
			{
				counter++;
				B[i] -= 3;
			}
		}

		for(int i = 0; i < 7; i++)
		{
			while(R[i] > 0 && R[i+1] > 0 && R[i+2] > 0)
			{
				counter++;
				R[i] -= 1;
				R[i+1] -= 1;
				R[i+2] -= 1;
				if( ( R[i] > 0 && R[i+1] > 0 && R[i+2] > 0 ) != 1)
					break;
			}
			while(G[i] > 0 && G[i+1] > 0 && G[i+2] > 0)
			{
				counter++;
				G[i] -= 1;
				G[i+1] -= 1;
				G[i+2] -= 1;
				if( ( G[i] > 0 && G[i+1] > 0 && G[i+2] > 0 ) != 1)
					break;
			}
			while(B[i] > 0 && B[i+1] > 0 && B[i+2] > 0)
			{
				counter++;
				B[i] -= 1;
				B[i+1] -= 1;
				B[i+2] -= 1;
				if( ( B[i] > 0 && B[i+1] > 0 && B[i+2] > 0 ) != 1)
					break;
			}
		}
		if( counter >= 3)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}