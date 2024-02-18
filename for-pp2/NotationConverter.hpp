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
        // I mean, the name already implies what we want with this:
        void clear_string_from_whitespace(std::string &s);
};

#endif
