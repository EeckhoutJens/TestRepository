#pragma once
#include "BaseButton.h"
class KeyboardButton : public BaseButton
{
public:
	KeyboardButton(char keyboardCharacter);
	~KeyboardButton() override = default;
	char GetValue()const{return m_Value;}
private:
	char m_Value{};
};

