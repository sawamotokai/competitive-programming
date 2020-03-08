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

ii A[200010];

bool comp(ii p1, ii p2)
{
  if (p1.first == p2.first)
    return p1.second < p2.second;
  return p1.first > p2.first;
}

int main()
{
  int N, T;
  cin >> N >> T;

  rep(i, N)
  {
    int a, b;
    cin >> a >> b;
    A[i] = make_pair(a, b);
  }
  sort(A, A + N, comp);
  int ans = 0;
  rep(i, N)
  {
    int t = 0;
    int j = 0;
    int count = 0;
    while (j + i < N && t <= T)
    {
      t++;
      t += (t * A[j + i].first + A[j + i].second);
      j++;
      if (t <= T)
        count++;
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
  return 0;
}