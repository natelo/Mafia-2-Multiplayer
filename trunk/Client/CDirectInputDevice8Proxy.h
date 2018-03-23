/*************************************************************
*
* Solution   : Mafia 2 Multiplayer
* Project    : Client
* File       : CDirectInputDevice8Proxy.h
* Developers : AaronLad <aaron@m2-multiplayer.com>
*
***************************************************************/

#pragma once

#include "CDirectInput8Hook.h"
#include "CDirectInput8Proxy.h"

#define DIRECTINPUT_VERSION		0x0800

enum eDIDeviceType
{
	DIDEVICE_TYPE_UNKNOWN,
	DIDEVICE_TYPE_MOUSE,
	DIDEVICE_TYPE_KEYBOARD,
	DIDEVICE_TYPE_JOYSTICK
};

class CDirectInputDevice8Proxy : public IDirectInputDevice8
{

private:

	IDirectInputDevice8A *		m_pDevice;
	eDIDeviceType				m_DeviceType;

public:

	CDirectInputDevice8Proxy(IDirectInputDevice8A * pDevice, eDIDeviceType DeviceType);

	/*** IUnknown methods ***/
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID * ppvObj);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();

	/*** IDirectInputDevice8A methods ***/
	HRESULT STDMETHODCALLTYPE GetCapabilities(LPDIDEVCAPS p0);
	HRESULT STDMETHODCALLTYPE EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA p0, LPVOID p1, DWORD p2);
	HRESULT STDMETHODCALLTYPE GetProperty(REFGUID rguid, LPDIPROPHEADER p1);
	HRESULT STDMETHODCALLTYPE SetProperty(REFGUID rguid, LPCDIPROPHEADER p1);
	HRESULT STDMETHODCALLTYPE Acquire();
	HRESULT STDMETHODCALLTYPE Unacquire();
	HRESULT STDMETHODCALLTYPE GetDeviceState(DWORD p0, LPVOID p1);
	HRESULT STDMETHODCALLTYPE GetDeviceData(DWORD p0, LPDIDEVICEOBJECTDATA p1, LPDWORD p2, DWORD p3);
	HRESULT STDMETHODCALLTYPE SetDataFormat(LPCDIDATAFORMAT p0);
	HRESULT STDMETHODCALLTYPE SetEventNotification(HANDLE p0);
	HRESULT STDMETHODCALLTYPE SetCooperativeLevel(HWND p0, DWORD p1);
	HRESULT STDMETHODCALLTYPE GetObjectInfo(LPDIDEVICEOBJECTINSTANCEA p0, DWORD p1, DWORD p2);
	HRESULT STDMETHODCALLTYPE GetDeviceInfo(LPDIDEVICEINSTANCEA p0);
	HRESULT STDMETHODCALLTYPE RunControlPanel(HWND p0, DWORD p1);
	HRESULT STDMETHODCALLTYPE Initialize(HINSTANCE p0, DWORD p1, REFGUID rguid);
	HRESULT STDMETHODCALLTYPE CreateEffect(REFGUID rguid, LPCDIEFFECT p1, LPDIRECTINPUTEFFECT * p2, LPUNKNOWN p3);
	HRESULT STDMETHODCALLTYPE EnumEffects(LPDIENUMEFFECTSCALLBACKA p0, LPVOID p1, DWORD p2);
	HRESULT STDMETHODCALLTYPE GetEffectInfo(LPDIEFFECTINFOA p0, REFGUID rguid);
	HRESULT STDMETHODCALLTYPE GetForceFeedbackState(LPDWORD p0);
	HRESULT STDMETHODCALLTYPE SendForceFeedbackCommand(DWORD p0);
	HRESULT STDMETHODCALLTYPE EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK p0, LPVOID p1, DWORD p2);
	HRESULT STDMETHODCALLTYPE Escape(LPDIEFFESCAPE p0);
	HRESULT STDMETHODCALLTYPE Poll();
	HRESULT STDMETHODCALLTYPE SendDeviceData(DWORD p0, LPCDIDEVICEOBJECTDATA p1, LPDWORD p2, DWORD p3);
	HRESULT STDMETHODCALLTYPE EnumEffectsInFile(LPCSTR p0, LPDIENUMEFFECTSINFILECALLBACK p1, LPVOID p2, DWORD p3);
	HRESULT STDMETHODCALLTYPE WriteEffectToFile(LPCSTR p0, DWORD p2, LPDIFILEEFFECT p3, DWORD p4);
	HRESULT STDMETHODCALLTYPE BuildActionMap(LPDIACTIONFORMATA p0, LPCSTR p1, DWORD p2);
	HRESULT STDMETHODCALLTYPE SetActionMap(LPDIACTIONFORMATA p0, LPCSTR p1, DWORD p2);
	HRESULT STDMETHODCALLTYPE GetImageInfo(LPDIDEVICEIMAGEINFOHEADERA p0);
};
