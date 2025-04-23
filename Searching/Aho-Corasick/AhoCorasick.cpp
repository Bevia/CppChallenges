#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    Node* failLink; // Failure link
    vector<string> output; // Store matched patterns

    Node() : failLink(nullptr) {}
};

class AhoCorasick {
private:
    Node* root;

public:
    AhoCorasick() {
        root = new Node();
    }

    // Add a word to the trie
    void addWord(const string& word) {
        Node* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new Node();
            }
            current = current->children[c];
        }
        current->output.push_back(word); // Mark the end of the word
    }

    // Build the failure links
    void build() {
        queue<Node*> q;
        for (auto& pair : root->children) {
            pair.second->failLink = root; // Root-level children fail to root
            q.push(pair.second);
        }

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (auto& pair : current->children) {
                char c = pair.first;
                Node* child = pair.second;

                // Set the fail link
                Node* fail = current->failLink;
                while (fail && fail->children.find(c) == fail->children.end()) {
                    fail = fail->failLink;
                }
                child->failLink = fail ? fail->children[c] : root;

                // Combine output from the fail link
                if (child->failLink) {
                    child->output.insert(child->output.end(),
                                         child->failLink->output.begin(),
                                         child->failLink->output.end());
                }

                q.push(child);
            }
        }
    }

    // Search for patterns in the text
    void search(const string& text) {
        Node* current = root;
        for (size_t i = 0; i < text.size(); i++) {
            char c = text[i];

            // Follow fail links on mismatch
            while (current && current->children.find(c) == current->children.end()) {
                current = current->failLink;
            }
            current = current ? current->children[c] : root;

            // Output all matched patterns
            if (current && !current->output.empty()) {
                for (const string& word : current->output) {
                    cout << "Found '" << word << "' at index " << i - word.size() + 1 << endl;
                }
            }
        }
    }
};

int main() {
    AhoCorasick ac;
    vector<string> keywords = {"he", "she", "his", "hers"};
    for (const string& keyword : keywords) {
        ac.addWord(keyword);
    }

    ac.build();

    string text = "ushers";
    ac.search(text);

    return 0;
}
