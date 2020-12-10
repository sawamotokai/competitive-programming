#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

void solve () {
  ll a,b,x,y,n;
  cin >> a >> b >> x >> y >> n;
  ll ans = a*b;
  ll now = 1;
  {
    ll na = a;
    ll nb = b;
    ll nn = n;
    ll dec = min(n, a-x);
    nn-=dec;
    na-=dec; 
    nb-=min(nn, b-y);
    chmin(ans,na*nb);
  }
  {
    ll na = a;
    ll nb = b;
    ll nn = n;
    ll dec = min(n, b-y);
    nn-=dec;
    nb-=dec; 
    na-=min(nn, a-x);
    chmin(ans,na*nb);
  }
  printf("%lld\n", ans);
}

int t;
int main() {
  cin >> t;
  rep(i,t) solve();
  return 0;
}