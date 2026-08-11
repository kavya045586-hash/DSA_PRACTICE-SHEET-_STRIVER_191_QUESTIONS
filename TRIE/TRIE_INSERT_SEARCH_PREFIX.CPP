// Question: Implement Trie (Prefix Tree)
// Source: Striver DSA Sheet - Trie Problems

struct Node {
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        flag = false;
    }

    bool containskey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void end() {
        flag = true;
    }

    bool isend() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->end();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isend();
    }

    bool startsWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};
