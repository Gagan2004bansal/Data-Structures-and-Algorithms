#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TrieNode
{
public:
    char val;
    TrieNode *children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char val)
    {
        this->val = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        this->isTerminal = false;
    }
};
void InsertWord(TrieNode *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != nullptr)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursion Call
    InsertWord(child, word.substr(1));
}
bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != nullptr)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    bool ans = searchWord(child, word.substr(1));
    return ans;
}
void deleteWord(TrieNode *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != nullptr)
    {
        child = root->children[index];
    }
    else
    {
        return;
    }

    deleteWord(child, word.substr(1));
}
void FindPrefix(TrieNode *root, vector<string> &ans, string &input, string &prefix)
{
    // Base Case
    if (root->isTerminal == true)
    {
        ans.push_back(prefix + input);
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        int index = i - 'a';
        TrieNode *next = root->children[index];
        if (next != nullptr)
        {
            input.push_back(i);
            // Recursive call
            FindPrefix(next, ans, input, prefix);
            // Backtrack
            input.pop_back();
        }
    }
}
void FindWords(TrieNode *root, vector<string> &ans, string input, string prefix)
{

    // Base Case
    if (input.length() == 0)
    {
        TrieNode *lastchar = root;
        FindPrefix(root, ans, input, prefix);
        return;
    }

    char ch = input[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != nullptr)
    {
        child = root->children[index];
    }
    else
    {
        return;
    }

    // Recursive Call
    FindWords(child, ans, input.substr(1), prefix);
}
int main()
{
    TrieNode *root = new TrieNode('-');

    InsertWord(root, "gagan");
    InsertWord(root, "bans");
    InsertWord(root, "bat");
    InsertWord(root, "bansal");
    InsertWord(root, "bansal");
    InsertWord(root, "university");

    cout << searchWord(root, "gagan") << endl;

    // deleteWord(root, "bansal");

    cout << searchWord(root, "university") << endl;

    string input;
    cin >> input;
    vector<string> ans;

    string prefix = input;
    FindWords(root, ans, input, prefix);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}