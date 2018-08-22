#include <bits/stdc++.h>

using namespace std;

pair<int,int>arr[256];

int main()
{
    string a;
    cin>>a;

    for(int i=0;i<a.length();i++)
    {
    	arr[(int)a[i]].first++;

    	arr[(int)a[i]].second=i;
    }

    int res=INT_MAX;
    for(int i=0;i<256;i++)
    {
    	if(arr[i].first==1)
    		res=min(res,arr[i].second);

    }

    cout<<a[res];




}