#include <bits/stdc++.h>

using namespace std;


vector<int> toBinary(int num)
{
	vector<int>v;
	while(num!=0)
	{
		int rem=num%2;
		v.push_back(rem);
		num=num/2;

	}

	reverse(v.begin(),v.end());

	return v;
}


int main()
{

  int t;
  cin>>t;
  
  while(t--)
  {
      int num;
   cin>>num;

   vector<int>v;

   v=toBinary(num);
   
   int maxx=0;
   for(int i=0;i<v.size();i++)
   {
     int cnt=0;
   	 while(v[i]==1)
   	 {
   	 	cnt++;
   	 	i++;
   	 }

   	 if(cnt>maxx)
   	 	maxx=cnt;


   }

   cout<<maxx<<"\n";
   
  }
}