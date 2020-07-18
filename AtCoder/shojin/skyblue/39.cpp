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


// abc89d

int h, w, d;
int maxNum;
int a[305][305];
ll dist[100000];
map<int, P> mp;



int getDist(int before, int after) {
  int x1 = mp[before].first;
  int y1 = mp[before].second;
  int x2 = mp[after].first;
  int y2 = mp[after].second;
  return abs(x1-x2) + abs(y1-y2);
}

int mem(int num) {
  int ret=0;
  if (dist[num] == -1) {
    if (num + d <= maxNum) {
      ret = mem(num+d);
      if (num) ret += getDist(num, num+d);
    }
    dist[num] = ret;
  }
  return dist[num];
}

void solve() {
  int L, R; cin >> L>> R;
  cout << mem(L)-mem(R) << endl; 
}

int main() {
  memset(dist, -1, sizeof(dist));
  cin >> h >> w >> d;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) mp[a[i][j]] = P(i, j);
  maxNum = h*w;
  rep(i, d) mem(i);
  int q; cin >> q;
  rep(i, q) solve();
  return 0;
}