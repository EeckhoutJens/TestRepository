#pragma once
#include <vector>
class Command;
namespace dae
{
	class InputManager
	{
	public:
		void HandleInput(int controllerID);
		bool IsPressed(char keyboardButton) const;
		bool IsPressed(DWORD controllerButton) const;
		void AssignCommand(Command* command);

	private:
		XINPUT_STATE m_State{};
		std::vector<Command*> m_VecCommands{};
		Command* DefaultCommand{};

		bool m_IsAPressed{ false };
	};


}