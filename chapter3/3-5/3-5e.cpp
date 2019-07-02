#include <algorithm>
#include <stdio.h>

using namespace std;

inline void change(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int n, t;
	scanf("%d%d", &n, &t);
	pair<int, int> d[n];

	for(int i = 0; i < n; i++)
		scanf("%d%d", &d[i].first, &d[i].second);

	//firstの小さい順にソート
	sort(&d[0], &d[n]);

	if(d[0].first != 1)
	{
		printf("%d\n", -1);
		return 0;
	}

	int max_second = 0, max_first = t;
	int length = 1;

	int counter = 0;

	while(counter < n && t > length)
	{
		max_second = 0;

		for (int i = 0; i < n; i++)
		{
			if(d[i].first <= length && d[i].second > length)
			{
				if(max_second <= d[i].second)
				{
					max_second = d[i].second;
				}
			}
		}
		if(max_second == 0)
		{
			printf("%d\n", -1);
			return 0;
		}
		length = max_second;
		counter++;
	}
	if(length < t)
		printf("%d\n", -1);
	else
		printf("%d\n", counter);

	return 0;
}