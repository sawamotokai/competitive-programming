#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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



void solve() {
  ll P,F,cntS,cntW,s,w;
  cin >> P >> F >> cntS >> cntW >> s >> w;
  ll ans = 0;
  if (s < w) {
    ll cnts = cntS;
    ll cntw = cntW;
    ll p = P;
    ll f = F;

    ll now = 0;
    now += min(cnts, p/s);
    p -= min(cnts, p/s) * s;
    cnts = max(0ll, cnts-p/s);
    if (p >= w) {
      now += min(cntw, p / w);
      cntw = max(0ll, cntw - p / w);
    }

    now += min(cnts, f/s);
    f -= min(cnts, f/s) * s;
    cnts = max(0ll, cnts-f/s);
    if (f >= w) {
      now += min(cntw, f/w);
      cntw = max(0ll, cntw - f/w);
    }
    chmax(ans, now);

    now = 0;
    cnts = cntS;
    cntw = cntW;
    p = P;
    f = F;

    now += min(cnts, f/s);
    f -= min(cnts, f/s) * s;
    cnts = max(0ll, cnts-f/s);
    if (f >= w) {
      now += min(cntw, f/w);
      cntw = max(0ll, cntw - f/w);
    }

    now += min(cnts, p/s);
    p -= min(cnts, p/s) * s;
    cnts = max(0ll, cnts-p/s);
    if (p >= w) {
      now += min(cntw, p / w);
      cntw = max(0ll, cntw - p / w);
    }

    chmax(ans, now);

  } else {

    ll cnts = cntS;
    ll cntw = cntW;
    ll p = P;
    ll f = F;

    ll now = 0;
    now += min(cntw, p/w);
    p -= min(cntw, p/w) * w;
    cntw = max(0ll, cntw-p/w);
    if (p >= s) {
      now += min(cnts, p / s);
      cnts = max(0ll, cnts - p / s);
    }

    now += min(cntw, f/w);
    f -= min(cntw, f/w) * w;
    cntw = max(0ll, cntw-f/w);
    if (f >= s) {
      now += min(cnts, f/s);
      cnts = max(0ll, cnts - f/s);
    }
    chmax(ans, now);

    cnts = cntS;
    cntw = cntW;
    p = P;
    f = F;

    now = 0;

    now += min(cntw, p/w);
    p -= min(cntw, p/w) * w;
    cntw = max(0ll, cntw-p/w);
    if (p >= s) {
      now += min(cnts, p / s);
      cnts = max(0ll, cnts - p / s);
    }

    now += min(cntw, f/w);
    f -= min(cntw, f/w) * w;
    cntw = max(0ll, cntw-f/w);
    if (f >= s) {
      now += min(cnts, f/s);
      cnts = max(0ll, cnts - f/s);
    }
    chmax(ans, now);
  }
  cout << ans << endl;
}
int t;
int main() {
  cin >> t;
  rep(i,t) solve();
  return 0;
}