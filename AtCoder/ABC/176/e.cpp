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

int H,W,M;
int main() {
  cin >> H >> W >> M;
  set<ii> st;
  map<int, int> mpH,mpW;
  rep(i,M) {
    int h,w;cin >> h>>w;
    mpH[h]++;
    mpW[w]++;
    st.insert({h,w});
  }

  int mxH=-1;
  int mxW=-1;
  set<int> hpos, wpos;
  for (auto p: mpH) {
    auto [pos, h] = p;
    if (chmax(mxH, h)) hpos = set<int>();
    if (mxH == h) hpos.insert(pos);
  }
  for (auto p: mpW) {
    auto [pos, w] = p;
    if (chmax(mxW, w)) wpos = set<int>();
    if (mxW == w) wpos.insert(pos);
  }

  int ans = mxH + mxW - 1;
  for (int h: hpos) {
    for (int w: wpos) {
      if (st.find({h,w}) == st.end()) {
        ans++;
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}