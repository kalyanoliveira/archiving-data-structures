#ifndef NOTATION_CONVERTER_H
#define NOTATION_CONVERTER_H

#include "NotationConverterInterface.hpp"
#include "deque.hpp"

class NotationConverter : public NotationConverterInterface {
    public:
        NotationConverter();

    private:
        Deque d;
};

#endif
