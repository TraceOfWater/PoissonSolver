//--------------------------------------------------------------------------------------
// By XU, Tianchen
//--------------------------------------------------------------------------------------

#include "SharedConst.h"

RWTexture3D<float>	x;
RWTexture3D<float>	y;

//--------------------------------------------------------------------------------------
// Up sampling
//--------------------------------------------------------------------------------------
[numthreads(THREAD_GROUP_SIZE, THREAD_GROUP_SIZE, THREAD_GROUP_SIZE)]
void main(uint3 DTid : SV_DispatchThreadID)
{
	y[DTid] = x[DTid >> 1];
}
