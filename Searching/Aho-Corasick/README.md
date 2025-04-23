## Theory

The Aho-Corasick algorithm is a powerful and efficient algorithm used for multi-pattern string searching. 
It allows you to find occurrences of multiple keywords in a given text in linear time, 
making it very useful for tasks like text analysis, searching in DNA sequences, or network intrusion detection.

The algorithm constructs a trie (prefix tree) from the set of keywords and 
adds "failure links" to facilitate efficient searching. These failure links ensure 
that when a mismatch occurs, the algorithm quickly transitions to the next possible 
state without starting over from the root of the trie.

## How It Works:
Adding Words to the Trie:
The addWord() method builds a trie structure for the keywords.
Building Failure Links:
The build() method uses a breadth-first search (BFS) to create failure links and combine outputs from the fail links.
Searching:
The search() method processes the input text character by character, using the trie and failure links to find matches efficiently.
Output Example:
For the text "ushers" and the keywords ["he", "she", "his", "hers"], the output will be:

Found 'she' at index 2
Found 'he' at index 3
Found 'hers' at index 1
