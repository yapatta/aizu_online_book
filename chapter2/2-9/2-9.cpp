#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(void)
{
	int n, k, t, u, v, l;
	double second;
	double length;

	cin >> n >> k >> t >> u >> v >> l;
	int *d;
	d = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
		cin >> d[i];

	//d[0]までは速さuで走る
	second = (double)d[0] / u;
	length = (double)d[0];

	//d[0]からt秒間速さvで加速して走る
	second += t;
	length += v*t;

	if(l - length < 0)		//lengthがlを超えた場合
		{
			second -= t;
			length -= v*t;
			second += (l-length) / v;
			length = l;
		}

	int counter = 0;	//counter(持っている人参の数)
	int j = 1;

	while(length - d[j] >= 0 && j < n && length != l) //d地点を何個抜かしたか
	{
		if(counter == k)
		{
			length = d[j];
			second -= v*t;
			second += (d[j]-d[j-1]) / v;
			counter--;
		}
		if(counter < k)
			counter++;

		j++;

		cout << second << endl;
		cout << length << endl;
	}

	while(length != l)	//counterの個数だけ加速 ちなみにcounterがマイナスになることはない
	{
		if(counter > 0)
		{
			second += t;
			length += v*t;
			counter--;		//加速したらcounterを1減らす

			if(length - l > 0)		//lengthがlを超えた場合
			{
				second -= t;
				length -= v*t;
				second += (l-length) / v;
				length = l;
				break;
			}
			while(length - d[j] >= 0 && j < n) //d地点を何個抜かしたか
			{
				if(counter < k)
					counter++;
				j++;
			}		
		}

		else		//counterが0のとき
		{
			if(j < n)		//まだ先に人参がある場合
			{
				second += (double)(d[j] - length) / u;		//普通の速度で
				length = d[j];
				j++;
				counter++;
			}
			else if(j == n)	//加速していない状態で先にあるのはゴールだけ
			{
				second += (double)(l - length) / u;		//普通の速度で
				length = l;
				break;
			}
		}
		if(length == l)
			break;
	}

	cout << setprecision(9) << setiosflags(ios::fixed) << second << endl;

	free(d);
	return 0;
}