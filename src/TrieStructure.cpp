#include "TrieStructure.h"

Trie::TrieNode::~TrieNode() {
   //Destruct();
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

Trie::TrieNode* Trie::HelperDelete(TrieNode* root, std::string word, int depth) {
    if (root == nullptr) {
        return root;
    }

    if(depth == word.size()) {
        if (root->isEndOfWord) {
            root->charCount--;
            root->isEndOfWord = false;
        }

        if(root->charCount == 0) {
            delete root;
            return nullptr;
        }
    }
    return root;
}

void Trie::Delete(std::string word, int depth) {
    HelperDelete(this->root, word, depth);
}

void Trie::HelperDestruct(TrieNode* root) {
    if (root == nullptr) {
        return;
    }
    
    for (int i = 0; i < CHAR_SIZE; i++) {
        HelperDestruct (root->children[i]);
    }

    delete root;
}

void Trie::Destruct() {
    HelperDestruct(this->root);
}