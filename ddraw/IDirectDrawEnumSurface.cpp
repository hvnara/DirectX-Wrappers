/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "ddraw.h"

HRESULT CALLBACK m_IDirectDrawEnumSurface::EnumSurfaceCallback(LPDIRECTDRAWSURFACE a, LPDDSURFACEDESC b, LPVOID c)
{
	ENUMSURFACE *lpCallbackContext = (ENUMSURFACE*)c;

	if (a)
	{
		a = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface>(a);
	}

	return lpCallbackContext->lpCallback(a, b, lpCallbackContext->lpContext);
}

HRESULT CALLBACK m_IDirectDrawEnumSurface2::EnumSurface2Callback(LPDIRECTDRAWSURFACE4 a, LPDDSURFACEDESC2 b, LPVOID c)
{
	ENUMSURFACE2 *lpCallbackContext = (ENUMSURFACE2*)c;

	if (a)
	{
		a = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface4>(a);
	}

	return lpCallbackContext->lpCallback(a, b, lpCallbackContext->lpContext);
}

HRESULT CALLBACK m_IDirectDrawEnumSurface7::EnumSurface7Callback(LPDIRECTDRAWSURFACE7 a, LPDDSURFACEDESC2 b, LPVOID c)
{
	ENUMSURFACE7 *lpCallbackContext = (ENUMSURFACE7*)c;

	if (a)
	{
		a = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface7>(a);
	}

	return lpCallbackContext->lpCallback(a, b, lpCallbackContext->lpContext);
}
