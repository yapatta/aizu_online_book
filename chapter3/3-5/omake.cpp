#include <iostream>

using namespace std;

class Cint
{
public:
	int m_num;

	Cint();
	Cint(int num);
	void Disp();
};

Cint::Cint()	   {m_num = 0;}
Cint::Cint(int num){m_num = num;}
void Cint::Disp()
{
	cout << m_num << endl;
}

int main()
{
	Cint a, b(100), c(30);
	a.Disp();
	b.Disp();
	c.Disp();
	return 0;
}