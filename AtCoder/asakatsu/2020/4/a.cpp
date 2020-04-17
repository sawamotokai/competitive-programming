#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n; cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end(), [](int a, int b) {return a>b;});
  int ans=0;
 rep(i,n) {
    if(!(i&1)) ans+=a[i];
    else ans -= a[i];
  }
  cout << ans << endl;
  return 0;
}