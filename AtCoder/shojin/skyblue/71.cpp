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
  int start = 0;
  rep(i,N) {
    int a = A[i];
    mp[a]++;
    if (mp[a] == 1) cnt++;
    if (cnt == C) {
      start = i;
      break;
    } 
  }
  int left = 0;
  for (int i=start+1; i<N;) {
    do {
      ans += N - i - 1;
      mp[A[left]]--;
    } while (mp[A[left++]] != 0);
    do {
      mp[A[i]]++;
    } while (mp[A[i++]] != 1);
  } 
  printf("%lld\n", ans);
  return 0;
}