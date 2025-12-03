#ifndef CHAOSGAME_H
#define CHAOSGAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

const unsigned int ITERATIONS_PER_FRAME = 10000;

class ChaosGame : public sf::Drawable {
    public:
        ChaosGame(int pixelWidth, int pixelHeight);
        
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void updateRenderer();
        void loadText(sf::Text& text);
        void setPolygon(int sides);

    private:

        float getRatio(int sides);
        void generateVertices(int sides);
        void runIteration();

        sf::VertexArray m_vArray;
        sf::Vector2i m_pixel_size;
        
        int m_sides;
        float m_ratio;
        std::vector<sf::Vector2f> m_vertices;
        sf::Vector2f m_currentPoint;
        
        int m_lastVertexIndex;
        std::mt19937 m_randGen;
        unsigned long long m_pointsDrawn;
};

#endif
