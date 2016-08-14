#include <string>
#include "Material.hpp"

void LoadTexture(const String& current, String& dest, const std::string src)
{
	if (!src[0]) return;

	size_t length = src.length();
	dest.resize(length);
	size_t out;
	mbstowcs_s(&out, &dest[0], length, src.c_str(), _TRUNCATE);
	dest = current + dest;
	if (!TextureAsset::IsRegistered(dest))
	{
		TextureAsset::Register(dest, dest, TextureDesc::For3D);
	}
}

bool mmd::Material::Create(BinaryReader & reader)
{
	float color;
	reader.read(color);
	m_Material.diffuse.r = color;
	reader.read(color);
	m_Material.diffuse.g = color;
	reader.read(color);
	m_Material.diffuse.b = color;
	reader.read(color);
	m_Material.diffuse.a = color;
	reader.read(color);
	m_Material.specular.a = color;
	reader.read(color);
	m_Material.specular.r = color;
	reader.read(color);
	m_Material.specular.g = color;
	reader.read(color);
	m_Material.specular.b = color;
	reader.read(color);
	m_Material.ambient.r = color;
	reader.read(color);
	m_Material.ambient.g = color;
	reader.read(color);
	m_Material.ambient.b = color;

	reader.read(m_ToonIndex);
	reader.read(m_EdgeFlag);
	reader.read(m_IndicesCount);

	std::string fileInfo;
	fileInfo.resize(20);
	reader.read(&fileInfo[0], 20);
	std::string textureFileName;
	std::string sphereFileName;

	if (fileInfo[0])
	{
		// 読み込んだfilenameに*が存在した場合はスフィア名も含む.
		if (fileInfo.find("*") != -1)
		{
			size_t index = fileInfo.find("*");
			textureFileName = fileInfo.substr(0, index);
			sphereFileName = fileInfo.substr(index + 1);
		}
		else
		{
			textureFileName = fileInfo;
		}
		// カレントパスを取得.
		String currentPath = reader.path();
		size_t index = currentPath.lastIndexOf(L"/") + 1;
		currentPath = currentPath.substr(0, index);

		LoadTexture(currentPath, m_Texture, textureFileName);
		LoadTexture(currentPath, m_Sphere, sphereFileName);
	}
	return false;
}
