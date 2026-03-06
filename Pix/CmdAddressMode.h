#pragma once
#include "Command.h"


class CmdAddressMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetAddressMode";
	}
	const char* GetDescription() override
	{
		return "SetAddressMode\n"
			"\n"
			"sets the correct address mode";
	}
	bool Execute(const std::vector<std::string>& params) override;

};
