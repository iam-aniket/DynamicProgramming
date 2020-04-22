#include<bits/stdc++.h>
#define loop(i,a,n) for(int i = a; i < n; i++)
using namespace std;

int levenshteinDistance(string s1,string s2)
{
	int n1 = s1.size(),n2 = s2.size();
	
	int a[n2 + 1][n1 + 1];
	
	loop(i,0,n2+1)
	{
		loop(j,0,n1+1)
		{
			a[i][j] = 0;	
		}	
	}
	
	loop(i,0,n2+1)
		a[i][0] = i;
	loop(i,0,n1+1)
		a[0][i] = i;	
	
	loop(i,0,n2+1)
	{
		loop(j,0,n1+1)
		{
			cout<<a[i][j]<<" ";	
		}	
		cout<<endl;
	}
	
	loop(i,1,n2+1)
	{
		loop(j,1,n1+1)
		{
			if(s2[i-1] == s1[j-1])
				a[i][j] = a[i-1][j-1];
			else
			{
				a[i][j] = 1 + min(a[i-1][j],min(a[i][j-1],a[i-1][j-1]));
			}
		}
	}
	
	cout<<"NOW : \n";
		
	loop(i,0,n2+1)
	{
		loop(j,0,n1+1)
		{
			cout<<a[i][j]<<" ";	
		}	
		cout<<endl;
	}
	return a[n2][n1];
}

int main()
{
	int t = 1;
	cin>>t;
	
	while(t--)
	{
		cout<<"Enter the two strings : \n";
		string s1,s2;
		cin>>s1>>s2;
		
		int x = levenshteinDistance(s1,s2);
		
		cout<<"Min operations to convert s1 to s2 = "<<x<<endl;
	}
	
	
}
/*
3
asbnjiop
abnc

cat
dog

benyam
ephrem
*/
