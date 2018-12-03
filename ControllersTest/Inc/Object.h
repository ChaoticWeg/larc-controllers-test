#pragma once

#include "Common.h"
#include "Component.h"
#include "SpriteDesc.h"

class CObject :
	public CCommon,
	public CComponent,
	public CSpriteDesc2D
{
	friend class CObjectManager;

protected:
	Vector2 m_vSize;
	BoundingBox m_bBounds;

public:
	CObject(eSpriteType t, const Vector2 &p) { m_vPos = p; }
};
