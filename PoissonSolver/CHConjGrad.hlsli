//--------------------------------------------------------------------------------------
// By XU, Tianchen
//--------------------------------------------------------------------------------------

#include "SharedConst.h"

#define uSlice		(vDim.x * vDim.y)
#define GETIDX(v)	(v.z * uSlice + v.y * vDim.x + v.x)
