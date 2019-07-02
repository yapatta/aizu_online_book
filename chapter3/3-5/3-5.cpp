#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class dsa{
public:
	int first;
	int second;
	int sa;
	int max;
};

void change(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int n, t;
	cin >> n >> t;
	vector<dsa> d(n);

	for (int i = 0; i < n; i++)
	{
		cin >> d[i].first >> d[i].second;
		d[i].sa = d[i].second - d[i].first;
		d[i].max = d[i].sa + d[i].second;
	}
	sort(d.begin(), d.end());

	int counter = 0;

	if(d[0].first != 1)
	{
		cout << -1 << endl;
		return 0;
	}

	int max = 0;

	int length = d[0].second;
	for (int i = 0; i < n; i++)
		change(d[i].first, d[i].max);
	//maxが小さい順に
	sort(d.begin(), d.end());

	//maxが大きい順に
	reverse(d.begin(), d.end());

	//配列を元の形式に戻す
	for (int i = 0; i < n; i++)
		change(&d[i].first, &d[i].max);

	while(t > length)
	{
		for (int i = 0; i < n; i++)
		{
			if(t <= length)
				break;

			if(d[i].first <= length)
			{
				if(max < d[i].max)
				{
					max = d[i].max;
					length = d[i].second;
				}
				if(max.max == d[i].max)
					if(length < d[i].second)
						length = d[i].second;
			}
		}
		counter++;
	}

	cout << counter << endl;

	return 0;
}


//firstとsecondをチェンジ
	for(int i = 0; i < n; i++)
		change(&d[i].first, &d[i].second);

	//secondの小さい順にソート
	sort(d.begin(), d.end());
	//secondの大きい順にソート
	reverse(d.begin(), d.end());

	//firstとsecondの位置をもとに戻す
	for(int i = 0; i < n; i++)
		change(&d[i].first, &d[i].second);