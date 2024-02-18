#include "NotationConverter.hpp"
#include <string>
#include "deque.hpp"
#include <iostream>

// We'll implement the following functions "fully:"
// - infix to postfix
// - postfix to prefix
// - prefix to infix
// This establishes a "loop" between them.
// We can thus convert from any format by using this "loop" and reduce the
// number of methods that we *actually* need to implement.

// Uses loop.
std::string NotationConverter::postfixToInfix(std::string inStr) {
    return "hello";
}

// Fully implemented.
std::string NotationConverter::postfixToPrefix(std::string inStr) {
    return "hello";
}

// Fully implemented.
std::string NotationConverter::infixToPostfix(std::string inStr) {
    remove_whitespace_from_string(inStr);

    // Get a stack by adapting it from a deque.
    // This means we'll only be pushing to the front, and popping the front.
    Deque d;

    // Let's create an output string.
    std::string output;

    // For every character in the input string,
    for (int i = 0; i < inStr.length(); i++) {

        // ==
        std::cout << "curr char " << inStr[i] << " ";

        // If the character is an operand (i.e, a letter), 
        if (inStr[i] >= 'a' && inStr[i] <= 'z' || inStr[i] >= 'A' && inStr[i] <= 'Z') {

            // ==
            std::cout << "is a letter" << std::endl;

            // Append to output.
            output += inStr[i];
            // Jump to next iteration of the loop.
            continue;
        }

        // If we get an opening parentheses (, 
        if (inStr[i] == '(') {

            // ==
            std::cout << "is an opening parentheses" << std::endl;

            // Push it to the top of the stack.
            d.push_to_front("(");
            // Jump to next iteration of the loop.
            continue;
        }

        // If we get a closing parentheses ),
        if (inStr[i] == ')') {

            // ==
            std::cout << "is an closing parentheses" << std::endl;

            // While the top element of the stack is not an opening parentheses (,
            while (d.peek_front()[0] != '(') {
                // Append the top of the stack to the output.
                output += d.peek_front();
                // Pop the top of the stack.
                d.pop_front();
            }
        
            // This means that the top element of the stack is currently a (.
            
            // Let's pop it too, but **not** append it to the output:
            d.pop_front();

            // And now, we continue to the next iteration of the loop.
            continue;
        }

        // Under our inputs, our only option right now is to have an operator.
        // Nevertheless, let's check for it:
        if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '+' || inStr[i] == '-') {

            // ==
            std::cout << "is an operator" << std::endl;

            // While the precedence of the operator on top of the stack is
            // greater than or equal to the precedence of the operator in
            // `inStr[i]`, OR while the stack is not empty,
            while (!d.empty() && p(d.peek_front()[0]) > p(inStr[i])
                    || !d.empty() && p(d.peek_front()[0]) == p(inStr[i])) {
                // Append the top of the stack to the output.
                output += d.peek_front();
                // Pop the top of the stack.
                d.pop_front();
            }

            // This either means that:
            // - the stack is empty
            // - the operator on the top of the stack has less precedence than
            // the operator in `inStr[i]`.
            
            // So let's just push `inStr[i]` to the top of the stack:
            d.push_to_front(std::string(1, inStr[i]));
        }

    }

    // Now, all we have to do is pop the remaining elements from the stack, and
    // append them to the output.
    while (!d.empty()) {
        output += d.peek_front();
        d.pop_front();
    }

    return output;
}

// Uses loop.
std::string NotationConverter::infixToPrefix(std::string inStr) {
    return "hello";
}

// Fully implemented.
std::string NotationConverter::prefixToInfix(std::string inStr) {
    return "hello";
}

// Uses loop.
std::string NotationConverter::prefixToPostfix(std::string inStr) {
    return "hello";
}

// Yeah, we could use some library for this, but I'm not sure if I'm allowed to
// do that.
void NotationConverter::remove_whitespace_from_string(std::string &s) {
    int new_index = 0;

    // For every character in the string,
    for (int i = 0; i < s.length(); i++) {
        // If the current character is a space, continue to the next iteration
        // of the loop.
        if (s[i] == ' ') continue;

        // This means that the current character is not space.
       
        // Hence, let's place on the `new_index` index of `s`, and ...
        s[new_index] = s[i];
        // ... increase `new_index`.
        new_index++;
    }

    // We should now place `\0` at `new_index`, because `new_index - 1` is the
    // last character in our "new," "overwritten" string.
    s[new_index] = '\0';

    // Since the parameter of this function is reference to a std::string, we
    // should also make sure that the reference gets notice of the updated size
    // of its contents.
    s.resize(new_index);

    return;
}

int NotationConverter::p(const char &c) {
    if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}
