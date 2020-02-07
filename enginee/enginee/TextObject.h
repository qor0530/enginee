#pragma once
#include "GameObject.h"
class TextObject :
	public GameObject
{
public:
	TextObject();
	~TextObject();

	void Awake() override;
	void Update() override;
};

