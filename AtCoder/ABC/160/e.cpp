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
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
const ll INF = 1e18L + 1;

bool comp(ii a, ii b)
{
  return a.first > b.first;
}

int main()
{
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vii apples;
  rep(i, a)
  {
    int x;
    cin >> x;
    apples.push_back(make_pair(x, 1));
  }
  rep(i, b)
  {
    int x;
    cin >> x;
    apples.push_back(make_pair(x, 2));
  }
  rep(i, a)
  {
    int x;
    cin >> x;
    apples.push_back(make_pair(x, 3));
  }
  sort(apples.begin(), apples.end(), comp);
  int c1 = 0, c2 = 0;
  ll ans = 0;
  rep(i, a + b + c)
  {
    ii apple = apples[i];
    if (apple.second == 1 && c1 < x)
    {
      ans += apple.first;
      c1++;
    }
    else if (apple.second == 2 && c2 < y)
    {
      ans += apple.first;
      c2++;
    }
    else if (apple.second == 3)
    {
      if (c1 <　)
    }
  }
  return 0;
}