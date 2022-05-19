
//link - https://www.codechef.com/START39B/problems/MINBLOCK

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pob pop_back 
#define mk make_pair
#define in(x) ll x; cin>>x
#define in2(x,y) ll x;ll y;cin>>x;cin>>y;
#define in3(x,y,z) ll x;ll y;ll z;cin>>x;cin>>y;cin>>z;
#define in4(x,y,z,k) ll x;ll y;ll z;ll k;cin>>x;cin>>y;cin>>z;cin>>k;
#define reads(x) string x; cin>>x
#define strto to_string
#define fo(i,n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define repr(i,a,b) for(ll i=a; i>=b; i--)
#define repj(i,a,b,c) for(ll i=a; i<b; i+=c)
#define tr(it,a) for(auto it = a.begin(); it != a.end(); it++)
#define input(v,n) vector <ll> v(n); rep(i,0,n) cin>>v[i];
#define output(v) rep(i,0,n) cout<<v[i]<<" "; cout<<"\n"
#define all(v) v.begin(),v.end()
#define allr(v) v.begin(),v.end(),greater<ll>()

#define clr(x) memset(x, 0, sizeof(x))
#define sall(v) sort(all(v));
#define rall(v) reverse(all(v));
#define PI 3.1415926535897932384626
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)

#define arrin(ar,n) ll ar[n];for(ll i=0;i<n;i++) cin>>ar[i]
#define vin(v,n) vector<ll> v;for(ll i=0;i<n;i++){ll temp;cin>>temp;v.pb(temp);}
#define vc(v,j) vector<j> v;
#define mp unordered_map
#define rdup(a) sort(all(a));a.erase(unique(all(a)),a.end());
#define pll pair<ll,ll>

#define pii pair<int,int>
#define vvi vector<vector<int>>


const int N = 1e9 +7;
using namespace std;

ll power(ll base,ll ex);
ll extended_gcd(ll a,ll b,ll &x,ll &y);
ll powermod(long long x,ll y, int p);
bool pow2(ll n);
void dfs(ll node,ll parent);

ll dividing=1e9+7;

vector<vector<pii>> adj;
vector<int> sz;
vector<int> val;
int dfs_sz(int x,int p=0)
{
  sz[x]=1;
  
  for(pii j: adj[x])
  {
    if(j.first==p)
      continue;
    sz[x]+=dfs_sz(j.first,x);

  }
  return sz[x];
  
}

void dfs(int x,int p=0)
{
  for(pii j: adj[x])
  {
    if(j.first==p)
      continue;
    if(j.second==1)
    {
      val.pb(sz[j.first]);
      continue;

    }
    dfs(j.first,x);
    
  }
  
}


void solve()
{
	int n,k;
  cin>>n>>k;
  adj.clear();
  adj.resize(n+1);
  sz.clear();
  sz.resize(n+1);
  val.clear();
  //adjacency list - graph input
  for(int i=1;i<n;i++)
  {
    int u,v,x;
    cin>>u>>v>>x;
    pii a1={u,x};pii a2={v,x};
    adj[u].pb(a2);
    adj[v].pb(a1);
  }
  dfs_sz(1);//for calculating the size of the sub tree
  dfs(1);// for calculating how many roads blocked and store into a vector
  
  
  sort(all(val));
  
  int tot = n;
	int ans = 0;
	while(tot > k && val.size()>0){
		int t = val.back();
		val.pop_back();
		tot -= t;
		ans++;
	}
	if(tot > k) ans = -1;
	cout << ans << "\n";
}


	
int main()
{fastIO;
int t;
cin>>t;
	
	while(t--)
	{
		solve();
	}
	return 0;
}


ll extended_gcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll x1,y1;
	ll d = extended_gcd(b,a % b,x1,y1);
	x = y1;
	y = x1 - y1*(a/b);
	return d;
}

bool pow2(ll n)
{
   if(n==0)
   return false;
  
   return (ceil(log2(n)) == floor(log2(n)));
}

ll power(ll base,ll ex){
	if(base == 0)
		return 0;
	if(ex == 0)
		return 1;
	ll y;
	if((ex & 1) == 0){
		y = power(base,ex/2);
		y = (y * y) % N;
	}
	else{
		y = base % N;
		y = (y * power(base,ex-1) % N) % N;
	}
	return (y+N)%N;
}

ll powermod(long long x,ll y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
