#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s,int low,int high)
{
	int len=s.length();

	while(low<high)
	{
		if(s[low]!=s[high])
			return false;

		low++;
		high--;
	}

	return true;

}

void printPalinUtil(vector< vector<string> >& all,vector<string>& cur,int start,int n,string s)
{
	if(start==n)
	{
		all.push_back(cur);
		return;
	}

	for(int i=start;i<n;i++)
	{
		if(isPalindrome(s,start,i))
		{
			cur.push_back(s.substr(start,i-start+1));

			printPalinUtil(all,cur,i+1,n,s);

			cur.pop_back();
		}
	}
}


void printPalin(string s)
{
	vector<vector<string> >all;
	vector<string>cur;

	printPalinUtil(all,cur,0,s.length(),s);

	for(int i=0;i<all.size();i++)
	{
		for(int j=0;j<all[i].size();j++)
			cout<<all[i][j]<<" ";
		
		cout<<endl;

	}
}

int main()
{
    string str = "nitin";
    printPalin(str);
    return 0;
}