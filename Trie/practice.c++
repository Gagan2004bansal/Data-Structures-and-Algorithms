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
void insertWord(TrieNode *root, string word)
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
        // present h
        child = root->children[index];
    }
    else
    {
        // absent h
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursion
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode *root, string word)
{
    // Base Case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != nullptr)
    {
        // present toh h
        child = root->children[index];
    }
    else
    {
        return false;
    }

    // Baki Recursion Hu m
    bool ans = searchWord(child, word.substr(1));
    return ans;
}
void deleteWord(TrieNode *root, string word)
{
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
        // present h
        child = root->children[index];
    }
    else
    {
        return;
    }

    // Baki recursion hu m
    deleteWord(child, word.substr(1));
}
void storeString(TrieNode *root, vector<string> &suffix, string &input, string prefix)
{
    // Base Case
    if (root->isTerminal == true)
    {
        suffix.push_back(prefix + input);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        TrieNode *next = root->children[index];
        if (next != NULL)
        {
            // child exist krta h
            input.push_back(ch);
            // recursion call
            storeString(next, suffix, input, prefix);
            // Backtrack
            input.pop_back();
        }
    }
}
void findPrefixString(TrieNode *root, string input, vector<string> &ans, string prefix)
{
    // Base Case
    if (input.length() == 0)
    {
        TrieNode *lastchar = root;
        storeString(root, ans, input, prefix);
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

    // Recursion
    findPrefixString(child, input.substr(1), ans, prefix);
}
// Implementing Phone Directory
vector<vector<string> > PhoneDirectory(TrieNode *root, string word)
{
    vector<vector<string> > output;
    TrieNode *prev = root;
    string Helper = "";

    for (int i = 0; i < word.length(); i++)
    {
        char lastchar = word[i];
        int index = lastchar - 'a';
        TrieNode *curr = prev->children[index];

        if (curr == NULL)
        {
            break;
        }
        else
        {
            vector<string> possibleString;
            Helper.push_back(lastchar);
            string dummy = "";
            storeString(curr, possibleString, Helper, dummy);
            output.push_back(possibleString);

            // Important
            prev = curr;
        }
    }

    return output;
}
int main()
{
    TrieNode *root = new TrieNode('-');

    // Insert kese ??

    insertWord(root, "gagan");
    insertWord(root, "bansal");
    insertWord(root, "bat");
    insertWord(root, "bahh");
    insertWord(root, "ball");
    insertWord(root, "badminton");
    insertWord(root, "university");

    // Search krna h ab

    cout << searchWord(root, "bat") << endl;

    // Delete krne ka man h mera

    // deleteWord(root, "bat");

    // cout << searchWord(root, "bat") << endl;

    string input = "ba";
    vector<string> ans;

    // string prefix = input;
    // findPrefixString(root, input, ans, prefix);

    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // Phone Directory
    vector<vector<string> > res = PhoneDirectory(root, "bad");
    for (int i = 0; i < res.size(); i++)
    {
        cout << i << " : ";
        for (auto ch : res[i])
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}

// start at 01:01 time Trie class - 3