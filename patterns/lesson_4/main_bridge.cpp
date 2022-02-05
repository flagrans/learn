#include <iostream>

// Implementor
class DrawingImplementor {
public:
    virtual void drawSquare() = 0;
    virtual ~DrawingImplementor() {}
};

class drawBrush : public DrawingImplementor {
public:
    void drawSquare() {
        std::cout << "draw brush" << std::endl;
    }
};

class drawPencil : public DrawingImplementor {
public:
    void drawSquare() {
        std::cout << "draw pencil" << std::endl;
    }
};

// Abstraction
class Shape {
public:
    virtual void draw()= 0; // low-level
    virtual void resize(double pct) = 0; // high-level
    virtual ~Shape() {
    }
};

class Square: public Shape {
protected:
    DrawingImplementor* _drawImplementor;
public:
    Square(DrawingImplementor* implementation) : _drawImplementor(implementation) {}
    virtual ~Square() {}

    virtual void draw() {
        std::cout << "Square ";
        _drawImplementor->drawSquare();
    }
    virtual void resize(double pct){
        std::cout << pct << std::endl;
    }
};

int main() {

    DrawingImplementor* implementation = new drawBrush();
    DrawingImplementor* implementation2 = new drawPencil();

    Shape* shape = new Square(implementation);
    shape->draw();
    delete shape;

    shape = new Square(implementation2);
    shape->draw();
    delete shape;

    delete implementation;
    delete implementation2;

    return 0;
}
