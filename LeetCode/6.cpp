#include <iostream>
#include <queue>

using namespace std;

int main()
{
  string s = "PAYPALISHIRING";

  int numRows = 3;

  queue<int>
      q;
  string ans = "";
  vector<bool> wasChecked;
  for (int i = 0; i < s.length(); i++)
    wasChecked.push_back(false);

  int headIdx = 0;
  while (headIdx < s.length())
  {
    q.push(headIdx);
    ans += s.at(headIdx);
    wasChecked[headIdx] = true;
    headIdx += 2 * (numRows - 1);
  }

  while (!q.empty())
  {
    int num = q.front();
    q.pop();
    wasChecked[num] = true;
    ans += s.at(num);
    if (num - 1 >= 0 && !wasChecked[num - 1])
      q.push(num - 1);
    if (num + 1 < s.length() && !wasChecked[num + 1])
      q.push(num + 1);
  }
  printf("fasfasfafasfafs");
  return 0;
}
