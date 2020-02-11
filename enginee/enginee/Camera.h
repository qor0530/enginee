#pragma once

#include <d3dx9.h>

static class Camera // static �� Ŭ������ �ȿ� �� static �̾���Ѵ�
{
public:
	Camera();
	~Camera();

	static void Update();

	static int ScreenWidth; // ����
	static int ScreenHeight; // ����

	static D3DXVECTOR2 position;
	static D3DXVECTOR2 scale;
	static D3DXMATRIX matrix;
	static float degree;

	static void AddShake(float shake);

	static float shake;
};

