#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    // Configuraci�n de la ventana
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "C�rculo con una aceleraci�n variable");
    ventana.setFramerateLimit(60);

    // Configuraci�n del c�rculo
    sf::CircleShape circuloverde(30.0f);
    circuloverde.setFillColor(sf::Color::Green);
    sf::Vector2f velocidad(0.0f, 0.0f);
    float aceleracion = 0.2f;

    // Bucle principal
    while (ventana.isOpen()) {
        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        // Manejo de entrada del teclado
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // Acelerar hacia la izquierda
            velocidad.x -= aceleracion;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // Acelerar hacia la derecha
            velocidad.x += aceleracion;
        }
        else {
            // Desacelerar en X si no se presiona ninguna tecla
            if (velocidad.x > 0.0f) {
                velocidad.x -= aceleracion;
            }
            else if (velocidad.x < 0.0f) {
                velocidad.x += aceleracion;
            }
        }

        // Actualizaci�n de la posici�n del c�rculo
        sf::Vector2f currentPosition = circuloverde.getPosition();
        circuloverde.setPosition(currentPosition + velocidad);

        // Limpiar la pantalla
        ventana.clear();

        // Dibujar el c�rculo
        ventana.draw(circuloverde);

        // Mostrar el contenido en la ventana
        ventana.display();
    }

    return 0;
}