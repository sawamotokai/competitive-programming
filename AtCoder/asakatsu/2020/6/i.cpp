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
  int N; cin>>N;
  vector<ll> d(N);
  rep(i,N) cin >> d[i];
  sort(d.begin() , d.end());
  vector<ll> d2(N-1);
  rep(i, N-1) d2[i] = d[i+1] - d[i];
  ll ans =0;
  rep(i, N-1) {
    ans += d2[i] * (N-i-1) * (i+1);
  }
  printf("%lld\n", ans );
  return 0;
}