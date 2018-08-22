#include <bits/stdc++.h>

using namespace std;


int maxOnesCon(int x)
{
	int cnt=0;

	while(x!=0)
	{
		x=(x&(x<<1));
		cnt++;
	}

	return cnt;
}

int main()
{
	cout<<maxOnesCon(44)<<endl;
	cout<<maxOnesCon(427)<<endl;


	

}