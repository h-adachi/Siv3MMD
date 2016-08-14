#pragma once

#include <string>
#include <vector>
#include <Siv3D.hpp>
#include "Material.hpp"

namespace mmd
{
	class PMD
	{
	public:
		PMD();
		virtual ~PMD();
		bool Create(BinaryReader& reader);
		void Draw();

	private:
		float m_Version;
		std::string m_ModelName;
		std::string m_Comment;
		
		Mesh* m_Mesh;
		Array<mmd::Material> m_Materials;
	};
}
