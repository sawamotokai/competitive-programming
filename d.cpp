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
  if (p1.first != p2.first)
    return p1.first < p2.first;
  return p1.second > p2.second;
}

int getMin(int j, si &s, int n)
{
  for (int i = j + 1; i <= n; i++)
  {
    if (s.find(i) == s.end())
    {
      s.insert(i);
      return i;
    }
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  vii pairs(n);
  si s;
  map<int, int> mp;
  rep(i, n)
  {
    int a;
    cin >> a;
    s.insert(a);
    mp[a]++;
    pairs[i] = make_pair(a, 0);
  }
  rep(i, n)
  {
    int t;
    cin >> t;
    pairs[i].second = t;
  }
  sort(pairs.begin(), pairs.end(), comp);
  rep(i, pairs.size()) std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
  int ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    }
  rep(i, n - 1)
  {
    if (pairs[i].first == pairs[i + 1].first)
    {
      ans += (getMin(pairs[i].first, s, 1e9) - pairs[i].first) * pairs[i + 1].second;
    }
  }
  cout << ans << endl;
  return 0;
}