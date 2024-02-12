// Classes can inherit from each other.
// Here, I'll cover a specific kind of inheritance: *public* inheritance.

#include <iostream>
#include <string>

class Animal {
    public:
        Animal();

        bool get_has_dna() const;

    private:
        bool has_dna;
};

Animal::Animal() {
    has_dna = true;
}

bool Animal::get_has_dna() const {
    return has_dna;
}

// By saying `public Animal`, we are essentially saying that `Dog` has access
// to all public members of `Animal`, but **not** to the private ones.
class Dog : public Animal {
    public:
        Dog(std::string b = "UNKNOWN");

        std::string get_breed() const;

    private:
        std::string breed;
};

Dog::Dog(std::string b) {
    breed = b;
}

std::string Dog::get_breed() const {
    return breed;
}

int main(void) {
    Animal a;
    std::cout << "Has dna? " << a.get_has_dna() << std::endl;

    Dog d("wasssup");
    std::cout << "Has dna? " << d.get_has_dna() << std::endl;
    std::cout << "Breed: " << d.get_breed() << std::endl;

    // // This would not work because `Dog` inherits *publicly* from `Animal`,
    // // which means `Dog` does not have access to member `has_dna` because
    // // `has_dna` is private to `Animal`. 
    // std::cout << d.has_dna << std::endl;

    return 0;
}
