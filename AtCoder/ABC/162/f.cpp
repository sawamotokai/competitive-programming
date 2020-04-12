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
  int N; cin>>N;
  vi A(N);
  rep(i,N) cin>>A[i];
  vector<ll> with(N);
  vector<ll> without(N);
  with[0] = A[0];
  without[0] = 0;

  for(int i=1; i<N; i++) {
    with[i] = without[i-1] + A[i];
    without[i] = max(with[i-1], without[i-1]);
  }
  sort(A.begin(), A.end());
  ll ans =max(with[N-1], without[N-1]);
  if (N&1) {
    ans -= A[N/2];
  }
  cout << ans << endl;
  return 0;
}