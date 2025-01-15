 g++ -std=c++11 ./GraphTraversalMethods/trie.cpp -o ./GraphTraversalMethods/trie.cpp -o trie 

 ./trie


 ## Theory

 Explanation:
	1.	TrieNode Class:
	•	Contains a unordered_map<char, TrieNode*> to store children nodes.
	•	Includes a boolean is_end_of_word to mark the end of a word.
	2.	Trie Class:
	•	The insert method traverses each character of the word and creates new nodes if they don’t exist in the current node’s children.
	•	The search method checks if each character of the word exists in the Trie and confirms if the final node is marked as is_end_of_word.
	•	The startsWith method ensures that the prefix exists in the Trie.
	3.	main() Function:
	•	Demonstrates inserting words and performing searches.
