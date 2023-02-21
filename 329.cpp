#include<bits/stdc++.h>
using namespace std;

#define ll       	long long
#define ld       	long duble
#define ull      	unsigned ll
#define vi   		vector<int>
#define vll   		vector<ll>
#define vld   		vector<ld>
#define vstr   		vector<string>
#define vvi 		vector<vector<int>>
#define vvll 		vector<vector<ll>>
#define vvld 		vector<vector<ld>>
#define pii      	pair<int, int>
#define pll      	pair<ll, ll>
#define mp       	make_pair
#define pb       	push_back
#define sz(x)    	(int) x.size()
#define all(a)         a.begin(), a.end()
#define all_0(x)       memset(x,0,sizeof(x))
#define all_neg(x)     memset(x,-1,sizeof(x))
#define all_1(x)       memset(x,1,sizeof(x))
#define  bitcount(x)   (int)__builtin_popcount(x)
#define  Lsb(x)  	   (int)__builtin_ctzll(x)
#define fr0(i, p, n)     for(ll i = p; i < n; i++)
#define fr1(i, p, n)     for(ll i = p; i <=n; i++)
#define fast           ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define in(n)          long long n;   cin >> n
#define ins(s)         string s;   cin >> s
#define csp(x)         cout<<(x)<<" "
#define c1(x)          cout<<(x)<<endl
#define c2(x,y)        cout<<(x)<<" "<<(y)<<endl
#define c3(x,y,z)      cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define c4(a,b,c,d)    cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl

#define YES            cout<<"YES"<<endl
#define Yes            cout<<"Yes"<<endl
#define NO             cout<<"NO"<<endl
#define No             cout<<"No"<<endl
#define nl             printf("\n")
#define ff             first
#define ss             second
#define endl           "\n"

const int mod = (int) 1e9 + 7;
const int inf = (int) 2e9 + 5;
const ll  Inf = (ll) 2e18 + 5;
const int N   = (int) 2e5 + 5;
vector<vector<int>> v;
vector<int>vt;
int dp[205][205];
int dfs(int i,int j,int pre,vector<vector<int>>& v){
	int m = v.size();
	int n= v[0].size();
	if(i<0 or j<0)return 0;
	if(i>=m or j>=n)return 0;
	if(pre>=v[i][j])return 0;
	if(dp[i][j])return dp[i][j];

	int l = dfs(i,j+1,v[i][j],v);
	int r = dfs(i,j-1,v[i][j],v);
	int u = dfs(i+1,j,v[i][j],v);
	int d = dfs(i-1,j,v[i][j],v);
	dp[i][j]=max({l,r,u,d})+1;
	return dp[i][j];
}
int solve() {
	ll x = 0,y = 0, z = 0, i, j, sum = 0,ans=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			vt.push_back(x);
		}
		v.push_back(vt);
		vt.clear();
	}
	int max_val=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			max_val = max(max_val,dfs(i,j,-1,v));
		}
	}
	cout<<max_val<<endl;

	return 0;
}

int main() {
	fast;
	int test = 1;
	//Int(test);
	//cin >> test;
	while (test--) {
		solve();
	}
	return 0;
}


