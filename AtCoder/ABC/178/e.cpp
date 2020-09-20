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

int N;

int main() {
  cin >> N;
  vii p(N);
  rep(i,N) cin >> p[i].fi >> p[i].se;  
  vii p2(N);
  rep(i,N) p2[i] = p[i];
  sort(all(p));
  sort(all(p2), [](ii a, ii b) {return a.se < b.se;});
  ll ans = 0;
  auto getDist = [](ii a, ii b) {
    return abs(a.fi - b.fi) + abs(a.se - b.se);
  };
  rep(i,N) {
    ii x = p[i];
    ii y = p[0];
    ll d = getDist(x,y);
    chmax(ans,d);
    y = p.back();
    d = getDist(x,y);
    chmax(ans,d);
    y = p2.back();
    d = getDist(x,y);
    chmax(ans,d);
    y = p2[0];
    d = getDist(x,y);
    chmax(ans,d);
  }
  cout << ans << endl;
  return 0;
}