#include "CmdAddressMode.h"
#include "TextureManager.h"

bool CmdAddressMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	AddressMode addressMode = AddressMode::Border;
	if (params[0] == "border") { addressMode = AddressMode::Border; }
	else if (params[0] == "clamp") { addressMode = AddressMode::Clamp; }
	else if (params[0] == "wrap") { addressMode = AddressMode::Wrap; }
	else if (params[0] == "mirror") { addressMode = AddressMode::Mirror; }
	else
	{
		return false;
	}
	TextureManager::Get()->SetAddressMode(addressMode);
	return true;
}
