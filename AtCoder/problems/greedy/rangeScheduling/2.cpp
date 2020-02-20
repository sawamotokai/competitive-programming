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

bool comp(ii p1, ii p2)
{
  return (p1.first + p1.second) < (p2.first + p2.second);
}

int main()
{
  int N;
  cin >> N;
  vector<ii> pos(N);
  rep(i, N)
  {
    int a, b;
    cin >> a >> b;
    pos[i] = make_pair(a, b);
  }
  sort(pos.begin(), pos.end(), comp);

  int rightMost = pos[0].first + pos[0].second;
  int ans = N;
  for (int i = 1; i < N; i++)
  {
    if (pos[i].first - pos[i].second < rightMost)
    {
      ans--;
    }
    else
    {
      rightMost = pos[i].first + pos[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}