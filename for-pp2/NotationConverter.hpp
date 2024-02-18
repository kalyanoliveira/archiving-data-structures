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

    private:
        // I want to have a place in the class where I can have the input
        // string with no spaces; easily readable.
        std::string input_s;

        // The same can be said for the output string.
        std::string output_s;
};

#endif
