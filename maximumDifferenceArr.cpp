#include <bits/stdc++.h>

using namespace std;

int main()
{

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int a[n];

		for(int i=0;i<n;i++)
			cin>>a[i];

		int minn=a[0];
		int maxD=a[1]-a[0];

		for(int i=1;i<n-1;i++)
		{
			if(a[i]<minn)
				minn=a[i];

			if(a[i+1]-minn > maxD)
				maxD=a[i+1]-minn;


		}

		if(maxD<=0)
			cout<<-1<<endl;

		else
			cout<<maxD<<endl;


	}

}