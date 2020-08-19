#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

string S;
int main() {
  cin >> S;
  string year = S.substr(0,4);
  string month = S.substr(5,2);
  string day = S.substr(8,2);
  int y=stoi(year);
  int m=stoi(month);
  int d=stoi(day);
  if (y < 2019) {
    cout << "Heisei" << endl;
    return 0;
  } else if (y > 2019) {
    cout << "TBD" << endl;
    return 0;
  }

  if (m < 5) {
    cout << "Heisei" << endl;
    return 0;
  } else {
    cout << "TBD" << endl;
    return 0;
  }
  return 0;
}