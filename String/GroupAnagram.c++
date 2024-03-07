// Group Anagram :: Leetcode 42
// link - https://leetcode.com/problems/group-anagrams/?envType=daily-question&envId=2024-02-06
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
vector<vector<string> > Solution(vector<string> array)
{
    vector<vector<string> > groups;                 // <--- Store the answer string vector
    unordered_map<string, vector<string> > mapping; // <--- Map the string with their anagram

    for (int i = 0; i < array.size(); i++)
    {
        string word = array[i];
        sort(word.begin(), word.end());
        mapping[word].push_back(array[i]);
    }

    for (auto it : mapping)
    {
        groups.push_back(it.second);
    }

    return groups;
}
int main()
{
    int m;
    cout << "Enter number of string : ";
    cin >> m;
    vector<string> array;
    for (int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        array.push_back(input);
    }

    vector<vector<string> > ans = Solution(array);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << " | ";
    }
    cout << endl;

    return 0;
}