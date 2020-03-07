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

int main()
{
  string S;
  int Q;
  cin >> S >> Q;
  int reverseCount = 0;
  string front = "";
  string back = "";
  rep(_, Q)
  {
    int T;
    cin >> T;

    if (T == 1)
    {
      // reverse S
      reverseCount++;
    }
    else
    {
      int F;
      cin >> F;
      char c;
      cin >> c;
      if (F == 1)
      {
        // prepend c
        if (reverseCount & 1)
          back += c;
        else
          front += c;
      }
      else
      {
        // append c
        if (reverseCount & 1)
          front += c;
        else
          back += c;
      }
    }
  }
  reverse(front.begin(), front.end());
  S.append(back);
  S.insert(0, front);
  if (reverseCount & 1)
    reverse(S.begin(), S.end());

  cout << S << endl;
  return 0;
}