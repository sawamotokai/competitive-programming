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

int A[110];
int B[110];

int main()
{
  int t, n, m;
  cin >> t >> n;
  rep(i, n) cin >> A[i];
  cin >> m;
  rep(i, m) cin >> B[i];
  int takoyaki = 0;
  int sold = 0;
  rep(i, m)
  {
    while (takoyaki < n)
    {
      if (A[takoyaki] <= B[i] && A[takoyaki] + t >= B[i])
      {
        takoyaki++;
        sold++;
        break;
      }
      takoyaki++;
    }
  }
  if (sold != m)
  {
    puts("no");
    return 0;
  }
  puts("yes");

  return 0;
}