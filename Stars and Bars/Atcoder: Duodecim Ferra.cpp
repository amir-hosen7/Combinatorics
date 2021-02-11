

//https://atcoder.jp/contests/abc185/tasks/abc185_c

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prnt(a) cout<<a
#define sp cout<<" "
#define nl cout<<"\n"
#define in1(a) cin>>a
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,a,b) for(ll i=a; i<b; i++) 
typedef tree < ll, null_type, less < ll >, 
rb_tree_tag, tree_order_statistics_node_update > ordered_set;
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}

//------------------------------------------------------------------------------//
const int N=1e6;


ll nCr(ll n,ll r){
	ll res=1;
	if(r>(n-r)){
		r=n-r;
	}
	rep(i,0,r){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}


int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	rep(T,1,t+1){
		ll n; cin>>n;
		ll bars=11;
		ll stars=n+11-12;
		cout<<nCr(stars,bars)<<"\n";
	}
	return 0;
}

