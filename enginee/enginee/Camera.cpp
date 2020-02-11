#include "Camera.h"

int Camera::ScreenWidth = 1280;
int Camera::ScreenHeight = 720;

D3DXMATRIX Camera::matrix = D3DMATRIX();
D3DXVECTOR2 Camera::scale = { 1.0f, 1.0f }; 
D3DXVECTOR2 Camera::position = { 0.0f, 0.0f };

float Camera::degree = 0.0f;
float Camera::shake = 50.0f;

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Update()
{
	if (shake > 0.0f)
	{
		auto degree_ = rand() % 360;
		auto radian_ = D3DXToRadian(degree_);
		position += D3DXVECTOR2(cos(radian_)*shake, sin(radian_)*shake);
		shake *= 0.9f;
	}
	else
	{
		shake = 0.0f;
	}
	D3DXMATRIX centerMatrix, positionMatrix, scaleMatrix, rotateMatrix;

	D3DXMatrixTranslation(&positionMatrix, -position.x, -position.y, 0.0f);
	D3DXMatrixTranslation(&centerMatrix, ScreenWidth*0.5f, ScreenHeight*0.5f, 0.0f);
	D3DXMatrixScaling(&scaleMatrix, scale.x, scale.y, 0.0f);
	D3DXMatrixRotationZ(&rotateMatrix, D3DXToRadian(degree));
	matrix = positionMatrix*scaleMatrix*rotateMatrix*centerMatrix;
}

void Camera::AddShake(float shake)
{
	Camera::shake += shake;
}

