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
	void LateUpdate() override;
private:
	void PlayerMove();
	void CameraMove();
	void MouseInput();
};

