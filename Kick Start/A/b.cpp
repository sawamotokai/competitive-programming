#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
typedef long long ll;
const ll INF = 1e18L + 1;

int ans = 0;

int main()
{
  int t;
  cin >> t;
  rep(_, t)
  {
    int N, K, P;
    cin >> N >> K >> P;
    vvi plates(N, vi(K, 0));
    rep(i, N) rep(j, K) cin >> plates[i][j];
    }
  return 0;
}