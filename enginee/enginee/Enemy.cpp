#include "stdafx.h"
#include "Enemy.h"
#include "TextObject.h"
#include "Animation.h"
Enemy::Enemy():
	target(nullptr)
{
}


Enemy::~Enemy()
{
}

void Enemy::Awake()
{
	name = "Enemy";
	sortingLayer = 1;
	animation->SetAnimation("Enemy");

	target = static_cast<TextObject *>(GameObject::Find("Player"));
}

void Enemy::OnDestroy()
{
	PlaySound(L"./Resource/Sound/Die.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void Enemy::Update()
{
	target = static_cast<TextObject *>(GameObject::Find("Player"));

	if (target == nullptr)
	{
		return;
	}
	auto diff = target->position - position;
	D3DXVECTOR2 result = { 0.0f, 0.0f };
	D3DXVec2Normalize(&result, &diff);
	position += result * 5.0f;
}
