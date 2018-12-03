#include "ObjectManager.h"

CObjectManager::CObjectManager()
{
	for (unsigned i = 0; i < RLAYER_COUNT; ++i)
		m_layers[(eRenderLayer)i] = ObjectList();
}

CObjectManager::~CObjectManager()
{
	Clear();
}

void CObjectManager::Clear()
{
	for (auto it = m_layers.begin(); it != m_layers.end();)
	{
		for (auto obj = it->second.begin(); obj != it->second.end();)
		{
			delete *obj;
			obj = it->second.erase(obj);
		}

		it = m_layers.erase(it);
	}
}
