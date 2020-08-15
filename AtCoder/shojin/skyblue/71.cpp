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
  // indeed now elimination b
  int N, C; cin >> N >> C;
  map<int,int> mp;
  vi A(N);
  rep(i,N) cin >> A[i];
  ll ans = 0;
  int cnt = 0;
  int r = 0;
  int l = 0;
  rep(i,N) {
    int a = A[i];
    mp[a]++;
    if (mp[a] == 1) cnt++;
    if (cnt == C) {
      r = i;
      break;
    } 
  }
  ans += (N-r);
  for (; l < N; l++) {
    mp[A[l]]--;
    assert(cnt == C);
    if (mp[A[l]] == 0) {
      mp.erase(A[l]);
      cnt--;
    }
    while (cnt < C && r < N) {
      mp[A[r]]++;
      if (mp[A[r]] == 1) cnt++;
      r++;
    }
    assert(r <= N);
    ans+=N-r;
  }
  printf("%lld\n", ans);
  return 0;
}