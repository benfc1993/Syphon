#pragma once

#ifdef SY_PLATFORM_WINDOWS
#ifdef SY_BUILD_DLL
#define SYPHON_API _declspec(dllexport)
#else
#define SYPHON_API _declspec(dllimport)
#endif // SY_BUILD_DLL
#else
#error Syphon only supports Windows
#endif // SY_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
