#include "ComplexPlane.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    
    VideoMode vm = VideoMode::getDesktopMode();
    unsigned int width = vm.width;
    unsigned int height = vm.height;
    
    RenderWindow window(vm, "Mandelbrot Set", Style::Default);
    
    Font font;
    if (!font.loadFromFile("AdwaitaSans-Regular.ttf")) {
        // For error
        cerr << "Failed to load font!" << endl;
    }
    
    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    
    ComplexPlane mandel(width, height);

    while (window.isOpen()) {
        ///Input
        Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == Event::Closed) {
                window.close();
            }
            
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    mandel.zoomIn();
                    mandel.setCenter(Mouse::getPosition(window));
                }
                else if (event.mouseButton.button == Mouse::Right) {
                    mandel.zoomOut();
                    mandel.setCenter(Mouse::getPosition(window));
                }
            }

            if (event.type == Event::MouseMoved) {
                mandel.setMouseLocation(Mouse::getPosition(window));
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        
        ///Update
        mandel.updateRenderer();
        mandel.loadText(text);

        ///Draw
        window.clear();

        mandel.draw(window, RenderStates::Default);
        window.draw(text);
        
        window.display();
    }
    return 0;
}
