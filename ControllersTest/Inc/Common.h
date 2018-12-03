#pragma once

#include "GameDefines.h"

class CRenderer;
class CObjectManager;
class CInputManager;

class CCommon
{
protected:
	static CRenderer *m_pRenderer;
	static CObjectManager *m_pObjectManager;
	static CInputManager *m_pInputManager;
};
