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
typedef long long ll;
const ll INF = 1e18L + 1;

int main() {
  int n;
  cin >> n;
  string base = "";
  rep(i, n) base += 'a' + i;
  set<string> s;
  for (int i = (1<<n)-1; i >= 0; i--)
  {
    string str = base;
    // for (int j = 0; j < n; j++)
    int firstOne;
    for (int j = n-1; j >= 0; j--)
    {
      if (1 & (i >> j)) {
        firstOne = (n-j)-1;break;
      }
    }
    for (int j = n-1; j >= 0; j--)
    {
      if (1 & (i >> j))
      {
        str[n-j-1] = base[firstOne];
      }
    }
    // cout << str << endl;
    s.insert(str);
  }
  for (auto it=s.begin(); it!=s.end(); it++)
    cout << *it <<endl;
  
  return 0;
}