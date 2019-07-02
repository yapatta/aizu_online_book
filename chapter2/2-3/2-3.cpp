#include <iostream>
using namespace std;

int main(void)
{
	int x, y, s;
	while(cin >> x >> y >> s)
	{
		if(x == 0 && y == 0 && s == 0)
			break;

		int max = 0;
		int i, j,sum_x = 0, sum_y = 0;
		double to_x = 1 + x/100.0;
		double to_y = 1 + y/100.0;
		
		for (i = 1; i <= s-1; i++)
		{
			for(j = 1; j <= s-1; j++)
			{
				sum_x = (int)(i*to_x + 0.000001) + (int)(j*to_x + 0.000001);
				if(sum_x == s)
				{
					sum_y = (int)(i*to_y + 0.000001) + (int)(j*to_y + 0.000001);
					
					if(max <= sum_y)
						max = sum_y;
				}
			}
		}
		cout << max << endl;
	}

	return 0;
}