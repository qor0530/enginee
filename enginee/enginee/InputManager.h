#pragma once

#include <vector>
#include <d3dx9.h>

class KeyState
{
public:
	int vkCode;
	bool isOn;		//Ű�� ��� ������ ������
	bool isDown;	//Ű�� �ѹ� ���ȴ°�
	bool isUp;		//Ű�� ���� ���°�

	KeyState(int vkCode) :
		vkCode(vkCode),
		isOn(false),
		isDown(false),
		isUp(false)
	{

	}
	
};
static class InputManager
{
public:
	InputManager();
	~InputManager();

	static D3DXVECTOR2 mousePosistion;

	static void Init(HWND hWnd);
	static void Update();
	static HWND hWnd;
	enum class KeyCode { W, A, S, D, Space, L_mouse, R_mouse, MAX };

	static std::vector<KeyState *> KeyStateVector;

	static void AddKey(KeyCode keyCode, int vkCode);

	static bool GetKey(KeyCode keyCode);
	static bool GetKeyDown(KeyCode keyCode);
	static bool GetKeyUp(KeyCode keyCode);
};

