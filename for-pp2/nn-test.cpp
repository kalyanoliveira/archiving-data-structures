#include <iostream>
#include "NotationConverter.hpp"
#include <string>

std::string remove_spaces_from_string(std::string &s);

int main(void) {
    NotationConverter nc;

    std::string something = " asdf asdf a d ds fsd f     sd1 ";        

    something = remove_spaces_from_string(something);

    std::cout << something << std::endl;


    return 0;
}

// Yeah, we could use some library for this, but I'm not sure if I'm allowed to
// do that.
std::string remove_spaces_from_string(std::string &s){
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

    return s;
}
