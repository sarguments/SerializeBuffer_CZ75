#pragma once

/*---------------------------------------------------------------

Packet.

네트워크 패킷용 클래스.
간편하게 패킷에 순서대로 데이타를 In, Out 한다.

- 사용법.

CPacket cPacket;

넣기.
clPacket << 40030;	or	clPacket << iValue;	(int 넣기)
clPacket << 3;		or	clPacket << byValue;	(BYTE 넣기)
clPacket << 1.4;	or	clPacket << fValue;	(float 넣기)

빼기.
clPacket >> iValue;	(int 빼기)
clPacket >> byValue;	(BYTE 빼기)
clPacket >> fValue;	(float 빼기)

!.	삽입되는 데이타 FIFO 순서로 관리된다.
큐가 아니므로, 넣기(<<).빼기(>>) 를 혼합해서 사용하면 안된다.

----------------------------------------------------------------*/

class CPacket
{
public:
	enum en_PACKET
	{
		eBUFFER_DEFAULT = 1400		// 패킷의 기본 버퍼 사이즈.
	};

	//////////////////////////////////////////////////////////////////////////
	// 생성자, 파괴자.
	//
	// Return:
	//////////////////////////////////////////////////////////////////////////
	CPacket();
	CPacket(int iBufferSize);

	virtual	~CPacket();

	//////////////////////////////////////////////////////////////////////////
	// 패킷  파괴.
	//
	// Parameters: 없음.
	// Return: 없음.
	//////////////////////////////////////////////////////////////////////////
	void	Release(void);

	//////////////////////////////////////////////////////////////////////////
	// 패킷 청소.
	//
	// Parameters: 없음.
	// Return: 없음.
	//////////////////////////////////////////////////////////////////////////
	void	Clear(void);

	//////////////////////////////////////////////////////////////////////////
	// 버퍼 사이즈 얻기.
	//
	// Parameters: 없음.
	// Return: (int)패킷 버퍼 사이즈 얻기.
	//////////////////////////////////////////////////////////////////////////
	int	GetBufferSize(void) { return _bufferSize; }
	//////////////////////////////////////////////////////////////////////////
	// 현재 사용중인 사이즈 얻기.
	//
	// Parameters: 없음.
	// Return: (int)사용중인 데이타 사이즈.
	//////////////////////////////////////////////////////////////////////////
	int		GetDataSize(void) { return _dataSize; }

	//////////////////////////////////////////////////////////////////////////
	// 버퍼 포인터 얻기.
	//
	// Parameters: 없음.
	// Return: (char *)버퍼 포인터.
	//////////////////////////////////////////////////////////////////////////
	char	*GetBufferPtr(void) { return _buffer; }

	//////////////////////////////////////////////////////////////////////////
	// 버퍼 Pos 이동. (음수이동은 안됨)
	// GetBufferPtr 함수를 이용하여 외부에서 강제로 버퍼 내용을 수정할 경우 사용.
	//
	// Parameters: (int) 이동 사이즈.
	// Return: (int) 이동된 사이즈.
	//////////////////////////////////////////////////////////////////////////
	int		MoveRearPos(int iSize);
	int		MoveFrontPos(int iSize);

	/* ============================================================================= */
	// 연산자 오퍼레이터.
	/* ============================================================================= */
	CPacket	&operator = (CPacket &clSrcPacket);

	//////////////////////////////////////////////////////////////////////////
	// 넣기.	각 변수 타입마다 모두 만듬.
	//////////////////////////////////////////////////////////////////////////
	CPacket	&operator << (BYTE byValue);
	CPacket	&operator << (char chValue);

	CPacket	&operator << (short shValue);
	CPacket	&operator << (WORD wValue);

	CPacket	&operator << (int iValue);
	CPacket	&operator << (DWORD dwValue);
	CPacket	&operator << (float fValue);

	CPacket	&operator << (__int64 iValue);
	CPacket	&operator << (double dValue);

	//////////////////////////////////////////////////////////////////////////
	// 빼기.	각 변수 타입마다 모두 만듬.
	//////////////////////////////////////////////////////////////////////////
	CPacket	&operator >> (BYTE &byValue);
	CPacket	&operator >> (char &chValue);

	CPacket	&operator >> (short &shValue);
	CPacket	&operator >> (WORD &wValue);

	CPacket	&operator >> (int &iValue);
	CPacket	&operator >> (DWORD &dwValue);
	CPacket	&operator >> (float &fValue);

	CPacket	&operator >> (__int64 &iValue);
	CPacket	&operator >> (double &dValue);

	//////////////////////////////////////////////////////////////////////////
	// 데이타 얻기.
	//
	// Parameters: (char *)Dest 포인터. (int)Size.
	// Return: (int)복사한 사이즈.
	//////////////////////////////////////////////////////////////////////////
	int		GetData(char *chpDest, int iSize);

	//////////////////////////////////////////////////////////////////////////
	// 데이타 삽입.
	//
	// Parameters: (char *)Src 포인터. (int)SrcSize.
	// Return: (int)복사한 사이즈.
	//////////////////////////////////////////////////////////////////////////
	int		PutData(char *chpSrc, int iSrcSize);

protected:
	char* _buffer;
	int	_bufferSize;

	// 사용중인 사이즈
	int	_dataSize;

	int _front;
	int _rear;
};
