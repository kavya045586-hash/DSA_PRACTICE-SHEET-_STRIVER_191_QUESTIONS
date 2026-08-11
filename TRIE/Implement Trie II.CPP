/*
 Implement Trie II
--------------------------------
A Trie is a tree-like data structure used to efficiently store and retrieve prefixes of a collection of strings.

Implement the following functionalities:

Trie(): Initializes a Trie object
void insert(string word): Inserts the string word into the Trie
int countWordsEqualTo(string word): Returns the number of instances of the string word in the Trie
int countWordsStartingWith(string prefix): Returns the number of strings in the Trie that start with the prefix prefix
void erase(string word): Removes the string word from the Trie
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int wordCount;     // number of words ending at this node
    int prefixCount;   // number of words passing through this node

    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        wordCount = 0;
        prefixCount = 0;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->prefixCount++;
        }
        node->wordCount++;
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->wordCount;
    }

    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->prefixCount;
    }

    void erase(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return; // word not present
            node = node->get(ch);
            node->prefixCount--;
        }
        node->wordCount--;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("app");

    cout << trie.countWordsEqualTo("app") << endl;       // Output: 2
    cout << trie.countWordsStartingWith("app") << endl;  // Output: 3
    cout << trie.countWordsStartingWith("appl") << endl; // Output: 1

    trie.erase("app");
    cout << trie.countWordsEqualTo("app") << endl;       // Output: 1
}
