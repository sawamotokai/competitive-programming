#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  ll n,k; cin >> n >>k;
  double ans = 0;
  for (int i=1; i<=n; i++) {
    int r = ceil(log2(k) - log2(i));
    if (r<0) {
      ans += 1.0/n;
      continue;
    }
    ans += 1.0/n * pow(0.5, r); 
  }
  printf("%.15f\n", ans);
  return 0;
}