#pragma once
class CAssetManager : public SingleInstance<CAssetManager>
{
public:
	map<LPCWSTR, CTexture*> textures;

public:
	CTexture* LoadTexture(LPCWSTR filename , int maxScene);
	void TermAssets();
};

