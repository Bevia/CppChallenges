 g++ -std=c++11 ./GraphTraversalMethods/trie.cpp -o ./GraphTraversalMethods/trie.cpp -o trie 

 ./trie


 ## Theory

 A Trie (pronounced as “try”) is a tree-like data structure used to efficiently store and search for strings, especially when working with prefixes. Each node represents a character of a string, and the path from the root to a node represents a prefix of a string.

Features of a Trie
	1.	Efficient Searching: Finding all strings with a given prefix is fast.
	2.	Insertion and Deletion: Inserting and deleting words are efficient.
	3.	Memory Usage: It can be memory intensive for large datasets due to its node structure.

### Explanation of code:
	1.	TrieNode Class:
	•	Contains a unordered_map<char, TrieNode*> to store children nodes.
	•	Includes a boolean is_end_of_word to mark the end of a word.
	2.	Trie Class:
	•	The insert method traverses each character of the word and creates new nodes if they don’t exist in the current node’s children.
	•	The search method checks if each character of the word exists in the Trie and confirms if the final node is marked as is_end_of_word.
	•	The startsWith method ensures that the prefix exists in the Trie.
	3.	main() Function:
	•	Demonstrates inserting words and performing searches.
