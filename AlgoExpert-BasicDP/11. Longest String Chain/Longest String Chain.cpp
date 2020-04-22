#include<bits/stdc++.h>

#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define lli long long int
#define ss second
#define ff first
#define pb push_back
#define rep(i,a,n) for(int i = a; i < n; i++)

using namespace std;

//Recurssive Fn to compute max edge length in graph for a particular vertex
//NOTE : Finding Longest path in any graph is not possible in polynomial time and not found
		//and it is a NP hard problem and hence cant be calculated
		
//But observing carefully this Graph is a DAG(Directed Acyclic Graph) and hence can be calc

//Logic : 

//Longest edge lenth at any vertex is max of Longest edge length
//for all its outer edge vertices

//Default value is 1 if no outer edge present(as it has LSC length including it only)
 
int longestLengthAtanyVertexInThisDAG(int v,vector<vector<int>> graph,vector<int> score)
{
	if(score[v] > 0)		//memoization
		return score[v];
		
	score[v] = 1;			//default value if not already calc
	
	for(int b : graph[v])	//Traverse for all outer edge vertices
		score[v] = max(score[v],longestLengthAtanyVertexInThisDAG(b,graph,score) + 1);
	
	return score[v];
}
int longestStringChainLength(vector<string> s,int n)
{
	vector<int> score;//Store max graph length at each vertex
	unordered_map<string,int> dict;//A dictionary to find if maybe string present in the original string vector
	
	rep(i,0,n)
		dict[s[i]] = i;//Initialize each string with index in dictionary
	
	vector<vector<int>> graph;
	
	graph.clear();
	graph.resize(n);//Remember-------Resize is very important---(as to set definite size)
	score.clear();
	score.resize(n);//Remember-------Resize is very important---(as to set definite size)
	
	rep(i,0,n)
	{
		string z = s[i];//Store current word
	
		for(int j = 0; j < (int)z.length(); j++)//Iterate for every character in word
		{
			
			string maybe = z.substr(0,j) + z.substr(j+1);//remove that particular character
			
			//cout<<\nmaybe<<"\n";
			
			auto pos = dict.find(maybe);//Check if the new string formed after removing the charcter
										//is present in dictionary or not
			
			if(pos == dict.end())		//If not found
				continue;
			else
				graph[pos->ss].pb(i);	//If found --- Add edge in the Graph 
		}
	}
	
	int ans = 0;
	rep(i,0,n)
		ans = max(ans,longestLengthAtanyVertexInThisDAG(i,graph,score));//compare and calculate max length at all vertex
	
	return ans;
	
}
int main()
{
	int t = 1;
	cin>>t;
	while(t--)
	{
		int n = 1;
		
		cout<<"Enter number of strings : ";
		cin>>n;	
	
		string temp;
		vector<string> s;
		
		cout<<"Enter the strings : \n";
		rep(i,0,n)
		{
			cin>>temp;
			s.pb(temp);
		}
		
		int x = longestStringChainLength(s,n);
		cout<<"Longest String Chain Length = "<<x<<"\n";
	}	
	return 0;
}
/*
1
8
a
b
ba
bc
bca
bdacc
bda
bdca
*/
/*
1
9
a
ab
abc
abcd
abcde
abcdef
abcdefg
abcdefgh
abcdefghi
*/
