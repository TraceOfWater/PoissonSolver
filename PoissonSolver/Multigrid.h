#pragma once

#include "Jacobi.h"

class Multigrid :
	public Jacobi
{
public:
	Multigrid(ID3D11DeviceContext *const pDeviceContext);
	virtual ~Multigrid();
	HRESULT Init();

	void Solve(const DirectX::XMUINT3 &vSize, ID3D11ShaderResourceView* const* const ppSrcSRVs,
		ID3D11ShaderResourceView* const* const ppDstSRVs, ID3D11UnorderedAccessView* const* const ppSrcUAVs,
		ID3D11UnorderedAccessView* const* const ppDstUAVs, uint32_t uNumIt, uint32_t uMips);

	static HRESULT CreateSolver(ID3D11DeviceContext *const pDeviceContext, Multigrid **ppSolver);

protected:
	uint32_t			m_uUAVSlot_xdown;
	uint32_t			m_uUAVSlot_xup;
	uint32_t			m_uUAVSlot_ydown;
	uint32_t			m_uUAVSlot_yup;

	ID3D11ComputeShader	*m_pDownSmpShader;
	ID3D11ComputeShader	*m_pUpSmpShader;
};
