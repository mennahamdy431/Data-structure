#include <iostream>
#include "stack.h"

using namespace std;

bool problem2(string brackets) {
    stack<char> stack;
    bool comment = false;

    for (int i = 0; i < brackets.size(); ++i) {

        if ((brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[') && !comment) {
            stack.push(brackets[i]);
        } else if (brackets[i] == '/' && !comment) {

            if (brackets[i + 1] == '*') {
                stack.push(brackets[i]);
                i++;
                stack.push(brackets[i]);
                comment = true;
            }
        } else if ((brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']') && !comment) {
            if (brackets[i] == ')') {
                if (stack.top() == '(')
                    stack.pop();
                else
                    return false;
            } else if (brackets[i] == '}') {
                if (stack.top() == '{')
                    stack.pop();
                else
                    return false;
            } else {
                if (stack.top() == '[')
                    stack.pop();
                else
                    return false;
            }

        } else if (brackets[i] == '*' && comment) {
            if (brackets[i + 1] == '/') {
                stack.pop();
                stack.pop();
                i++;
                comment = false;
            }
        }

    }
    if (stack.size()==0)
        return true;
    else
        return false;
}

int main() {

    (problem2("([{}])(){}[]{[]}"))? cout<<"Valid\n":cout<<"invalid\n";

    (problem2("({)}"))? cout<<"Valid\n":cout<<"invalid\n";

    (problem2("({/*)}]]]]]]}*/})"))? cout<<"Valid\n":cout<<"invalid\n";

    (problem2("({/*[][[]]]]]})"))? cout<<"Valid\n":cout<<"invalid\n";

    (problem2("[{/*******/}]"))? cout<<"Valid\n":cout<<"invalid\n";

}
