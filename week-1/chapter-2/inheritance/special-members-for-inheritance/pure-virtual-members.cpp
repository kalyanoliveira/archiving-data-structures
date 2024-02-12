// C++ classes implement ADTs via their public interfaces *and* also implement
// those interfaces.

// However, there are many instances were we might want to have just the
// interface of something declared, and then apply some polymorphism (and
// perhaps some dynamic casting too) to define/implement those interfaces.

// The missing concept here are "abstract classes:" these are classes that can
// only be inherited, and that do not generate any objects.

// Abstract classes are perfect for our problem of "wanting to implement *just*
// the interface:" we can create an abstract class the base class, with
// declared (but not defined) public interface, and then make derived classes
// from that base class actually implement the interface.

// **In C++, to implement an "abstract class," all we have to do is to make one
// or more of its members a *purely virtual member*.**

// To create a purely virtual member, we must make it `virtual` and assign it
// `= 0`.

#include <iostream>

class Shape {
    public:
        // Done! Now `Shape` is technically an abstract class because of this
        // "purely virtual member."
        virtual void draw() = 0;
};

class Rectangle : public Shape {
    public:
        virtual void draw();
};

void Rectangle::draw() {
    std::cout << "This is a drawn rectangle!" << std::endl;
}

class Triangle : public Shape {
    public:
        virtual void draw();
};

void Triangle::draw() {
    std::cout << "This is a drawn triangle!" << std::endl;
}

int main(void) {
    Shape *a[2];

    a[0] = new Rectangle;
    a[1] = new Triangle;

    // Draw only the rectangles:
    for (int i = 0; i < 2; i++) {
        if (dynamic_cast<Rectangle *>(a[i]) != NULL) {
            a[i]->draw();
        }
    }

    // Draw only the Triangles:
    for (int i = 0; i < 2; i++) {
        if (dynamic_cast<Triangle *>(a[i]) != NULL) {
            a[i]->draw();
        }
    }

    return 0;
}
