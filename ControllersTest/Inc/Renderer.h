#pragma once

#include "GameDefines.h"
#include "SpriteRenderer.h"

class CRenderer :
	public CSpriteRenderer
{
public:
	CRenderer() : CSpriteRenderer(Unbatched2D) {}
	void LoadImages();
};
