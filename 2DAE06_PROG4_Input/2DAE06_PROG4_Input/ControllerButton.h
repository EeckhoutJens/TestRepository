#pragma once
#include "BaseButton.h"
class ControllerButton : public BaseButton
{
public:
	ControllerButton(DWORD chosenButton);
	~ControllerButton() override = default;
	DWORD GetValue()const{return value;}
private:
	DWORD value{};
};

