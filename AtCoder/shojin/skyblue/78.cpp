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

ll N,C;
int main() {
  cin >> N >> C;
  vi a(N);
  rep(i,N) cin >> a[i];
  rep(i,N) a[i]--;
  vvi cnt(N);
  vi p(N,-1);
  vll ans(C, N*(N+1)/2);
  rep(i,N) {
    int num = a[i];
    int prev = p[num];
    int l = i - (prev + 1);
    p[num] = i;
    cnt[num].push_back(l);
  }
  rep(i,C) {
    int l = N - (p[i] + 1);
    cnt[i].push_back(l);
  }
  rep(i,C) {
    for (ll r: cnt[i]) {
      ans[i] -= r*(r+1)/2;
    }
    printf("%lld\n", ans[i]);
  }
  return 0;
}