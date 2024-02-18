#include "NotationConverter.hpp"
#include <string>

// We'll implement the following functions "fully:"
// - infix to postfix
// - postfix to prefix
// - prefix to infix
// This establishes a "loop" between them.
// We can thus convert from any format by using this "loop" and reduce the
// number of methods that we *actually* need to implement.

// Uses loop.
std::string NotationConverter::postfixToInfix(std::string inStr) {
    input_s = inStr;
    return "hello";
}

// Fully implemented.
std::string NotationConverter::postfixToPrefix(std::string inStr) {
    return "hello";
}

// Fully implemented.
std::string NotationConverter::infixToPostfix(std::string inStr) {
    return "hello";
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
void NotationConverter::clear_input_string_from_whitespace() {
    int new_index = 0

    std::string &s = input_s;

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
