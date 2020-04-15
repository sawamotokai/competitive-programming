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
ll N;
ll five(int expo) {
  if (N<pow(5,expo)*2) return 0;
  return five(expo+1) + N/((ll)pow(5,expo)*2);
}

int main() {
  cin >> N; 
  if (N&1) {
    cout << 0 << endl; return 0;
  }
  printf("%lld\n", five(1));
  return 0;
}