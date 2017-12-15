// SerializeBuffer_CZ75.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "hoxy_Header.h"
#include "SerializeBuffer_CZ75.h"

CPacket cPacket;

int main()
{
	CCmdStart::CmdDebugText(L"START", true);

    return 0;
}

CPacket::CPacket()
	:_iBufferSize(en_PACKET::eBUFFER_DEFAULT)
{
	_chpBuffer = (char*)malloc(_iBufferSize);
}

CPacket::CPacket(int iBufferSize)
	: _iBufferSize(iBufferSize)
{
	_chpBuffer = (char*)malloc(_iBufferSize);
}

CPacket::~CPacket()
{
	Release();
}

void CPacket::Release(void)
{
	free(_chpBuffer);
	Clear();
}

void CPacket::Clear(void)
{
	_front = 0;
	_rear = 0;
}

int CPacket::MoveRearPos(int iSize)
{
	_rear += iSize;

	// TODO : 리턴값 의미?

	return iSize;
}

int CPacket::MoveFrontPos(int iSize)
{
	_front += iSize;

	return iSize;
}
