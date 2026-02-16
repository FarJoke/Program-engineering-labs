#include <iostream>
using namespace std;

class Shape {
    public:
        Shape() {};
        Shape(const Shape&) {};
        virtual ~Shape() = default;

        virtual double area() const = 0;

        virtual void draw() const {
            std::cout << "Drawing shape\n";
        };

        void show_info() const {
            std::cout << "This is a shape\n";
        };
};

class Circle: public Shape {
    private:
        double radius;
        
    public:
        // Конструктор по умолчанию
        Circle() : radius(1.0) {
            std::cout << "Circle default constructor\n";
        };

        // Конструктор с параметром
        Circle(double r) : radius(r) {
            std::cout << "Circle parameter constructor\n";
        };

        // Конструктор копирования
        Circle(const Circle& other)
            : Shape(other), radius(other.radius) {
            std::cout << "Circle copy constructor\n";
        };

        // Деструктор
        ~Circle() override {
            std::cout << "Circle destructor\n";
        };

        // Виртуальное переопределение метода area
        double area() const override {
            return 3.14159 * radius * radius;
        };

        // Сеттер для радиуса
        void setRadius(double r) {
            radius = r;
        };

        // Перегрузка метода setRadius
        void setRadius(double r, bool printInfo) {
            radius = r;
            if (printInfo)
                std::cout << "Radius changed\n";
        };

        // Переопределение метода draw
        void draw() const override {
            std::cout << "Drawing circle\n";
        };
                
};

class Square: public Shape {
    private:
        double sideLength;
        
    public:

        // Конструктор по умолчанию
        Square() : sideLength(1.0) {
            std::cout << "Square default constructor\n";
        };

        // Конструктор с параметром
        Square(double s) : sideLength(s) {
            std::cout << "Square parameter constructor\n";
        };

        // Конструктор копирования
        Square(const Square& other)
            : Shape(other), sideLength(other.sideLength) {
            std::cout << "Square copy constructor\n";
        };

        // Деструктор
        ~Square() override {
            std::cout << "Square destructor\n";
        };

        // Виртуальное переопределение метода area
        double area() const override {
            return sideLength * sideLength;
        };

        // Сеттер для длины стороны
        void setSideLength(double s) {
            sideLength = s;
        };

        // Переопределение метода show_info
        void show_info() const {
            std::cout << "This is a square with side length: " << sideLength << "\n";
        };

        // Переопределение метода draw
        void draw() const override {
            std::cout << "Drawing square\n";
        };


};

class Triangle: public Shape {
    private:
        double hight;
        double base;

    public:
        // Конструктор по умолчанию
        Triangle() : hight(1.0), base(1.0) {
            std::cout << "Triangle default constructor\n";
        };

        // Конструктор с параметрами
        Triangle(double h, double b) : hight(h), base(b) {
            std::cout << "Triangle parameter constructor\n";
        };
  
        // Конструктор копирования
        Triangle(const Triangle& other)
            : Shape(other), hight(other.hight), base(other.base) {
            std::cout << "Triangle copy constructor\n";
        };

        // Деструктор
        ~Triangle() override {
            std::cout << "Triangle destructor\n";
        };

        // Виртуальное переопределение метода area
        double area() const override {
            return 0.5 * base * hight;
        };

        // Сеттер для высоты
        void setHight(double h) {
            hight = h;
        };

        // Сеттер для основания
        void setBase(double b) {
            base = b;
        };

        // Переопределение метода show_info
        void show_info() const {
            std::cout << "This is a triangle with base: " << base << " and hight: " << hight << "\n";
        };

        // Переопределение метода draw
        void draw() const override {
            std::cout << "Drawing triangle\n";
        };
};


int main() {
    Shape* shape = nullptr;

    int choice;
    std::cout << "Choose shape:\n";
    std::cout << "1 - Circle\n";
    std::cout << "2 - Square\n";
    std::cout << "3 - Triangle\n";
    std::cin >> choice;

    if (choice == 1)
        shape = new Circle(5.0);
    if (choice == 2)
        shape = new Square(4.0);
    if (choice == 3)
        shape = new Triangle(3.0, 6.0);

    if (shape) {
        shape->draw();                 
        std::cout << shape->area() << std::endl;  
        shape->show_info();        
    }

    delete shape;

    return 0;
};