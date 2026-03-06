#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None,	// no culling used
	Back,	// culling items facing way from the camera
	Front,	// culling items facing way from the camera
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void OnNewFrame();
	void SetCullMode(CullMode mode);
	void CorrectUV(bool correctUV);

	// Start accepting vertices
	bool BeginDraw(Topology topology, bool applyTransform = false);
	// Add vertices to the list, onyl if drawing is enable
	void AddVertex(const Vertex& vertex);
	// Send all the stored vertices to the rasterizer as specified topology
	bool EndDraw();
private:
	PrimitivesManager();
	CullMode mCullMode = CullMode::None;
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
	bool mCorrectUV = false;
};