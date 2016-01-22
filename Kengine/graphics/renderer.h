#pragma once
#include "../app/window.h"
#include "SFML/Graphics.hpp"

class Renderer
{

public:
	Renderer();
	~Renderer();
	void draw(Window &window);

private:
};