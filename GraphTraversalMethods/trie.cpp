#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Map to store child nodes
    bool is_end_of_word = false; // Indicates the end of a word
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode(); // Add a new node if it doesn't exist
            }
            node = node->children[ch]; // Move to the next node
        }
        node->is_end_of_word = true; // Mark the end of the word
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false; // Character not found
            }
            node = node->children[ch]; // Move to the next node
        }
        return node->is_end_of_word; // Check if it's the end of a word
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false; // Prefix not found
            }
            node = node->children[ch]; // Move to the next node
        }
        return true; // Prefix exists
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("batman");
    trie.insert("apply");
    trie.insert("bats");

    // Search for full words
    cout << boolalpha; // Print "true" or "false" for boolean values
    cout << trie.search("apple") << endl;   // Output: true
    cout << trie.search("app") << endl;     // Output: true
    cout << trie.search("bat") << endl;     // Output: true
    cout << trie.search("batman") << endl;  // Output: true
    cout << trie.search("apply") << endl;   // Output: true
    cout << trie.search("batwoman") << endl; // Output: false

    return 0;
}