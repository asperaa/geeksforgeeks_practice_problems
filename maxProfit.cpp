#include <bits/stdc++.h>

using namespace std;


void buySell(int a[],int n)
{
    int buy=0;
    int sell=0;
    
    vector<pair<int,int> >p;
    for(int i=0;i<n-1;i++)
    {
    	if(a[i]<a[i+1])
    	{
    		sell=i+1;


    	}

    	else
    	{
    		
    		if(buy!=sell)
    			p.push_back(make_pair(buy,sell));
    		sell=i+1;
    		buy=i+1;
    	}

    
        


    }

    if(buy!=sell)
    	p.push_back(make_pair(buy,sell));

    if(p.size()==0)
    	cout<<"No Profit";

    else
    {
    	for(int i=0;i<p.size();i++)
    		cout<<"("<<p[i].first<<" "<<p[i].second<<")"<<" ";

    }
}


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

		buySell(a,n);
		cout<<"\n";

	}
}