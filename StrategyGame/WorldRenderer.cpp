#include "WorldRenderer.h"

WorldRenderer* WorldRenderer::RENDERER = nullptr;

WorldRenderer * WorldRenderer::Get_The_Renderer_Instance()
{
	if (RENDERER != nullptr)
		return RENDERER;
	return RENDERER = new WorldRenderer();
}
