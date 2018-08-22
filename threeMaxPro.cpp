#include <bits/stdc++.h>

using namespace std;

int main()
{

	int a[]={7,8,6,5,2,3};

	int f=-1,s=-1,t=-1;

    int maxPro=INT_MIN;
    
    int ansF,ansS,ansT;

	for(int i=0;i<7;i++)
	{
		f=a[i];

		for(int j=i+1;j<7;j++)
		{
			if(a[j]>a[i])
			{
				s=a[j];
			
			    for(int k=j+1;k<7;k++)
			    {
			    	if(a[k]>a[j] && maxPro<f*s*t)
			    	{
			    		t=a[k];
                        
                        maxPro=max(maxPro,f*s*t);
                        ansF=f;
                        ansT=t;
                        ansS=s;
			    	}
			    }

            }
		}

	}

	if(s==-1 || t==-1)
	{
		cout<<"Not possible\n";
        return 0;
	}

	cout<<ansF<<" "<<ansS<<" "<<ansT<<endl;

	return 0;
}