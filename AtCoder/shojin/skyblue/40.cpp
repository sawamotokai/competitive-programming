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

bool dpX[8005][18005];
bool dpY[8005][18005];
int main() {
  int x,y; string s; cin >> s >> x >> y;
  int n = s.size();
  int origin = n;
  int mx = 2*n;
  vector<int> moveX; 
  vector<int> moveY; 
  int dir = 0;
  int cnt = 0;
  bool firstMove = s[0] == 'F';
  rep(i, n) {
    if (s[i] == 'T') {
      if (firstMove) {
        dpX[0][origin + cnt] = true;
        firstMove = false;
        cnt = 0;
      }
      dir ^= 1;
      if (cnt) {
        if (dir) moveY.push_back(cnt);
        else moveX.push_back(cnt);
      }
      cnt = 0;
    } 
    else cnt++;
  }
  dpX[0][n] = dpY[0][n] = true;
  for (int i=0; i<moveX.size(); i++) {
    rep(j, mx+1) {
      if (dpX[i][j]) {
        dpX[i+1][j] = true;
        if (j+moveX[i] <= n)dpX[i+1][j+moveX[i]] = true;
        if (j-moveX[i] >= 0) dpX[i+1][j-moveX[i]] = true;
      }
    }
  }
  for (int i=0; i<moveY.size(); i++) {
    rep(j, mx+1) {
      if (dpY[i][j]) {
        dpY[i+1][j] = true;
        if (j+moveY[i] <= n)dpY[i+1][j+moveY[i]] = true;
        if (j-moveY[i] >= 0) dpY[i+1][j-moveY[i]] = true;
      }
    }
  }
  x += origin;
  y += origin;
  bool ok = dpX[moveX.size()][x] && dpY[moveY.size()][y];
  ok();
  return 0;
}