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
// abc34d
int main() {
  int n,k; cin >> n >> k; 
  vector<P> bottle(n);
  rep(i,n) cin >> bottle[i].first >> bottle[i].second;
  double curP = 0;
  double water = 0;
  double salt = 0;
  
  vi used(n);
  rep(i,k){
    int nextIdx = 0;
    double maxNp = 0.;
    rep(j, n){
      if (used[j]) continue;
      double s = (double) bottle[i].first * bottle[i].second / 100.0;
      double w = (double) bottle[i].first - s;
      cout << w << " " << s << " " << j << endl;
      double nw = water + w;
      double ns = salt + s;
      double np = 100. * ns/(nw+ns);
      // cout << np << endl;
      if (maxNp < np) {
        maxNp = np;
        nextIdx = j;
      }
    }
    used[nextIdx] = true;
    double s = bottle[nextIdx].first * bottle[nextIdx].second / 100.0;
    double w = bottle[nextIdx].first - w;
    double nw = water + w;
    double ns = salt + s;
    double np = 100 * ns/(nw+ns);
    curP = np;
    water = nw;
    salt = ns;
  }
  printf("%.10f\n", curP);
  return 0;
}