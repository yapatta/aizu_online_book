#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	while(cin >> n >> m && (n != 0 || m != 0))
	{
		vector<int> h(n);
		vector<int> w(m);
		int hn = 0, wm = 0;

		for(int i = 0;i < n; i++)
		{
			cin >> h[i];
			hn += (i+1);
		}
		for(int i = 0;i < m; i++)
		{
			cin >> w[i];
			wm += (i+1);
		}
		vector<int> h_all(hn, 0);
		vector<int> w_all(wm, 0);

		int k = 0;
		for(int j = 0;j < n; j++)
		{
			for(int i = 0;i < n-j; i++)
			{
				for(int s = i;s <= i+j; s++)
				{
					h_all[k] += h[s];
				}
				k++;
			}
		}

		k = 0;
		for(int j = 0;j < m; j++)
		{
			for(int i = 0;i < m-j; i++)
			{
				for(int s = i;s <= i+j; s++)
				{
					w_all[k] += w[s];
				}
				k++;
			}
		}

		int counter = 0;

		for(int i = 0; i < hn; i++)
		{	
			for(int j = 0; j < wm; j++)
			{
				if(h_all[i] == w_all[j])
					counter++;
			}
		}

		cout << counter << endl;
	}
	return 0;
}