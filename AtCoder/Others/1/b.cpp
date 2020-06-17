#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
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
  ll a,v,b,w,t; cin >> a >> v >> b >> w >> t;
  int dist = abs(a-b);
  ll velo = (v-w);
  ll move = velo * t;
  bool ok;
  if (dist <= move) ok = true;
  else ok = false;
  if (dist == 0) ok = true;
  puts(ok?"YES":"NO");
  return 0;
}