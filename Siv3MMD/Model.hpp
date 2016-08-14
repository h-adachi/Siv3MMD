#pragma once

#include <string>
#include <Siv3D.hpp>
#include "PMD.hpp"

namespace mmd
{
	class Model
	{
	public:
		Model();
		virtual ~Model();

		// モデルの生成
		// filename : PMDファイルを指定
		bool Create(const FilePath& filename);
		// 更新
		void Update();
		// 描画
		void Draw();


	private:
		PMD m_Pmd;
	};
}
