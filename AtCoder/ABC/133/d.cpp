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
  int n; cin >> n; 
  vector<ll> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i] *= 2;
  }
  ll key = a[n-1];
  rep(i, n-1) {
    ll adder = a[i];
    if (!(i&1)) adder *= -1;
    key += adder;
  }
  key /= 2;
  vi ans(n);
  ans[n-1] = key;
  for (int i=n-2; i>=0; i--) {
    ans[i] = a[i] - ans[i+1];
  }
  rep(i,n) cout << ans[i] << endl;
  return 0;
}