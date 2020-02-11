#include "stdafx.h"
#include "Animation.h"
#include "GraphicManager.h"

#include "GameObject.h"
#include "BoxCollider.h"
void Animation::Update()
{
	if (timePerFrame < 0)
	{
		return;
	}

	auto curTime = clock();

	if (lastChangeTime + timePerFrame < curTime)
	{
		lastChangeTime = curTime;

		if (nowFrame.x + frameSize.x + 1.0f >= imageSize.x)
		{
			nowFrame.x = 0;
		}
		else
		{
		nowFrame.x += frameSize.x;
		}
	}
}

void Animation::SetAnimation(std::string textureName)
{
	timePerFrame = -1;
	this->textureName = textureName;
	frameSize = imageSize = GraphicManager::GetTextureSize(textureName);
	lastChangeTime = clock();
	if (textureName == "TestAnimation")
	{
		//clock_t �� ���� �� 1�ʿ� 1000 ms 
		timePerFrame = 100;
		frameSize = { 100, 100 };
	}

	parent->collider->size = frameSize;
}

RECT Animation::GetRect()
{
	int left = nowFrame.x;
	int top = 0;
	int right = left + frameSize.x;
	int bottom = top + frameSize.y;

	return RECT{ left, top, right, bottom }; // �߰�ȣ �˻��غ�
}

Animation::Animation() : textureName(""),
		imageSize({ 0.0f },{ 0.0f }),
		frameSize({ 0.0f },{ 0.0f }),
		nowFrame({ 0.0f }, { 0.0f }),
		lastChangeTime(0.0f),
		timePerFrame(-1.0f)
{
}


Animation::~Animation()
{
}
