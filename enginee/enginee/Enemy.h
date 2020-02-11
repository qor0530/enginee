#pragma once
#include "GameObject.h"

class TextObject;
class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();

	void Awake() override;
	void OnDestroy() override;
	void Update() override;

private:
	TextObject * target;

};

