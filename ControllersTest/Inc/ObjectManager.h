#pragma once

#include <list>
#include <map>

#include "Object.h"

using ObjectList = std::list<CObject*>;
using LayerMap = std::map<eRenderLayer, ObjectList>;

class CObjectManager
{
private:
	LayerMap m_layers;

	void Register(CObject *, const eRenderLayer &);

public:
	CObjectManager();
	~CObjectManager();

	void Clear();
};
