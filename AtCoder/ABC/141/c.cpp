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
  int n,k,q; cin >> n >> k >> q;
  vi a(n, k-q);
  rep(i,q) {
    int foo; cin >> foo;
    foo--;
    a[foo]++;
  }
  rep(i,n) {
    string out;
    if (a[i] <= 0) out = "No";
    else out = "Yes";
    cout << out << endl;
  }
  return 0;
}