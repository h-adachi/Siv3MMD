#include <string>
#include "Model.hpp"

mmd::Model::Model()
{
}

mmd::Model::~Model()
{
}

bool mmd::Model::Create(const FilePath& filename)
{
	BinaryReader reader(filename);
	return m_Pmd.Create(reader);
}

void mmd::Model::Update()
{
}

void mmd::Model::Draw()
{
	m_Pmd.Draw();
}
