#pragma once
//DLL export or import declaration
//Only one instance of this decleration is needed per DLL.
//Every class which needs to be accessed outside of the DLL will
//need the WEATHERSTATION_API declaration between the class keyword and the
//class name: class WEATHERSTATION_API Subject {}

#ifdef WEATHERSTATION_EXPORTS
#	define WEATHERSTATION_API __declspec(dllexport)
#else
#	define WEATHERSTATION_API __declspec(dllimport)
#endif