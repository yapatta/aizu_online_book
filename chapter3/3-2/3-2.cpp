#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
 
int main(void)
{
	int n;
	cin >> n;

	vector<string> d(n);

	for(int i = 0; i < n;i++)
	{
		cin >> d[i];
	}
	sort(&d[0], &d[n]);

	cout << d[0] << endl;

	return 0;
}