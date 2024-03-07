#include <iostream>
#include <vector>
using namespace std;
void Solution(int n, int k, int start, vector<vector<int> > &ans, vector<int> &temp)
{
    // Base Case
    if (temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i <= n; i++)
    {
        temp.push_back(i);
        Solution(n, k, i + 1, ans, temp);
        temp.pop_back();
    }

    return;
}
int main()
{
    int n;
    cout << "Enter N : " << endl;
    cin >> n;

    int k;

    vector<vector<int> > ans;
    vector<int> temp;
    int start = 1;

    for (int i = 1; i <= n; i++)
    {
        k = i;
        Solution(n, k, start, ans, temp);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}