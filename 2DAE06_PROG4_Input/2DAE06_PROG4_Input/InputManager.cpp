#include "pch.h"
#include "InputManager.h"
#include "Commands.h"
#include "BaseButton.h"
#include "KeyboardButton.h"
#include "ControllerButton.h"
//Reference: https://katyscode.wordpress.com/2013/08/30/xinput-tutorial-part-1-adding-gamepad-support-to-your-windows-game/



void dae::InputManager::HandleInput(int controllerID)
{
	RtlZeroMemory(&m_State, sizeof(XINPUT_STATE));
	if (XInputGetState(controllerID, &m_State) == ERROR_SUCCESS)
	{
	}


	for (Command* pCommand : m_VecCommands)
	{
		KeyboardButton* pKeyboardButton = dynamic_cast<KeyboardButton*>(pCommand->GetButton());
		if (pKeyboardButton)
		{
			if (IsPressed(pKeyboardButton->GetValue()))
			{
				pCommand->Execute();
			}
		}

		ControllerButton* pControllerButton = dynamic_cast<ControllerButton*>(pCommand->GetButton());
		if (pControllerButton)
		{
			if (IsPressed(pControllerButton->GetValue()))
			{
				pCommand->Execute();
			}
		}
	}

}

bool dae::InputManager::IsPressed(char keyboardButton) const
{
	return GetKeyState(keyboardButton) & 0x8000;
}

bool dae::InputManager::IsPressed(DWORD controllerButton) const
{
	return m_State.Gamepad.wButtons & controllerButton;
}

void dae::InputManager::AssignCommand(Command* command)
{
	m_VecCommands.push_back(command);
}

