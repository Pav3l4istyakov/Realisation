#include <iostream>
#include <vector>
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Square" << std::endl;
    }
};

class CompositeShape : public Shape {
private:
    std::vector<Shape*> shapes;
public:
    void add(Shape* shape) {
        shapes.push_back(shape);
    }

    void draw() override {
        for (Shape* shape : shapes) {
            shape->draw();
        }
    }
};

int main() {
    Circle* circle = new Circle();
    Square* square = new Square();

    CompositeShape* composite = new CompositeShape();
    composite->add(circle);
    composite->add(square);

    composite->draw();

    delete circle;
    delete square;
    delete composite;

    return 0;
}
