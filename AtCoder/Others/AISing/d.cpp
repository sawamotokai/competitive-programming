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

int popcnt(int n) {
  return __builtin_popcount(n);
}

int f(int n) {
  if (n==0) return 0;
  return 1 + f(n % popcnt(n));
}

int main() {
  int n; string x; cin >> n >> x;
  // find x mod pc;
  int pc=0;
  rep(i,n) if(x[i] == '1') pc++;
  vi ans(n);
  rep(b, 2) {
    int npc = pc;
    if (b==0) npc++;
    else npc--;
    if (npc <= 0) continue;
    int num = 0;
    rep(i, n) {
      num = (num << 1) %npc;
      num += x[i] - '0';
    }
    int k = 1;
    for (int i=n-1; i>=0; --i) {
      if (x[i] - '0' == b) {
        int nx = num;
        if (b == 0) nx = (nx + k) % npc;
        else nx = (nx - k + npc) % npc;
        ans[i] = f(nx) + 1;
      }
      k = (k << 1) % npc;
    }
  }
  rep(i,n) cout << ans[i] << endl;
  return 0;
}