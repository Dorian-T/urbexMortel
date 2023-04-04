#include <SFML/Graphics.hpp>
#include "gameSFML.h"

#include <time.h>
#include <stdlib.h>

using namespace sf;



int main() {
    srand(time(NULL));
    RenderWindow window(VideoMode(1920, 1080), "L'Urbex mortel !");
    window.setFramerateLimit(30);
    Game g;
    sfmlLoop(g, window);
}