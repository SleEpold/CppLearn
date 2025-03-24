#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <list>
#include <cstring>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int INF = 0x7FFFFFFF;
const int N = 1000010;

stack<string> a;

bool isSymbol(string str) {
        if (str == "/" || str == "+" || str == "-" || str == "*")
            return true;
        else
            return false;
    }

    int calculate() {
        string n;
        int x = 0, y = 0;

        if (isSymbol(a.top())) {
            n = a.top();
            a.pop();

            if (isSymbol(a.top()))
                y = calculate();
            else {
                y = stoi(a.top());
                a.pop();
            }

            if (isSymbol(a.top()))
                x = calculate();
            else {
                x = stoi(a.top());
                a.pop();
            }

            if (n == "/")
                return x / y;
            else if (n == "+")
                return x + y;
            else if (n == "-")
                return x - y;
            else if (n == "*")
                return x * y;
            
        } else {
            int s = stoi(a.top());
            a.pop();
            return s;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {

        for (int i = 0; i < tokens.size(); i++) {
            a.push(tokens[i]);
        }

        return calculate();
    }

int main()
{

    vector<string> tokens = {"4","13","5","/","+"};

    cout << evalRPN(tokens);

    return 0;
}



// class Solution {
// public:
//     stack<string> a;

//     bool isSymbol(string str) {
//         if (str == "/" || str == "+" || str == "-" || str == "*")
//             return true;
//         else
//             return false;
//     }

//     int calculate() {
//         string n;
//         int x = 0, y = 0;

//         if (isSymbol(a.top())) {
//             n = a.top();
//             a.pop();

//             if (isSymbol(a.top()))
//                 y = calculate();
//             else {
//                 y = stoi(a.top());
//                 a.pop();
//             }

//             if (isSymbol(a.top()))
//                 x = calculate();
//             else {
//                 x = stoi(a.top());
//                 a.pop();
//             }

//             if (n == "/")
//                 return x / y;
//             else if (n == "+")
//                 return x + y;
//             else if (n == "-")
//                 return x - y;
//             else if (n == "*")
//                 return x * y;
//         } else {
//             int s = stoi(a.top());
//             a.pop();
//             return s;
//         }
//         return 0;
//     }

//     int evalRPN(vector<string>& tokens) {

//         for (int i = 0; i < tokens.size(); i++) {
//             a.push(tokens[i]);
//         }

//         return calculate();
//     }
// };