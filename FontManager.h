#pragma once
#define FONTAMOUNT 1
enum Direction
{
	LEFT,
	CENTER
};

class FontManager : public SingleInstance<FontManager>
{
public:
	LPD3DXFONT font[FONTAMOUNT];

	void InitFont(LPCWSTR setFont, int xSize, int ySize, int index)
	{
		if (FAILED(D3DXCreateFontW(
			DXUTGetD3D9Device(),
			ySize,
			xSize,
			FW_BOLD,
			1,
			false,
			DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS,
			ANTIALIASED_QUALITY,
			FF_DONTCARE,
			setFont,
			&font[index]
		)))
		{
			MessageBox(DXUTGetHWND(),
				L"����",
				L"��Ʈ�� �ҷ����� ���߽��ϴ�.",
				MB_OK);
		}
	}

	void OnRenderFont(LPCWSTR str, int x, int y, D3DCOLOR color, int index, int direction = DT_LEFT)
	{
		RECT rect = { x,  y,
					  x + 1000 , y + 1000 };

		font[index]->DrawTextW(
			NULL,
			str,
			-1,
			&rect,
			direction,
			color
		);
	}
};