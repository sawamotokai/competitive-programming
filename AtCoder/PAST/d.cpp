#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
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
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

void findNum(vector<string> num) {
  int out=-1;
  if (num[0][0] == '.') out =1;
  else if (num[2][1] == '.' && num[1][0] == '#') out = 0;
  else if (num[1][0] == '.' && num[3][2] == '.') out = 2;
  else if (num[1][0] == '.' && num[3][0] == '.' && num[2][0] == '#') out = 3;
  else if (num[0][1] == '.') out = 4;
  else if (num[1][2] == '.' && num[3][0] == '.') out = 5;
  else if (num[1][2] == '.') out = 6;
  else if (num[2][1] == '.') out = 7;
  else if (num[3][0] == '#') out = 8;
  else out = 9;
  cout << out;
}

int main() {
  int n; cin >> n;
  vector< string> board(5);
  rep(i, 5) cin >> board[i];
  rep(i,n) {
    int upperLeft = i*4 + 1;
    vector<string> num(5);
    rep(j,5) {
      num[j] = board[j].substr(upperLeft, 3);
    }
    findNum(num);
  }
  cout << endl;
  return 0;
}