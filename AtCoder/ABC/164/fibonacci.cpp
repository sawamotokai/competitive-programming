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
  auto fibo = [](int k) {
    double left = (5+sqrt(5))/10 * pow((1+sqrt(5)/2), k) * (1+sqrt(5))/2;
    double right = (5-sqrt(5))/10 * pow((1-sqrt(5)/2), k) * (1-sqrt(5))/2;
    return left + right;
  };
  int k; cin >> k;
  cout << fibo(k) << endl;
  return 0;
}