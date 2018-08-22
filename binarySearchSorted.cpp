#include <bits/stdc++.h>

using namespace std;


int bs(int a[],int key,int s,int e)
{

	if(s<e)
	{
		int mid=(s+e/2);

		if(a[mid]==key && a[mid-1]!=key)
		{
			return mid;
		}

		else if(a[mid] > key)
		{
			bs(a,key,s,mid-1);
		}
	}





}


int main()
{

}