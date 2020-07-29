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
  int n,k; cin >> n >> k;
  vll a(n);
  bool zero = false;
  rep(i,n) {
    cin>>a[i];
    if (a[i] == 0) zero = true;
  }
  if (zero) {
    cout << n << endl;
    return 0;
  }
  int l=0, r=0;
  int ans =0;
  ll num = 1;
  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }
  while(r<n && l <= r) {
    while (r < n && num*a[r] <= k) {
      chmax(ans, r - l + 1);
      num*=a[r++];
    }
    if (r==l) r++, l++;
    else num /= a[l++];
  }
  printf("%d\n", ans);
  return 0;
}