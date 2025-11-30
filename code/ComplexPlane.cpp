#include "ComplexPlane.h"
#include <complex>
#include <sstream>

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {
	m_pixel_size = { pixelWidth, pixelHeight };
	m_aspectRatio = static_cast<double>(pixelHeight) / static_cast<double>(pixelWidth);
	m_plane_center = { 0.0, 0.0 };
	m_plane_size.x = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	m_zoomCount = 0;
	m_state = sf::State::CALCULATING; //
	m_vArray.setPrimitiveType(sf::Points);
	m_vArray.resize(pixelWidth * pixelHeight);
}

void draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_vArray);
}

void complexPlane::updateRenderer() {

	if (m_State == sf::State::CALCULATING) {
		for (int i {0}; i < m_pixel_size.y; i++) {
			for (int j {0}; j < m_pixel_size.x; j++) {

				sf::Uint8 r, g, b;
				size_t iters {0};

				m_vArray[ j + i * pixelWidth].position = { (float)j, (float)i };

				iters = countIterations(mapPixelToCoords(sf::Vector2i(j, i));//check
				iterationsToRGB(iters, r, g, b);

				vArray[j + i * pixelWidth].color = { r, g, b };
			}
		}
		m_State = sf::State::DISPLAYING;
	}

}

void ComplexPlane::zoomIn() {
	m_zoomCount++;
	sf::Vector2f temp;
	float scale = pow(BASE_ZOOM, m_zoomCount);

	temp.x = BASE_WIDTH * scale;
	temp.y = BASE_HEIGHT * m_aspectRatio * scale;

	m_plane_size = temp;
	m_State = sf::State::CALCULATING; //
}

void ComplexPlane::zoomOut() {
	m_zoomCount--;

	sf::Vector2f temp;
	float scale = pow(BASE_ZOOM, m_zoomCount);

	temp.x = BASE_WIDTH * scale;
	temp.y = BASE_HEIGHT * m_aspectRatio * scale;

	m_plane_size = temp;
	m_State = sf::State::CALCULATING; //
}

void ComplexPlane::setCenter(sf::Vector2i mousePixel) {
	m_plane_center = mapPixelToCoords(mousePixel);
	m_State = sf::State::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel) {
	m_mouseLocation = mapPixelToCoords(mousePixel);
}

void ComplexPlane::loadText(Text& text) {

	ostringstream txt;

	txt << "Mandelbrot Set\n";
	txt << "Center: (" << m_plane_center.x << ", " << m_plane_center.y << ")\n";
	txt << "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")\n";
	txt << "Left Click to Zoom in\n" << "Right-click to Zoom out";

	text.setString(txt.str());

}

//private member functions

size_t ComplexPlane::countIterations(Vector2f coord) {
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {
}

sf::Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {
		
	   sf::Vector2f planeCoord;
	   planeCoord.x = ((mousePixel.x - 
		//:UNFINISHED
}





