#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    // setup
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle rect(Vector2f(30, 30));
    vector<Rectangle> rectangle;

    // loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            /** (5pts)
                Cuando se de click izquierdo, se deberá actualizar el objetivo del cuadrado a la posición del mouse.
            */
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int w = 50;
                    int h = 50;
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    Rectangle rec(Vector2f(w, h), Vector2i(x, y));
                    rectangle.push_back(rec);
                }
            }

            window.clear();
            rect.update();
            rect.drawTo(window);
            for (auto &r : rectangle)
            {
                r.update();
                r.drawTo(window);
            }
            window.display();
        }

        return 0;
    }
