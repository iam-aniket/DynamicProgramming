#include<bits/stdc++.h>
#define loop(i,a,n) for(int i = a; i < n; i++)
#define tek ios_base::sync_with_stdio(false)
#define mp make_pair
#define pb push_back
#define lli long long int
#define a b

using namespace std;
int numberOfWaysForChange(int tot,vector<int> denoms,int n)
{
	vector<int> ways(tot + 1,0);
	ways[0] = 1;
	
	for(int denom : denoms)
	{
		for(int amount = 1; amount < tot + 1; amount++)
		{
			if(amount >= denom)
			{
				ways[amount] += ways[amount - denom];
			}
		}
	}
	cout<<"TOTAL WAYS : ";
	loop(i,0,tot+1)
	cout<<ways[i]<<" ";
	cout<<endl;
	return ways[tot];
}
int minCoinsForChange(int tot,vector<int> denoms,int n)
{
	vector<int> ways(tot + 1,1000000);
	
	ways[0] = 0;
	
	for(int amount = 1; amount < tot + 1; amount++)
	{
		for(int denom : denoms)
		{
			if(amount >= denom)
			ways[amount] = min(1 + ways[amount - denom],ways[amount]);
		}
	}
	cout<<"MIN COINS : ";
	loop(i,0,tot+1)
	cout<<ways[i]<<" ";
	cout<<endl;
	return ways[tot];
}
int main()
{
	int t = 1;
	cin>>t;
	
	while(t--)
	{
		int tot = 0, n = 0;
		
		cout<<"Enter Total Amount : ";	cin>>tot;	
		cout<<"Enter number of denominations : ";	cin>>n;
		cout<<"Enter denominations : ";
		vector<int> denoms;
		
		loop(i,0,n)
		{
			int x = 0;
			cin>>x;
			denoms.pb(x);
		}
		
		int val = numberOfWaysForChange(tot,denoms,n);
		int minVal = minCoinsForChange(tot,denoms,n);
		
		
		cout<<"Total no of ways possible are : "<<val<<endl;
		cout<<"Minimum coins required are : "<<minVal<<endl;
	}	
} 
/*
2 
11
3
1 2 5
25
6
2 3 4 6 7 9
*/
//op -- 3
