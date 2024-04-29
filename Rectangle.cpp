#include "Rectangle.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Rectangle::Rectangle(Vector2f size)
{
    /**  (4pts)
        Inicializa las variables:
        - shape: un rectángulo de tamaño size.
        - speed: un Vector2f con valores (0, 0).
        - objective: un Vector2f con valores (0, 0).
        - Haz que el cuadrado se pinte de un color.
    */

    {
        this->shape = RectangleShape(size);
        this->speed = Vector2f(0.f, 0.f);
        this->shape.setFillColor(Color::Blue);
        this->objective = Vector2f(0, 0);
    }
}

Rectangle::Rectangle(Vector2f size, Vector2i position)
{
    /** (5pts)
        Inicializa las variables:
        - shape: un rectángulo de tamaño size.
        - speed: un Vector2f con valores (0, 0).
        - objective: un Vector2f de position.
        - Haz que el cuadrado se pinte de un color.
        - Haz que el cuadrado esté en la posición position.
    */

    {
        this->shape = RectangleShape(size);
        this->speed = Vector2f(0.f, 0.f);
        this->shape.setFillColor(Color::Blue);
        this->objective = Vector2f(0, 0);
        this->shape.setPosition(Vector2f(position));
    }
}

void Rectangle::update()
{
    /**(6pts)
        Mueve el cuadrado.
        Si el cuadrado está a menos de 5 pixeles del objetivo, detén el cuadrado y píntalo de verde.
        Si no, píntalo de rojo.
            - Puedes saber si está a 5 pixeles del objetivo si la diferencia entre la coordeanda x del cuadrado y la x del objetivo es menor a 5 y lo mismo con la y.
    */

    this->shape.move(speed);

    if (this->shape.getPosition().x < 5)
    {
        this->speed.x *= 0;
        this->shape.setFillColor(Color::Green);
    }

    else
    {
        this->shape.setFillColor(Color::Red);
    }

        if (this->shape.getPosition().y < 5)
    {
        this->speed.x *= 0;
        this->shape.setFillColor(Color::Green);
    }

    else
    {
        this->shape.setFillColor(Color::Red);
    }
}

void Rectangle::setObjective(Vector2f objective)
{
    /**(5pts)
        Asigna objetivo a la propiedad objective.
        Calcula la dirección hacia el objetivo y la velocidad necesaria para llegar al objetivo:
        - Calcula la dirección hacia el objetivo.
            - La dirección es la diferencia entre el objetivo y la posición del cuadrado.
        - Calcula la magnitud de la dirección.
            - la magnitud es la distancia entre el cuadrado y el objetivo.
            - usa teorema de pitágoras para calcularla.
        - Calcula la velocidad necesaria para llegar al objetivo.
          - La velocidad es la dirección hacia el objetivo dividida por la magnitud de la dirección, multiplicada por un factor para cada eje.
    */


}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}
