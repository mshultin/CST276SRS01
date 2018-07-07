// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
//Observer pattern via subject.h/cpp and observer.h/cpp; GoF (pg293)
#include "../Observer/viewer.h"
#include "../Observer/subject.h"

// TODO: reference additional headers your program requires here
