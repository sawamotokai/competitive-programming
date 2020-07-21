#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
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

int main() {
  ll N,C; cin >> N >> C;
  vector<vll> line(C, vll(100005));
  rep(i,N) {
    ll s,t,c; cin >> s >> t >> c;
    c--;
    line[c][s-1]++;
    line[c][t]--;
  }
  rep(i, 100003) {
    rep(c, C) {
      line[c][i+1] += line[c][i];
    }
  }
  ll ans = 0;
  rep(i, 100003) {
    ll num = 0;
    rep(c, C) {
      // if start time of one is the same as the end time of anohter, line[c][i] could be 2 and it's ok
      if (line[c][i] == 2) num--;
      num += line[c][i];
    }
    chmax(ans, num);
  }
  cout << ans << endl;
  return 0;

}