#include <iostream>
    using namespace std;
    class Shape 
    {
        public:
            virtual void draw() 
            {
                cout << "Drawing a shape." << endl;
            }
    };

    class Circle : public Shape 
    {
        public:
            void draw() override 
            {
                cout << "Drawing a circle." << endl;
            }
    };

    class Square : public Shape 
    {
        public:
            void draw() override 
            {
                cout << "Drawing a square." << endl;
            }
    };

    void render(Shape& s) 
    {
        s.draw();
    }

    int main() 
    {
        Circle c;
        Square s;
        render(c); // Outputs: "Drawing a circle."
        render(s); // Outputs: "Drawing a square."
        return 0;
    }
