#include "Game.h"

#include "Renderer.h"
#include "ObjectManager.h"
#include "ComponentIncludes.h"

CGame::~CGame()
{
	delete m_pRenderer;
	delete m_pObjectManager;
}

void CGame::Initialize()
{
	m_pRenderer = new CRenderer;
	m_pRenderer->Initialize(NUM_SPRITES);
	m_pRenderer->LoadImages();

	m_pObjectManager = new CObjectManager;

	m_pAudio->Load();

	BeginGame();
}

void CGame::ProcessFrame()
{
	m_pAudio->BeginFrame();
	m_pTimer->BeginFrame();

	RenderFrame();

	m_pTimer->EndFrame();
}

void CGame::RenderFrame()
{
	m_pRenderer->BeginFrame();



	m_pRenderer->EndFrame();
}

void CGame::BeginGame()
{
	
}
