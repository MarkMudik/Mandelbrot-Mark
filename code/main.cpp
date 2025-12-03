#include "ChaosGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    
    VideoMode vm = VideoMode::getDesktopMode();
    unsigned int width = vm.width;
    unsigned int height = vm.height;
    
    RenderWindow window(vm, "Chaos Game Fractal Generator", Style::Default);
    
    Font font;
    if (!font.loadFromFile("AdwaitaSans-Regular.ttf")) {
        cerr << "Failed to load font! Make sure AdwaitaSans-Regular.ttf is in the directory." << endl;
    }
    
    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    
    ChaosGame chaos(width, height); 
    int currentSides = 3;
    chaos.setPolygon(currentSides);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == Event::Closed) {
                window.close();
            }
            
            if (event.type == Event::KeyPressed) {
                int newSides = currentSides;
                if (event.key.code == Keyboard::Num3) newSides = 3;
                else if (event.key.code == Keyboard::Num4) newSides = 4;
                else if (event.key.code == Keyboard::Num5) newSides = 5;
                else if (event.key.code == Keyboard::Num6) newSides = 6;
                else if (event.key.code == Keyboard::Num7) newSides = 7;
                else if (event.key.code == Keyboard::Num8) newSides = 8;
                else if (event.key.code == Keyboard::Num9) newSides = 9;
                else if (event.key.code == Keyboard::Num0) newSides = 10;
                
                if (newSides != currentSides) {
                    currentSides = newSides;
                    chaos.setPolygon(currentSides); 
                }

                if (event.key.code == Keyboard::S) {
                    Texture texture;
                    texture.create(window.getSize().x, window.getSize().y);
                    texture.update(window);
                    if (texture.copyToImage().saveToFile("chaos_game_snap.png")) {
                        cout << "Screenshot saved!" << endl;
                    }
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        
        ///Update
        chaos.updateRenderer();
        chaos.loadText(text);

        ///Draw
        window.clear(); 

        chaos.draw(window, RenderStates::Default);
        window.draw(text);
        
        window.display();
    }
    
    return 0;
}
