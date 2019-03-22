//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2018-2019 NVIDIA Corporation. All rights reserved.



#ifndef __APEX_INTEROPABLE_BUFFER_H__
#define __APEX_INTEROPABLE_BUFFER_H__

typedef struct CUgraphicsResource_st *CUgraphicsResource;

namespace physx
{
	class PxCudaContextManager;
}

namespace nvidia
{
namespace apex
{

class ApexInteropableBuffer
{
public:
	ApexInteropableBuffer(bool mustBeRegistered = false, PxCudaContextManager *interopContext = NULL)
		: m_mustBeRegisteredInCUDA(mustBeRegistered)
		, m_registeredInCUDA(false)
		, m_interopContext(interopContext)
		, m_InteropHandle(NULL)
	{
	}

	virtual bool getInteropResourceHandle(CUgraphicsResource &handle)
	{
		if(m_registeredInCUDA && m_InteropHandle)
		{
			handle = m_InteropHandle;

			return true;
		}

		return false;
	}

protected:

	bool		 m_mustBeRegisteredInCUDA;
	bool		 m_registeredInCUDA;
	PxCudaContextManager *m_interopContext;
	CUgraphicsResource	m_InteropHandle;
};


}
} // end namespace nvidia::apex


#endif // __APEX_INTEROPABLE_BUFFER_H__