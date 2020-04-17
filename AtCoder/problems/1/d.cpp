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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n; cin >> n;
  vi a(n-1);
  rep(i,n-1) {
    cin >> a[i];
  }
  cout << a[0] << ' ';
  rep(i,n-2) {
    if (a[i]<a[i+1]) {
      cout << a[i] << ' ';
    } else cout << a[i+1] << ' ';
  }

  cout << a[n-2] << endl;
  return 0;
}