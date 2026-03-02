#pragma once
#include "Command.h"	

class CmdSetMaterialEmissive : public Command
{
public:
	const char* GetName() override
	{
		return "CmdSetMaterialEmissive";
	}

	const char* GetDescription() override
	{
		return
			"Sets the material emissiveness.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "CmdSetMaterialDiffuse";
	}

	const char* GetDescription() override
	{
		return
			"Sets the material diffuseness.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;

};

class CmdSetMaterialSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "CmdSetMaterialSpecular";
	}

	const char* GetDescription() override
	{
		return
			"Sets the material specular.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;

};

class CmdSetMaterialShininess : public Command
{
public:
	const char* GetName() override
	{
		return "CmdSetMaterialShininess";
	}

	const char* GetDescription() override
	{
		return
			"Sets the material shininess.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;

};