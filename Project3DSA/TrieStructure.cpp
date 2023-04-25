#include "TrieStructure.h"

Trie::TrieNode::~TrieNode() {
  
}

Trie::TrieNode* Trie::HelperInsert(TrieNode* root, std::string& words) {
    
    if (root == nullptr) {
        root = new TrieNode();
    }
    TrieNode* currNode = root;

    for (auto key: words) {
            if (currNode->children.find(key) == currNode->children.end()) {
            TrieNode* newNode = new TrieNode();
            currNode->children[key] = newNode;
        }
        currNode = currNode->children[key];
    }
    currNode->charCount++;
    currNode->isEndOfWord = true;
    return root;
}
void Trie::Insert(std::string& word) {
    this->root = HelperInsert(this->root, word);
}
bool Trie::HelperSearch(TrieNode* root, std::string words) {
    TrieNode* currNode = root;

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
    
    for (auto key: root->children) {
        HelperDestruct (key.second);
    }

    delete root;
}
void Trie::Destruct() {
    HelperDestruct(this->root);
}