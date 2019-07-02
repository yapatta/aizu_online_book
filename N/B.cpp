#include <iostream>
using namespace std;

int main(void)
{
	int a, b, k;
	cin >> a >> b >> k;
	if (b-a < 2*k)
	{
		for (int i = a; i <= b; i++)
			cout << i << endl;
	}
	else
	{
		int x = a;
		for (int i = 0; i < k; i++)
		{
			cout << x << endl;
			x++;
		}
		x = b - k + 1;
		for (int i = 0; i < k; i++)
		{
			cout << x << endl;
			x++;
		}
	}
	return 0;
}