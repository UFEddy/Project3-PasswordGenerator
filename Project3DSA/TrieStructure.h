#pragma once
#include <iostream>
#include <unordered_map>

// https://www.geeksforgeeks.org/introduction-to-trie-data-structure-and-algorithm-tutorials/
// https://www.geeksforgeeks.org/trie-delete/
// https://www.digitalocean.com/community/tutorials/trie-data-structure-in-c-plus-plus
// https://www.geeksforgeeks.org/trie-insert-and-search/
// https://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/
// Referenced AVL Tree Project as template for Trie implementation
class Trie{
    private:
        struct TrieNode {            
            int charCount;
            bool isEndOfWord;
            std::unordered_map<char, TrieNode*> children;           
            TrieNode() : charCount(0), isEndOfWord(false) {}
            ~TrieNode();
        };
        TrieNode* root = nullptr;
        Trie::TrieNode* HelperInsert(TrieNode* root, std::string& word);
        bool HelperSearch(TrieNode* root, std::string word);
        void HelperDestruct(TrieNode* root);

    public:
        Trie(): root(new TrieNode()) {}
        void Insert(std::string& word);
        bool Search(std::string word);
        void Destruct();
};