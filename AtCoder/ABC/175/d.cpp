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
  ll tot = 0;
  rep(i,N) tot += C[i];
  ll loop = K/N;
  ll rest = K%N;
  // possiblity 1 : loop many times and go as much as possilbe from all N
  // possilbity 2 : go as much as possible from all i in N;
  // 1:
  ll ans =-LINF;
  ll mx = -LINF;
  rep(i,N) {
    ll temp = 0;
    ll localMax = -LINF; 
    ll v = i;
    rep(j, rest) {
      temp += C[P[v]];
      chmax(localMax, temp);
      v = P[v];
    }
    chmax(mx, localMax);
  }

  ll now = tot * loop;
  if (now > 0) mx += now;
  chmax(ans , mx);

  //2 :
  mx = -LINF;
  rep(i,N) {
    ll temp = 0;
    ll localMax = -LINF; 
    ll v = i;
    rep(j, min(N,K)) {
      temp += C[P[v]];
      chmax(localMax, temp);
      v = P[v];
    }
    chmax(mx, localMax);
  }
  chmax(ans , mx);
  printf("%lld\n", ans);
  return 0;
}