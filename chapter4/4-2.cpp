#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>

using namespace std;

//配列多めに確保しないと終わる！

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		int mata;
		cin >> mata;
		//[][][1]は左
		//[][][2]は下
		 vector<vector<vector<int> > > zahyo(x+2, vector<vector<int> >(y+2, vector<int>(3, 0)));
		 zahyo[1][1][0] = 1;

		int ax,ay,bx,by;
		for (int j = 0; j < mata; ++j)
		{
			cin >> ax >> ay>> bx >> by;
			if(ax == bx)	//x座標が等しい
			{
				if(by > ay)	//bがaよりy座標が大きい
					zahyo[bx+1][by+1][2]++;
				else	//aがbよりy座標が大きい
					zahyo[ax+1][ay+1][2]++;
			}else	//y座標が等しい
			{
				if(bx > ax)	//bがaよりx座標が大きい
					zahyo[bx+1][by+1][1]++;
				else	//aがbよりx座標が大きい
					zahyo[ax+1][ay+1][1]++;
			}
		}

		for (int k = 1; k <= x+1; ++k)
		{
			for (int l = 1; l <= y+1; ++l)
			{
				if(!(k == 1 && l == 1))
				{
					if(zahyo[k][l][1] > 0 && zahyo[k][l][2] > 0)
						zahyo[k][l][0] = 0;
					else if(zahyo[k][l][1] > 0 && zahyo[k][l][2] == 0)
						zahyo[k][l][0] = zahyo[k][l-1][0];
					else if(zahyo[k][l][2] > 0 && zahyo[k][l][1] == 0)
						zahyo[k][l][0] = zahyo[k-1][l][0];
					else
						zahyo[k][l][0] = zahyo[k-1][l][0] + zahyo[k][l-1][0];
				}
			}
		}

		if(zahyo[x+1][y+1][0] == 0)
			cout << "Miserable Hokusai!" << endl;
		else
			cout << zahyo[x+1][y+1][0] << endl;
	}

	return 0;
}