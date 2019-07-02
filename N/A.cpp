#include <iostream>
using namespace std;

int main(void)
{
	char s[3];
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < 3; i++)
	{
		if(s[i] == 'a')
			a++;
		else if(s[i] == 'b')
			b++;
		else if(s[i] == 'c')
			c++;
	}
	if(a == 1 && b == 1 && c == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}