#pragma once

#include "debug.h"

#if _DEBUG
#define USE_DEBUGPRINTF
#endif

#ifdef USE_DEBUGPRINTF
#define DEBUGPRINTF (g_cDebugManager.setsource(__FILE__,__LINE__), realDebugPrintf)
#else
#define DEBUGPRINTF ;
#endif
