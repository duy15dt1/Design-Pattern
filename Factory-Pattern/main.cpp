#include <iostream>
#include <memory>
#include <random>
using namespace std;

class Shape;

enum class ShapeType{
    circle,
    square
};

class ShapeFactory{
public:
    static Shape* CreateShape(ShapeType Type);
};

class Shape{
public:
    ~Shape();

    //pure virtual cannot create instances of shape
    //thus shape is an abstract base class
    virtual void Draw() const = 0;
};

class Circle : public Shape{
private:
    float mRadius;
public:
    explicit Circle(float radius = 0.0F){
        mRadius = radius;
    }
    ~Circle(){
        cout << "Circle with radius " << mRadius << " destroyed" << endl;
    };

    void Draw() const override{
        cout << "Im a circle with radius " << mRadius << endl;
    }
};

class Square : public Shape{
private:
    float mLength;
public:
    explicit Square(float length = 0.0F){
        mLength = length;
    }
    ~Square(){
        cout << "Square with length " << mLength << " destroyed" << endl;
    }

    void Draw() const override{
        cout << "Im a square with length " << mLength << endl;
    }
};

Shape* ShapeFactory::CreateShape(ShapeType Type){
    switch(Type){
        case ShapeType::circle:{
            float radius;
            cout << "Enter the radius for the new circle ";
            cin >> radius;
            if (radius < 0.0F){
                cout << "Bad enter. Take default" << endl;
                radius = 0.0F;
            }
            return new Circle(radius);
            break;
        }
        case ShapeType::square:{
            float length;
            cout << "Enter the length for the new square ";
            cin >> length;
            if (length < 0.0F){
                cout << "Bad enter. Take default" << endl;
                length = 0.0F;
            }
            return new Square(length);
            break;
        }
    }
}

void TestShape(ShapeType Type){
    //create a shape
    //unique ptr is very important
    unique_ptr<Shape> shape_ptr(ShapeFactory::CreateShape(Type));

    //draw the shape
    shape_ptr->Draw();
    return;
}

int main(){
    TestShape(ShapeType::circle);

    TestShape(ShapeType::square);
    return 0;
}