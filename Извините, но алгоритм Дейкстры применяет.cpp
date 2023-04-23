Извините, но алгоритм Дейкстры применяется для нахождения кратчайшего пути в графе, поэтому он не может быть использован для конвертации инфиксного выражения в постфиксное. Вместо этого можно использовать алгоритм сортировочной станции (шунтинг-ярд). Вот простой пример кода на C++:

```c++
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }

    return 0;
}

string infixToPostfix(string infix) {
    stack<char> stack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }

            stack.pop();
        } else {
            while (!stack.empty() && getPriority(c) <= getPriority(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }

            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix = "1 + 2 * (3 - 4)";
    string postfix = infixToPostfix(infix);

    cout << postfix << endl;

    return 0;
}
```