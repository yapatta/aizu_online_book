#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> d(n);

	for(int i = 0; i < n;i++)
		cin >> d[i];

	sort(&d[0], &d[n]);

	for(int i = 0; i < n;i++)
	{
		printf("%d ", d[i]);
	}
	putchar('\n');

	return 0;
}