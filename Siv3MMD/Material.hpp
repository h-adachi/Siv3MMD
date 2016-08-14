#pragma once

#include <Siv3D.hpp>

namespace mmd
{
	class Material
	{
	public:
		bool Create(BinaryReader& reader);

		s3d::Material m_Material;
		int8 m_ToonIndex;
		int8 m_EdgeFlag;
		uint32 m_IndicesCount;
		String m_Texture;
		String m_Sphere;
	};
}
