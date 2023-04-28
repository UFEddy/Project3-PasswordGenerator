#include "TrieStructure.h"

Trie::TrieNode::~TrieNode() {
  
}

Trie::TrieNode* Trie::HelperInsert(TrieNode* root, std::string& words) {
    
    if (root == nullptr) {
        root = new TrieNode();
    }
    TrieNode* currNode = root;

    // Loop for iterating through each char in string and checking if it matches a Node, if not create a new Node
    for (auto key: words) {
            if (currNode->children.find(key) == currNode->children.end()) {
            TrieNode* newNode = new TrieNode();
            currNode->children[key] = newNode;
        }
        currNode = currNode->children[key];
    }

    // Track Character count and end of word to determine when end of word is reached for search
    currNode->charCount++;
    currNode->isEndOfWord = true;
    return root;
}
void Trie::Insert(std::string& word) {
    this->root = HelperInsert(this->root, word);
}
bool Trie::HelperSearch(TrieNode* root, std::string words) {
    TrieNode* currNode = root;

    // Iterate through all characters in string search for them in the nodes children and return boolean result of isEndOfWord
    for (auto key: words) {

        if (currNode->children.find(key) == currNode->children.end()) {
            return false;
        }
        currNode = currNode->children[key];
    }
    return (currNode->isEndOfWord);
}
bool Trie::Search(std::string word) {
    return HelperSearch(this->root, word);
}
void Trie::HelperDestruct(TrieNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // Iterate through all node and children calling helper destruct to delete nodes
    for (auto key: root->children) {
        HelperDestruct (key.second);
    }

    delete root;
}
void Trie::Destruct() {
    HelperDestruct(this->root);
}