#include "ComplexPlane.h"
#include <complex>

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {
	m_pixel_size = { pixelWidth, pixelHeight };
	m_aspectRatio = static_cast<double>(pixelHeight) / static_cast<double>(pixelWidth);
	m_plane_center = { 0.0, 0.0 };
	m_plane_size.x = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	m_zoomCount = 0;
	m_state = sf::State::CALCULATING;

	m_vArray.setPrimitiveType(sf::Points);
	m_vArray.resize(pixelWidth * pixelHeight);
}

void draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_vArray);
}

void complexPlane::updateRenderer() {

	if (m_State == CALCULATING) {
		for (int i {0}; i < m_pixel_size.y; i++) {
			for (int j {0}; j < m_pixel_size.x; j++) {
				//:UNFINISHED
}


//private member functions

sf::Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {
		
	   sf::Vector2f planeCoord;
	   planeCoord.x = ((mousePixel.x - 
		//:UNFINISHED
}





