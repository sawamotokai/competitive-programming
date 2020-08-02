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
  int k;cin >> k;
  ll now = 7;
  int cnt = 1;
  rep(i, 1e6) {
    if (now % k == 0) {
      cout << cnt << endl;
      return 0;
    }
    (now *= 10) %= k;
    (now += 7) %= k;
    cnt++;
  }
  cout << -1 << endl;
  return 0;
}