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

int inf  = 1e9;
int A[1005], B[1005];

int dp[10005];

int main() {
  fill(dp, dp+10005, inf);
  dp[0] = 0;
  int H,N; 
  cin >> H>>N;
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
// dp[i] := min total magic power used to decrease the monster's life by i
  for (int i=0; i<N; ++i) {
    for (int j=0; j<H; j++) {
      int nj = min(j+A[i], H);
      dp[nj] = min(dp[nj], dp[j]+B[i]);
    }
  }
  // rep(i,H) cout << dp[i] << endl;
  cout << dp[H] << endl;
  return 0;
}