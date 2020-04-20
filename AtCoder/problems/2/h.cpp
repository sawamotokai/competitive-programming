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

int main() {
  int N,L; cin >>N;
  cin >> L;
  vector<string> kuji(L);
  rep(i, L) {
    cout << i << endl;
    string s;
    getline(cin,s);
    kuji[i] = s;
    cout << kuji[i] << endl;
  }
  puts("size of kuji");
  cout << kuji[0] << endl;
  cout << kuji[1] << endl;
  string bottom; getline(cin, bottom);
  int start;
  rep(i, bottom.length()) {
    if (bottom[i] == 'o') start=i;
  }
  for (int i=L-1; i>=0; i--) {
    int dir=0;
    if (start && kuji[i][start-1] == '-') {
      dir = -2;
      cout << kuji[i][start-1] << endl;
    } 
    if (start+1<2*N-1 && kuji[i][start+1] == '-') {
      dir = 2;
      cout << kuji[i][start-1] << endl;
    }
    cout << kuji[i][start+1] << endl;
    start+=dir;
    cout << start << endl;
  }
  cout << start/2 + 1 << endl;
  return 0;
}