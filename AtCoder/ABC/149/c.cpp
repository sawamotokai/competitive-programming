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
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 


bool prime(int n) {
  for (int i=2; i*i<=n; i++){
    if (n%i==0) return false;
  }
  return true; 
}

int main() {
  int x; cin>>x;
  do {
    if (prime(x)) {
      cout << x << endl;
      return 0;
    }
  } while (x++);
  return 0;
}