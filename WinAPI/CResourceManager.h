#pragma once

class CCore;
class CImage;
class CSound;
class CPokemonResource;

class CResourceManager : public SingleTon<CResourceManager>
{
	friend SingleTon<CResourceManager>;
	friend CCore;
private:
	CResourceManager();
	virtual ~CResourceManager();

private:
	unordered_map<wstring, CImage*> m_umapImage;
	unordered_map<wstring, CSound*> m_umapSound;
	map<int, CPokemonResource*> m_mapPokemonResource;

public:
	CImage* FindImg(const wstring& key);
	CImage* LoadImg(const wstring& key, const wstring& fileName);
	CImage* LoadImgWithPath(const wstring& key, const wstring& filePath);

	CSound* FindSound(const wstring& key);
	CSound* LoadSound(const wstring& key, const wstring& fileName);

	CPokemonResource* GetPokemonResource(const int& key);
private:
	void Init();
	void Release();
};

#define RESOURCE	CResourceManager::GetInstance()
