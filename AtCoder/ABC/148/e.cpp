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
  ll N;
  cin >> N; 
  if (N&1) {
    cout << 0 << endl; return 0;
  }
  N /= 2;
  ll ans = 0;
  while (N >= 5) {
    ans += N/5;
    N /= 5;
  }
  printf("%lld\n", ans);
  return 0;
}