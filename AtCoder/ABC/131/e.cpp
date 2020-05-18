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
  int n,k; cin >> n >> k;
  int e = (n-1)*(n-2)/2;
  if (k>e) {
    cout << -1 << endl;
    return 0;
  }
  cout << e-k+n-1 << endl;
  int count = 0;
  for (int i=2; i<=n;i++) {
    printf("%d %d\n", 1, i);
  } 
  [&] {
    for (int i=2; i<n; i++) {
      for (int j=i+1; j<=n; j++) {
        if (count == e - k)
          return;
        printf("%d %d\n", i, j);
        count++;
      }
    }
  }();
  return 0;
}