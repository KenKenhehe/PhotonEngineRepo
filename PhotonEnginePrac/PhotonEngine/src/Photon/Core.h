#pragma once

#ifdef PH_PLATFORM_WINDOWS

	#ifdef PH_BUILD_DLL
		#define PHOTON_API _declspec(dllexport)
	#else
		#define PHOTON_API _declspec(dllimport)
	#endif // PH_BUILD_DLL
#else 
	#error Photon is a windows only engine!
#endif // PH_PLATFORM_WINDOWS

#define BIT(x) (1 << x)