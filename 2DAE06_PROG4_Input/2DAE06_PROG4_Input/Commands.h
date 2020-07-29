#pragma once
#include <iostream>
#include "Locator.h"
#include "BaseButton.h"

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
	void AssignButton(BaseButton* buttonToAssign)
	{
		if (!m_pButton)
		{
			m_pButton = buttonToAssign;
		}
		else
		{
			std::cout << "\nA button has already been assigned to this command\n";
		}
	}
	BaseButton* GetButton() const { return m_pButton; }


private:
	BaseButton* m_pButton{};
};

class JumpCommand final : public Command
{
public:
	 void Execute() override { std::cout << "I'm jumping\n"; Locator::GetAudio()->PlaySound(1); };
};

class DodgeCommand final : public Command
{
public:
	 void Execute() override { std::cout << "I'm dodging\n"; Locator::GetAudio()->PlaySound(2);
	};
};

class FartCommand final : public Command
{
	 void Execute() override { std::cout << "I'm farting\n"; Locator::GetAudio()->PlaySound(3);
	};
};

class AttackCommand final : public Command
{
	 void Execute() override { std::cout << "I'm attacking\n"; Locator::GetAudio()->PlaySound(4);
	};
};
