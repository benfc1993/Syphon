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

#ifdef SY_ENABLE_ASSERTS
#define SY_ASSERT(x, ...) {if(!(x)) { SY_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#define SY_CORE_ASSERT(x, ...) {if(!(x)) { SY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
#define SY_ASSERT(x, ...)
#define SY_CORE_ASSERT(x, ...)
#endif // SY_ENABLE_ASSERTS


#define BIT(x) (1 << x)
