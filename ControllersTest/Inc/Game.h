#pragma once

#include "Component.h"
#include "Settings.h"
#include "Common.h"

class CGame :
	public CComponent,
	public CSettings,
	public CCommon
{
private:
	void RenderFrame();
	void BeginGame();

public:
	~CGame();

	void Initialize();
	void ProcessFrame();
};
