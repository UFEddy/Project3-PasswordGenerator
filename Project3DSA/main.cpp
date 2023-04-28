#include "Set.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "TrieStructure.h"

int main() {
    Set pass;
    int input = 0;
    string searchSet;
    Trie passTrie;
    //opens the file
    ifstream infile("rockyou.txt");
    if (infile.is_open()) {
        string line;
        //inserts each line of the text into the set and the trie
        while (getline(infile, line)) {
           pass.insert(line);
           passTrie.Insert(line);
        }
        infile.close();
    } else {
        cout << "Unable to open file" << std::endl;
    }
    //displays menu until user input is 4 for exit
    while (input != 4){
        cout << " || MENU ||" << endl;
        cout << "1. Search for common password using set" << endl;
        cout << "2. Search for common password using trie" << endl;
        cout << "3. Make a strong password" << endl;
        cout << "4. Exit" << endl;
        cin >> input;
        //searches for password into the set
        if (input == 1){
            cout << "What password would you like to search? " << endl;
            cin >> searchSet;
            if (pass.search(searchSet) == true){
                cout << "Password is found in set! " << endl;
            }
            else {
                cout << "Password is not found in set. " << endl;
            }
        }
        //searces for password into the trie
        if (input == 2){
            cout << "What password would you like to search? " << endl;
            cin >> searchSet;
            if (passTrie.Search(searchSet)){
                cout << "Password is found in Trie! " << endl;
            }
            else {
                cout << "Password is not found in Trie. " << endl;
            }
        }
        //makes the random password
        if(input == 3){
            srand((unsigned) time(NULL));
            int length, letters, numbers, special;
            string final;
            //asks for user input for cretieria such as length, letters, special characters, and numbers
            cout << "How many characters would you like the password be? " << endl;
            cin >> length;
            cout << "How many letters would you like the password to have? " << endl;
            cin >> letters;
            cout << "How many numbers would you like the password to have? " << endl;
            cin >> numbers;
            cout << "How many special characters would you like the password to have? " << endl;
            cin >> special;
            string possible_special = "!@#$%^&*()_+-=[]{};:,.<>?";
            //if the letters, numbers, and special characters do not add up, ask again
            while ((letters + numbers + special) != length){
                cout << "Error, please try again" << endl;
                cout << "How many characters would you like the password be? " << endl;
                cin >> length;
                cout << "How many letters would you like the password to have? " << endl;
                cin >> letters;
                cout << "How many numbers would you like the password to have? " << endl;
                cin >> numbers;
                cout << "How many special characters would you like the password to have? " << endl;
                cin >> special;
            }
            //adds numbers 0-9 to the final string
            for(int i = 0; i < numbers; i++){
                final += to_string(rand() % 10);
            }
            //adds lowercase letters to the final string
            for(int i = 0; i < letters; i++){
                final +=  'a' + rand()%26;
            }
            //adds special characters to the final string
            for(int i = 0; i < special; i++){
                int random_index = rand() % possible_special.length();
                final += possible_special[random_index];
            }
            //scrambles the final string
            for (int i = final.length() - 1; i > 0; i--) {
                int j = rand() % (i + 1);
                char temp = final[i];
                final[i] = final[j];
                final[j] = temp;
            }
            //outputs the final string
            cout << "You're new password is: " << final << endl;
        }
    }
        //userinput = 4
        cout << "Thanks for using the random password generator! " << endl;
    return 0;
}
