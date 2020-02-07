#include "GameManager.h"
#include "Camera.h"
#include "Scene.h"
#include "GraphicManager.h"
#include "TextObject.h"
LPDIRECT3D9 GameManager::g_pD3D = LPDIRECT3D9();
LPDIRECT3DDEVICE9 GameManager::g_pd3dDevice = LPDIRECT3DDEVICE9();
Scene * GameManager::nowScene = nullptr;
void GameManager::Init(HWND hWnd)
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferHeight = Camera::ScreenHeight;
	d3dpp.BackBufferWidth = Camera::ScreenWidth;

	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);

	GraphicManager::Init(g_pd3dDevice);

	nowScene = new Scene();

	Instantiate<TextObject>({ 0.0f, 0.0f });
}

void GameManager::Update()
{
	nowScene->Update();
}

void GameManager::Render()
{
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// Begin the scene
	g_pd3dDevice->BeginScene();

	//������Ʈ ������
	GraphicManager::Render();

	// End the scene
	g_pd3dDevice->EndScene();


	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}
