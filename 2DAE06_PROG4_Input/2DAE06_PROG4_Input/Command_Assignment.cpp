#include "pch.h"
#include <iostream>
#include <thread>
#include "InputManager.h"
#include "Audio.h"
#include "Locator.h"
#include "KeyboardButton.h"
#include "ControllerButton.h"
#include "Commands.h"
#define Exercise2
int main()
{
	std::cout << "USE A CONTROLLER TO TEST INPUT" << std::endl;
	Locator::Initialize();
	Audio *service = new ConsoleAudio;
	Locator::Provide(service);

	ControllerButton ButtonA{ XINPUT_GAMEPAD_A };
	ControllerButton ButtonB{ XINPUT_GAMEPAD_B };
	ControllerButton ButtonY{ XINPUT_GAMEPAD_Y };
	ControllerButton ButtonX{ XINPUT_GAMEPAD_X };

#ifdef Exercise2
	Command* cmdFart = new FartCommand();
	Command* cmdJump = new JumpCommand();
	Command* cmdAttack = new AttackCommand();
	Command* cmdDodge = new DodgeCommand();

	cmdJump->AssignButton(&ButtonA);
	cmdAttack->AssignButton(&ButtonB);
	cmdDodge->AssignButton(&ButtonX);
	cmdFart->AssignButton(&ButtonY);
#endif
	

	auto inputManager = dae::InputManager();
#ifdef Exercise2
	inputManager.AssignCommand(cmdJump);
	inputManager.AssignCommand(cmdAttack);
	inputManager.AssignCommand(cmdDodge);
	inputManager.AssignCommand(cmdFart);
#endif



	auto t = std::chrono::high_resolution_clock::now();
	while (true)
	{
		inputManager.HandleInput(0);

#ifdef Exercise1
		if (inputManager.IsPressed(ButtonA.GetValue()))
			std::cout << "Button A has been pressed" << std::endl;
		else if (inputManager.IsPressed(ButtonB.GetValue()))
			std::cout << "Button B has been pressed" << std::endl;
		else if (inputManager.IsPressed(ButtonY.GetValue()))
			std::cout << "Button Y has been pressed" << std::endl;
		else if (inputManager.IsPressed(ButtonX.GetValue()))
		{
			std::cout << "Button X has been pressed" << std::endl;
			break;
		}
#endif
		t += std::chrono::milliseconds(16); // we want 60 fps
		std::this_thread::sleep_until(t);
	}
	std::cout << "Let's end." << std::endl;

}