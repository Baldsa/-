    //напиши алгоритм дейкстры для получение постфиксного выражения
    #include <iostream>
    #include <stack>
    #include <vector>
    #include <cstring>
    #include <string>
    #include <map>

    int priory(char);
    std::string infixToPostfix(std::string);



    int main() {
        setlocale(LC_ALL, "Russian");
        std::string us_string;
        std::cout << "Write an example ";
        std::getline(std::cin, us_string);
        std::cout << "Expression before conversion " << us_string << '\n';
        std::string postfix = infixToPostfix(us_string);
        std::cout << "Expression after conversion " << postfix << std::endl;
    }

    int priory(char us_sym) {
        switch (us_sym)
        {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;

        }

    }

    std::string infixToPostfix(std::string us_string) {
        std::stack<char> stack;
        std::string postfix = "";
        for (char i : us_string) {
            if (isdigit(i)) {
                postfix += i;
            }
            else if (i == '(') {
                stack.push(i);
            }
            else if (i == ')') {
                while (!stack.empty() && stack.top() != '(') {
                    postfix += stack.top();
                    stack.pop();
                }
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                }
            }
            else {
                while (!stack.empty() && priory(i) <= priory(stack.top())) {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(i);
            }


        }
        while (!stack.empty()) {
            postfix += stack.top();
            stack.pop();
        }
        return postfix;
    }
