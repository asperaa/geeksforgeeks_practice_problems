#include <bits/stdc++.h>

using namespace std;

int cnt[100];

int main()
{
	int flag=0;

	char f;

	string a;
	cin>>a;
    
	for(int i=0;i<a.length();i++)
	{
		cnt[(int)a[i]]++;

	}


	for(int i=0;i<a.length();i++)
	{
		if(cnt[(int)a[i]]==1)
		{
			f=a[i];
			flag=1;
			break;
		}
	}
    
   // cout<<cnt[(int)f];
    if(flag==1)
	cout<<f<<endl;
    
    else
    	cout<<"Not possible\n";
}