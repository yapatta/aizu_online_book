#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, q;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> q;
	for (int i = 0; i < q; ++i)
		cin >> b[i];

	int count = 0;

	sort(a.begin(), a.end());
	for (int i = 0; i < q; ++i)
	{
		int first = 0;
		int last = n;
		while(first + 1 < last){
		int med = (first + last) / 2;
		if(a[med] > b[i]) last = med;
		else first = med;
		}
		if(first < last && a[first] == b[i])
			count++;
	}
	cout << count << endl;

	return 0;
}