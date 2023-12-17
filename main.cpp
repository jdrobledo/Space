#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    // Configuración de la ventana
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Círculo con una aceleración variable");
    ventana.setFramerateLimit(60);

    // Configuración del círculo
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

        // Actualización de la posición del círculo
        sf::Vector2f currentPosition = circuloverde.getPosition();
        circuloverde.setPosition(currentPosition + velocidad);

        // Limpiar la pantalla
        ventana.clear();

        // Dibujar el círculo
        ventana.draw(circuloverde);

        // Mostrar el contenido en la ventana
        ventana.display();
    }

    return 0;
}