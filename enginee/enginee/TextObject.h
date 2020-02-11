#pragma once
#include "GameObject.h"
#include <ctime>
class TextObject :
	public GameObject
{
public:
	TextObject();
	~TextObject();

	clock_t deadTime;

	void Awake() override;
	void Update() override;
	void LateUpdate() override;
	void OnRender() override;
	void OnCollisionEnter(GameObject * gameObject) override;
	void OnDestroy() override;
private:
	void PlayerMove();
	void CameraMove();
	void MouseInput();
};

