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
  string n; int s;
  int d=0;
  cin >> n >> s;
  rep(i,n.size()) d += n[i]-'0';
  if (d <= s) {
    cout << 0 << endl;
    return;
  }
  int idx = -1;
  d = 0;
  rep(i,n.size()) {
    d += n[i]-'0';
    if (d < s) {
      idx = i;
    } else break;
  }
  if (idx == -1) {
    ll x = 1;
    ll num = 0;
    rep(i,n.size()) {
      x*=10;
      num *= 10;
      num += n[i]-'0';
    }
    ll ans = x - num;
    cout << ans << endl;
    return ;
  }
  ll x = 0;
  rep(i,idx+1) {
    x *= 10;
    x += n[i]-'0';
  }
  ++x;
  rep(i,n.size()-idx-1) x*=10;
  ll num = 0;
  rep(i,n.size()) {
    num *= 10;
    num += n[i]-'0';
  }
  ll ans = x-num;
  cout << ans << endl;
}

int t;
int main() {
  cin >> t;
  rep(i,t) solve();
  return 0;
}