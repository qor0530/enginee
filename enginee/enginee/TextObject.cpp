#include "stdafx.h"
#include "TextObject.h"
#include "Animation.h"
#include "InputManager.h"
#include "Camera.h"
#include "Scene.h"
#include "Bullet.h"
TextObject::TextObject()
{
}


TextObject::~TextObject()
{
}

void TextObject::Awake()
{
	animation->SetAnimation("TestAnimation");
	position = { 0.0f, 0.0f };
	sortingLayer = 1;
}

void TextObject::Update()
{
	PlayerMove();
	MouseInput();

}
void TextObject::LateUpdate()
{
	CameraMove();
}

void TextObject::PlayerMove()
{
	if (InputManager::GetKey(InputManager::KeyCode::W))
	{
		position.y -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::A))
	{
		position.x -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::S))
	{
		position.y += 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::D))
	{
		position.x += 5.0f;
	}

	//position = InputManager::mousePosistion;
}

void TextObject::CameraMove()
{
	auto diff = position - Camera::position;

	Camera::position += diff * 0.05f;

}

void TextObject::MouseInput()
{
	auto mousePosition = InputManager::mousePosistion;

	auto diff = mousePosition - position;

	auto radian = atan2(diff.y, diff.x);

	degree = D3DXToDegree(radian);

	D3DXVECTOR2 normal;
	
	D3DXVec2Normalize(&normal, &diff);

	if (InputManager::GetKeyDown(InputManager::KeyCode::L_mouse))
	{
		auto bullet = Instantiate<Bullet>(position);
		if (bullet != nullptr)
		{
			bullet->SetOption(normal, 0.0f);
		}
	}

}
