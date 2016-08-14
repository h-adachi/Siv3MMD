
# include <Siv3D.hpp>
# include "Model.hpp"

void Main()
{
	Graphics::SetBackground(Palette::White);
	Camera camera;
	camera.lookat = Vec3(0, 12, 0);
	camera.pos = Vec3(0, 16, -28);
	Graphics3D::SetCamera(camera);

	mmd::Model model;
	model.Create();

	while (System::Update())
	{
		Graphics3D::FreeCamera();
		model.Update();
		model.Draw();
	}
}
