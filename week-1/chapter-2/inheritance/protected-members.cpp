// In inheritance, a protected member of a base class is acessible by member
// functions of children classes, *but not from outside of the class*.

#include <iostream>

class Animal {
    public:
        Animal();

    protected:
        bool has_dna;
};

Animal::Animal() {
    has_dna = true;
}

class Dog : public Animal {
    public:
        Dog(std::string b = "UNKNOWN");

        std::string get_breed() const;

        bool get_has_dna() const;

    private:
        std::string breed;
};

Dog::Dog(std::string b) {
    breed = b;
}

std::string Dog::get_breed() const {
    return breed;
}

// Since `has_dna` is a protected member of `Animal`, member functions of the
// children class `Dog` should have access to `has_dna`.
bool Dog::get_has_dna() const {
    return has_dna;
}

int main(void) {
    Dog d("wasssup"); 

    // This should now work.
    std::cout << d.get_has_dna() << std::endl;

    return 0;
}
