#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s){
    stack<char> par;
    for(int i = 0; i < s.length(); ++i ){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            par.push(s[i]);
        else{
            if( (par.empty() || (par.top() == '(' && s[i] != ')') || (par.top() == '{' && s[i] != '}') || (par.top() == '[' && s[i] != ']'))){
                return false;
            }
            par.pop();
        }
    }
    return par.empty();
}

int main (){
    string s = "({}[(){[{[[{{([{([([{}])])}])}}]]}]}])";
    cout << isValid(s) << endl;
}