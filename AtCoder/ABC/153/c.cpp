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

int H[200010];
int main() {
  int N,K; cin>>N>>K;
  rep(i,N) cin>>H[i];
  sort(H, H+N, [](int a, int b){return a>b;});
  ll ans =0;
  for (int i=K; i<N; i++) {
    ans+=H[i];
  }
  cout << ans <<endl;
  return 0;
}