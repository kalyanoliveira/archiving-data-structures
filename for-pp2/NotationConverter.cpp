#include "NotationConverter.hpp"
#include <string>
#include "deque.hpp"
#include <iostream>
#include "invalid-input-string-exception.hpp"

// We'll implement the following functions "fully:"
// - infix to postfix
// - postfix to prefix
// - prefix to infix
// This establishes a "loop" between them.
// We can thus convert from any format by using this "loop" and reduce the
// number of methods that we *actually* need to implement.

// Uses loop.
std::string NotationConverter::postfixToInfix(std::string inStr) {
    is_valid(inStr);
    std::string output = prefixToInfix(postfixToPrefix(inStr));
    output = add_whitespace_to_string(output);
    return output;
}

// Fully implemented.
std::string NotationConverter::postfixToPrefix(std::string inStr) {
    is_valid(inStr);
    remove_whitespace_from_string(inStr);

    // We're going to use a stack adapted from a Deque.
    // Only uses front-related methods.
    Deque d;

    // Creating the output string.
    std::string output;

    // For each character in the string,
    for (int i = 0; i < inStr.length(); i++) {

        // If the character is an operand, 
        if (inStr[i] >= 'a' && inStr[i] <= 'z' || inStr[i] >= 'A' && inStr[i] <= 'Z') {
            // Push it to the top of the stack.
            d.push_to_front(std::string(1, inStr[i]));

            // Jump to the next iteration of the loop.
            continue;
        }

        // If the character is an operator,
        if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '+' || inStr[i] == '-') {

            // Pop two strings from the top of the stack, saving each string in
            // a different variable.
            std::string first = d.pop_front();
            std::string second = d.pop_front();

            // Create a new string, concatenating `operator` + `second` +
            // `first`.
            std::string string_to_push = inStr[i] + second + first;

            // Push that string that we concatenated.
            d.push_to_front(string_to_push);
        }

    }

    // While the stack is not empty,
    while (!d.empty()) {
        // Pop the top of the stack, and append it to the output.
        output += d.pop_front(); 
    }

    output = add_whitespace_to_string(output);

    // Return the output string.
    return output;
}

// Fully implemented.
std::string NotationConverter::infixToPostfix(std::string inStr) {
    is_valid(inStr);
    remove_whitespace_from_string(inStr);

    // Get a stack by adapting it from a deque.
    // This means we'll only be pushing to the front, and popping the front.
    Deque d;

    // Let's create an output string.
    std::string output;

    // For every character in the input string,
    for (int i = 0; i < inStr.length(); i++) {

        // If the character is an operand (i.e, a letter), 
        if (inStr[i] >= 'a' && inStr[i] <= 'z' || inStr[i] >= 'A' && inStr[i] <= 'Z') {

            // Append to output.
            output += inStr[i];
            // Jump to next iteration of the loop.
            continue;
        }

        // If we get an opening parentheses (, 
        if (inStr[i] == '(') {

            // Push it to the top of the stack.
            d.push_to_front("(");
            // Jump to next iteration of the loop.
            continue;
        }

        // If we get a closing parentheses ),
        if (inStr[i] == ')') {

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

    output = add_whitespace_to_string(output);
    return output;
}

// Uses loop.
std::string NotationConverter::infixToPrefix(std::string inStr) {
    is_valid(inStr);
    std::string output = postfixToPrefix(infixToPostfix(inStr));
    output = add_whitespace_to_string(output);
    return output;
}

// Fully implemented.
std::string NotationConverter::prefixToInfix(std::string inStr) {
    is_valid(inStr);
    remove_whitespace_from_string(inStr);

    // Use a deque as a stack.
    Deque d;

    // Create the output string.
    std::string output;

    // For each character in the string, == but in reverse order ==,
    for (int i = inStr.length(); i >= 0; i--) {

        // If the character is an operand,
        if (inStr[i] >= 'a' && inStr[i] <= 'z' || inStr[i] >= 'A' && inStr[i] <= 'Z') {
            // Push it to the stack.
            d.push_to_front(std::string(1, inStr[i]));

            // Jump to the next iteration of the loop.
            continue;
        }

        // If the character is an operator,
        if (inStr[i] == '*' || inStr[i] == '/' || inStr[i] == '+' || inStr[i] == '-') {
            // Pop two from the top of the stack.
            std::string first = d.pop_front();
            std::string second = d.pop_front();

            // Create a new string that is "(" + "first" + "operator" + "second" + ")".
            std::string temp = "(" + first + inStr[i] + second + ")";

            // Push that new string to the top of the stack (it's kind of like
            // it's the new operand)
            d.push_to_front(temp);
        }

    }

    // While the stack is not empty.
    while (!d.empty()) {
        // Pop the stack, and append it to the output.
        output += d.pop_front();
    }

    output = add_whitespace_to_string(output);
    return output;
}

// Uses loop.
std::string NotationConverter::prefixToPostfix(std::string inStr) {
    is_valid(inStr);
    std::string output = infixToPostfix(prefixToInfix(inStr));
    output = add_whitespace_to_string(output);
    return output;
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

// This is just used to return the precedence of operators.
// * and / have higher precedence than + and -.
int NotationConverter::p(const char &c) {
    if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

std::string NotationConverter::add_whitespace_to_string(const std::string &s) {
    int new_index = 0;

    // Create a buffer for the new string.
    std::string output;

    // For every character of the input string, == but the very last ==,
    for (int i = 0; i < s.length() - 1 ; i++) {

        // Append the character to the output
        output += s[i];
        
        // If this character needs a space after it,
        if (needs_spacing(s[i], s[i + 1])) {
            // then do so.
            output += " ";
        }
    }

    // Append the very last character to the output.
    output += s[s.length() - 1];

    return output;
}

bool NotationConverter::needs_spacing(const char &c1, const char &c2) {
    // If a ) is followed by an operator, output true.
    if (c1 == ')') {
        if (c2 == '*' || c2 == '/' || c2 == '+' || c2 == '-') return true;
    }

    // If an operator is followed by a (, output true.
    if (c1 == '*' || c1 == '/' || c1 == '+' || c1 == '-') {
        if (c2 == '(') return true;
    }

    // If an operand is followed by an operator, output true.
    if (c1 >= 'a' && c1 <= 'z' || c1 >= 'A' && c1 <= 'Z') {
        if (c2 == '*' || c2 == '/' || c2 == '+' || c2 == '-') return true;
    }

    // If an operator is followed by an operand, output true.
    if (c1 == '*' || c1 == '/' || c1 == '+' || c1 == '-') {
        if (c2 >= 'a' && c2 <= 'z' || c2 >= 'A' && c2 <= 'Z') return true;
    }

    // If an operand is followed by an operand, output true.
    if (c1 >= 'a' && c1 <= 'z' || c1 >= 'A' && c1 <= 'Z') {
        if (c2 >= 'a' && c2 <= 'z' || c2 >= 'A' && c2 <= 'Z') return true;
    }

    // Else, output false.
    return false;
}

void NotationConverter::is_valid(const std::string &s) {
    // For every character in the input string.
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is valid,
        if (c == '*' || c == '/' || c == '+' || c == '-' || c == '(' 
            || c == ')' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            // Continue to the next iteraction of the loop.
            continue;
        }

        // This means that the character is not valid.
        // So, we must throw an `InvalidInputString`.
        throw(InvalidInputString());
    }

    return;
}
