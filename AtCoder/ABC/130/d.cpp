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
  ll n,k; cin >> n>>k;
  vector<ll> a(n); 
  rep(i,n) cin >> a[i];
  int left =0, right=0;
  ll ans = n*(n+1)/2;
  ll sum = 0;
  for (int left =0; left<n; left++) {
    while (right<n && sum+a[right] < k) {
      sum += a[right++];
    } 
    sum -= a[left];
    ans -= right - left;
  }
  printf("%lld\n", ans);
  return 0;
}

