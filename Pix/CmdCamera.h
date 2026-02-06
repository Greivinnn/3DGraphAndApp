#pragma once

#include "Command.h"

class CmdSetCameraPosition : public Command
{
	const char* GetName()
	{
		return "SetCameraPosition";
	}
};

class CmdSetCameraDirection : public Command
{
	const char* GetName()
	{
		return "SetCameraPosition";
	}
};

class CmdSetCameraNearPlane : public Command
{
	const char* GetName()
	{
		return "SetCameraPosition";
	}
};


class CmdSetCameraFarPlane : public Command
{
	const char* GetName()
	{
		return "SetCameraPosition";
	}
};

class CmdSetCameraFov : public Command
{
	const char* GetName()
	{
		return "SetCameraPosition";
	}
};
