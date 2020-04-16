#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 
const ll mod = 1e9+7;
int main() {
  int N; cin>>N;
  vector<ll> a(N);
  rep(i,N) cin>>a[i];
  ll ans =0;
  rep(i, 60) {
    ll x=0;
    rep(j,N) {
      if (a[j]>>i &1) x++;
    }
    ll now = x*(N-x)%mod;
    rep(j, i) now = now*2%mod;
    ans = (ans + now) % mod;
  }
  cout << ans << endl;
  return 0;
}
