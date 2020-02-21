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
typedef stack<int> stk;

int main()
{
  int n;
  cin >> n;
  vector<stk> stacks;
  rep(i, n)
  {
    int w;
    cin >> w;
    if (stacks.size() == 0)
    {
      stack<int> s;
      s.push(w);
      stacks.push_back(s);
    }
    else
    {
      bool found = false;
      for (int i = 0; i < stacks.size(); i++)
      {
        int top = stacks[i].top();
        if (top >= w)
        {
          stacks[i].push(w);
          found = true;
          break;
        }
      }
      if (!found)
      {
        stack<int> s;
        s.push(w);
        stacks.push_back(s);
      }
    }
  }

  std::cout << stacks.size() << std::endl;

  return 0;
}