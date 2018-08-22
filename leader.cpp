#include <bits/stdc++.h>

using namespace std;
int main() {
	
	int t;
	
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    
	    
	    vector<int>a;
	    int in;
	    for(int i=0;i<n;i++)
	   {
	       cin>>in;
	       a.push_back(in);
	   }
	        
	    for(int i=0;i<n;i++)
	    {
	        int flag=1;
	        for(int j=i+1;j<n;j++)
	        {
	            if(a[i]<=a[j])
	            {
	                flag=0;
	                break;
	            }
	        }
	        
	        if(flag || i==n-1)
	          cout<<a[i]<<" ";
	    }
	    
	    a.clear();
	}
	return 0;
}