#pragma once

#include "planet.hpp"
#include <glm/glm.hpp>

class Renderer
{
public:
	virtual void windowHints() = 0;
	virtual void init(
		std::vector<PlanetParameters> planetParams, 
		int msaa,
		int windowWidth,
		int windowHeight) = 0;
	virtual void render(
		glm::dvec3 viewPos, 
		float fovy,
		glm::dvec3 viewCenter,
		glm::vec3 viewUp,
		float gamma,
		float exposure,
		float ambientColor,
		std::vector<PlanetState> planetStates) = 0;
	
	virtual void destroy() = 0;

protected:
	void generateFlareIntensityTex(int dimensions, std::vector<uint16_t> &pixelData);
	void generateFlareLinesTex(int dimensions, std::vector<uint8_t> &pixelData);
	void generateFlareHaloTex(int dimensions, std::vector<uint16_t> &pixelData);
};