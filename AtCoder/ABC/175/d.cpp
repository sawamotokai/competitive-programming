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

ll N,K;
int main() {
  cin >> N >> K;
  vll C(N), P(N);
  rep(i,N) {
    cin >> P[i];
    P[i]--;
  }
  rep(i,N) cin >> C[i];

  ll ans =-LINF;
  // if sum of loop is positive, go K/sizeofloop loops and go as much as possible in addition
  // else go as much as possible
  rep(s,N) {
    vi score;
    int v = s;
    ll tot = 0;
    while (1) {
      v = P[v];
      score.push_back(C[v]);
      tot += C[v];
      if (v == s) break;
    } 
    int len = score.size();
    ll t = 0;
    rep(i,len) {
      if (i+1 > K) break;
      t += score[i];
      ll now = t;
      if (tot > 0) {
        int rest = (K-i-1)/len;
        now += rest*tot;
      }
      chmax(ans,now);
    }
  }
  printf("%lld\n", ans);
  return 0;
}