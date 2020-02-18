#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef long long ll;

long long long sixbonacci(int n)
{
  vector<long long long> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 8;
  dp[5] = 16;
  for (int i = 6; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
  return dp[n];
}

ll fibonacci(int n)
{
  vector<ll> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}

// struct TreeNode
// {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// vector<vector<int>> levelOrderTraversal(Node *root)
// {
//   vector<vector<int>> ans;
//   if (!root)
//     return ans;
//   queue<Node *> nextLevel;
//   queue<Node *> curLevel;
//   nextLevel.push(root);
//   while (!nextLevel.empty())
//   {
//     while (!nextLevel.empty())
//     {
//       curLevel.push(nextLevel.front());
//       nextLevel.pop();
//     }
//     vector<int> temp;
//     while (!curLevel.empty())
//     {
//       Node *t = curLevel.front();
//       curLevel.pop();
//       temp.push_back(t->val);
//       if (t->left)
//         nextLevel.push(t->left);
//       if (t->right)
//         nextLevel.push(t->right);
//     }
//     ans.push_back(temp);
//   }
//   return ans;
// }

int main()
{
  cout << sixbonacci(610) << endl;
  return 0;
}
