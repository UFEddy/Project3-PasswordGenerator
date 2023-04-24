#include <iostream>
#include <fstream>
#include <sstream>
#include "TrieStructure.h"

void PrintMenu();

int main () {

    // Test input
    Trie myTrie;
    std::string file = "archive/rockyou.txt";
    std::string passwords;
    

    std::cout << "Loading Dataset..." << std::endl;
    std::ifstream inFile(file);
    if (inFile.is_open()) {        
        while (std::getline(inFile, passwords)) {
            myTrie.Insert(passwords);
        }                              
    }
    inFile.close();
    std::cout << "Dataset has been loaded!" << std::endl;

    PrintMenu();

    int input = 0;
    bool datasetLoaded = true;
    std::cin >> input;
    while(input != 2) {
        if(input == 1) {
            std::string word;
            std::cout << "Type in password to search for in database: ";
            std::cin >> word;
            if(myTrie.Search(word)) {
                std::cout << "The password: " << word << " was found in the dataset!" << std::endl;
            }
            else {
                std::cout << "The password: " << word << " was NOT found in the dataset" << std::endl;
            }
        }
        else {
            std::cout << "Incorrect Input" << std::endl;
        } 
      
        PrintMenu();
        std::cin >>input;
    }

    // Destruct Trie
    //myTrie.Destruct();

    return 0;
}

void PrintMenu() {
    std::cout << std::endl;
    std::cout << "Password Searcher Beta" <<std::endl;
    std::cout << "1. Search for Password" << std::endl;
    std::cout <<"2. Exit" << std::endl;
}