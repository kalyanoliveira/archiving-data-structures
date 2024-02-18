#ifndef NOTATION_CONVERTER_H
#define NOTATION_CONVERTER_H

#include "NotationConverterInterface.hpp"

class NotationConverter : public NotationConverterInterface {
    public:
        virtual std::string postfixToInfix(std::string inStr);
        virtual std::string postfixToPrefix(std::string inStr);

        virtual std::string infixToPostfix(std::string inStr);
        virtual std::string infixToPrefix(std::string inStr);

        virtual std::string prefixToInfix(std::string inStr);
        virtual std::string prefixToPostfix(std::string inStr);

        // I mean, the name already implies what we want with this:
        void remove_whitespace_from_string(std::string &s);
        
        // The test cases have a specific kind of whitespacing that needs to be
        // used.
        // Hence, this.
        std::string add_whitespace_to_string(const std::string &s);

    private:
        // This returns an integer which represents the "precedence level" of
        // an operator (i.e., the precedence of the chars * / + and -).
        int p(const char &c);

        // This is used to determine whether a sequence of characters needs a
        // space between them.
        bool needs_spacing(const char &c1, const char &c2);
};

#endif
