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
  vi p(n); rep(i,n) cin >> p[i];
  int ans = 0;
  auto comp = [](int a, int b, int c) {
    return (a < b && b < c) || (a > b && b > c);
  };
  for (int i=1; i<n-1; i++) {
    if (comp(p[i-1], p[i], p[i+1])) ans++;
  }
  cout << ans << endl;
  return 0;
}