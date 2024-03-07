#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Solution(vector<string> &ans, string path, int left, int right)
{
    // Base Condition
    if (left == 0 && right == 0)
    {
        ans.push_back(path);
        return;
    }

    // Condition
    if (left > right || left < 0 || right < 0)
    {
        return;
    }
    // Calling
    path.push_back('(');
    Solution(ans, path, left - 1, right);
    path.pop_back(); // <--- pop last element

    path.push_back(')');
    Solution(ans, path, left, right - 1);
    path.pop_back(); // <--- pop last element

    return;
}
int main()
{
    int n;
    cin >> n;
    string path = "";
    vector<string> ans;

    Solution(ans, path, n, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}