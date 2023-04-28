//
// Created by Maitri Jajoo on 4/21/23.
//

#include <set>
#include <string>

using namespace std;
class Set
{
    public:
        set<string> passList;
        void insert (string password);
        bool search(string password);
};
//inserts password to the set 
void Set::insert(string password){
    passList.insert(password);
}
//returns true if the password is found or false if not found 
bool Set::search(string password) {
    auto search = passList.find(password);
    if (search != passList.end()) {
        return true;
    }
   else {
       return false;
   }
}
