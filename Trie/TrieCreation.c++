#include <iostream>
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
// Insertion in Trie T.C => O(length of string) but generally we take O(1)
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
        // present
        child = root->children[index];
    }
    else
    {
        // absent
        // Create
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursion Call
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
        // present
        child = root->children[index];
    }
    else
    {
        // Not found
        return false;
    }

    // Recursion
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

    // 1 case
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != nullptr)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // not present
        return;
    }
    // baki recursion
    deleteWord(child, word.substr(1));
}
int main()
{
    TrieNode *root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    cout << "Insertion Done" << endl;

    cout << searchWord(root, "cat") << endl;

    deleteWord(root, "cat");
    cout << searchWord(root, "cat") << endl;

    return 0;
}