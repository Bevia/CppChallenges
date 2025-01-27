#include <iostream>
#include <vector>

using namespace std;

vector<string> permutations(string& str){

    sort(str.begin(), str.end());

    if (str.length()==1){
        return{str};
    }

    vector<string> permList;

    for (size_t i = 0; i < str.length(); ++i){
        char currentChar = str[i];
        string remainingChars = str.substr(0,i)+str.substr(i+1);
        vector <string> perms = permutations(remainingChars);
        for (const string perm : perms){
            permList.push_back(currentChar + perm);
        }
    }
    return permList;
}

int main(){

    string str = "BAC";
    vector<string> result = permutations(str);

    for (const string perms: result){
        cout << perms << " ";
    }
    cout << endl;


    return 0;
}