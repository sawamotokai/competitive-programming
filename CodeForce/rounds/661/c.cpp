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


void solve() {
  int n; cin >> n;
  vi w(n);
  rep(i,n) cin >> w[i];
  map<int,int> mp;
  rep(i,n) mp[w[i]]++;
  int ans = 0;
  rep(s, 2*n + 1) {
    map<int, int> mp2 = mp;
    int num = 0;
    rep(i,n) {
      int a = w[i];
      int b = s-a;
      if (mp2.find(b) != mp2.end()) {
        if (mp2[a] == 0 || mp2[b] == 0) continue;
        if (a == b && mp2[a] == 1) continue;
        mp2[a]--;
        mp2[b]--;
        num++;
      }
    }
    chmax(ans, num);
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  rep(i,t) solve();
  return 0;
}