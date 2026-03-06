#pragma once
#include "Command.h"


class CmdSetCorrectUV : public Command
{
public:
	const char* GetName() override
	{
		return "SetCorrectUV";
	}
	const char* GetDescription() override
	{
		return "SetCorrectUV\n"
			"\n"
			"sets the correct uv using our primitives manager functions";
	}
	bool Execute(const std::vector<std::string>& params) override;

};
