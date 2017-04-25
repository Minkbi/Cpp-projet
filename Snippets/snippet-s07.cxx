#include<iostream>
using namespace std;

void xpy(int &x, int &y)
{ x += y; }
int xpy2(int &x, int &y)
{ return x+y; }
int xpy3(int x, int y)
{ return x+y; }

int main()
{
  int a = 5, b = 6;
  cout<<xpy3(a,b)<<endl;
  cout<<xpy2(a,b)<<endl;
  xpy(a,b);
  cout<<a<<endl;
  return 0;
}
