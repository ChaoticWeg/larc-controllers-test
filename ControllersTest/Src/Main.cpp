#include "Defines.h"
#include "Window.h"
#include "Game.h"

#include "DebugPrintf.h"

static CWindow g_cWindow;
static CGame g_cGame;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// setup
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// check window
	if (!g_cWindow.WinMain(hInstance))
		return 1;

	// initialize multithreaded app
	Microsoft::WRL::Wrappers::RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
	if (FAILED(initialize))
		return 1;

#ifdef USE_DEBUGPRINTF
	// initialize debug manager
	g_cDebugManager.Initialize();
#endif

	// initialize game
	g_cGame.Initialize();

	// message loop
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			g_cGame.ProcessFrame();
		}
	}

	// clean up, exit
	CoUninitialize();
	return (int)msg.wParam;
}
