#include "Rasterizer.h"

void DrawLineHoriz(const Vertex& left, const Vertex& right)
{
	float dx = right.pos.x - left.pos.x;
	int startX = static_cast<int>(left.pos.x);
	int endX = static_cast<int>(right.pos.x);
	for (int x = startX; x < endX; ++x)
	{
		float t = static_cast<float>(x - startX) / dx;
		Vertex v = LerpVertex(left, right, t);
		Rasterizer::Get()->DrawPoint(v);
	}
}

void DrawLineVertical(const Vertex& bottom, const Vertex& top)
{
	float dy = top.pos.y - bottom.pos.y;
	int startY = static_cast<int>(bottom.pos.y);
	int endY = static_cast<int>(top.pos.y);
	for (int y = startY; y <= endY; ++y)
	{
		float t = static_cast<float>(y - startY) / dy;
		Vertex v = LerpVertex(bottom, top, t);
		Rasterizer::Get()->DrawPoint(v);
	}
}

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;
	return &sInstance;
}

void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::DrawPoint(const Vertex& vertex)
{
	int x = static_cast<int>(vertex.pos.x);
	int y = static_cast<int>(vertex.pos.y);
	SetColor(vertex.color);
	X::DrawPixel(x, y, vertex.color);
}
void Rasterizer::DrawLine(const Vertex& a, const Vertex& b)
{
	float dx = b.pos.x - a.pos.x;
	float dy = b.pos.y - a.pos.y;
	// if true, line is going up/down or move vertical than horizontal
	if (MathHelper::CheckEqual(dx, 0.0f) || abs(dy / dx) >= 1.0f)
	{
		if (a.pos.y < b.pos.y)
		{
			DrawLineVertical(a, b);
		}
		else
		{
			DrawLineVertical(b, a);
		}
	}
	// line is going more horizontal than vertical
	else
	{
		if (a.pos.x < b.pos.x)
		{
			DrawLineHoriz(a, b);
		}
		else
		{
			DrawLineHoriz(b, a);
		}
	}
}
void Rasterizer::DrawTriangle(const Vertex& a, const Vertex& b, Vertex& c)
{
	DrawLine(a, b);
	DrawLine(b, c);
	DrawLine(c, a);
}