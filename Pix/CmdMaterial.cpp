#include "MaterialManager.h"
#include "CmdMaterial.h"	

bool CmdSetMaterialEmissive::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 4)
    {
        return false;
    }

    X::Color color;
    color.r = std::stof(params[0]);
    color.g = std::stof(params[1]);
    color.b = std::stof(params[2]);
    color.a = std::stof(params[3]);

    MaterialManager::Get()->SetMaterialEmisive(color);
    return true;
}

bool CmdSetMaterialDiffuse::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 4)
    {
        return false;
    }

    X::Color color;
    color.r = std::stof(params[0]);
    color.g = std::stof(params[1]);
    color.b = std::stof(params[2]);
    color.a = std::stof(params[3]);

    MaterialManager::Get()->SetMaterialDiffuse(color);
    return true;
}

bool CmdSetMaterialSpecular::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 4)
    {
        return false;
    }

    X::Color color;
    color.r = std::stof(params[0]);
    color.g = std::stof(params[1]);
    color.b = std::stof(params[2]);
    color.a = std::stof(params[3]);

    MaterialManager::Get()->SetMaterialSpecular(color);
    return true;
}

bool CmdSetMaterialShininess::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1)
    {
        return false;
    }

    float shininess = std::stof(params[0]);
    MaterialManager::Get()->SetMaterialShininess(shininess);
    return true;
}
