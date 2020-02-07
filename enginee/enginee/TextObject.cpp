#include "stdafx.h"
#include "TextObject.h"
#include "Animation.h"
TextObject::TextObject()
{
}


TextObject::~TextObject()
{
}

void TextObject::Awake()
{
	animation->SetAnimation("TestAnimation");
}

void TextObject::Update()
{
}
