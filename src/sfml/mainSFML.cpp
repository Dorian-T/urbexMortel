#include <SFML/Graphics.hpp>
#include "gameSFML.h"
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "L'Urbex mortel !");
    window.setFramerateLimit(30);
    Game g;
    sfmlLoop(g, window);
}