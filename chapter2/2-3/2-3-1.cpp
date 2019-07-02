#include <iostream>

using namespace std;

int main(void)
{
	int x, y, s;
	while(cin >> x >> y >> s)
	{
		if(x == 0 && y == 0 && s == 0)
			break;

		int ato, max = 0;
		double wari = (double)(100+y)/(double)(100+x);
		
		for (int i = 0; i <= s / 2; i++)
		{
			int t = s - i;
			ato = (int)(t*wari) + (int)(i*wari);
			if(max < ato)
				max = ato;
		}
		cout << max << endl;
	}

	return 0;
}