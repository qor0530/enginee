#pragma once
static class Camera // static 인 클래스는 안에 도 static 이어야한다
{
public:
	Camera();
	~Camera();

	static int ScreenWidth; // 여기
	static int ScreenHeight; // 여기
};

