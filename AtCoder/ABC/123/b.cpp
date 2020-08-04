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
  vi A(5);
  rep(i,5) cin >> A[i];
  int ans = 0;
  int mn = 11;
  int mnIdx = -1;
  rep(i,5) {
    int m = A[i]%10;
    if (m == 0) m = 10;
    if (m < mn) {
      mn = m;
      mnIdx = i;
    }
  }
  rep(i,5) {
    if (i == mnIdx) {
      ans += A[i];
      continue;
    }
    ans += A[i];
    ans += (10 - (A[i] % 10))%10;
  }
  cout << ans << endl;
  return 0;
}