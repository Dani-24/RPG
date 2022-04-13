#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "Map.h"
#include "GuiManager.h"
#include "FadeToBlack.h"
#include "Player.h"
#include "EnemyMovement.h"
#include "EntityManager.h"
#include "Battle.h"
#include "Stages.h"
#include "Cock.h"
#include "Defs.h"
#include "Log.h"
#include "Camera.h"

Stages::Stages(App* application, bool start_enabled) : Module(application, start_enabled)
{
	name.Create("stages");

	actualStage = StageIndex::NONE;
	playerPtr = nullptr;

	onBattle = false;

	pause = false;
}

Stages::~Stages()
{}

bool Stages::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

bool Stages::Start()
{

	return true;
}

bool Stages::PreUpdate()
{
	bool ret = true;

	switch (actualStage)
	{
	case StageIndex::NONE:
		break;

	case StageIndex::TOWN:

		break;
	case StageIndex::DOJO:

		break;
	case StageIndex::SHOP:

		break;
	case StageIndex::SHOPSUB:

		break;
	case StageIndex::TAVERN:

		break;
	default:

		break;
	}

	return ret;
}

bool Stages::Update(float dt)
{
	switch (actualStage)
	{
	case StageIndex::NONE:
		break;

	case StageIndex::TOWN:

		break;
	case StageIndex::DOJO:

		break;
	case StageIndex::SHOP:

		break;
	case StageIndex::SHOPSUB:

		break;
	case StageIndex::TAVERN:

		break;
	default:

		break;
	}

	return true;
}

// Render bullshit
bool Stages::PostUpdate()
{
	bool ret = true;

	switch (actualStage)
	{
	case StageIndex::NONE:
		break;

	case StageIndex::TOWN:

		break;
	case StageIndex::DOJO:

		break;
	case StageIndex::SHOP:

		break;
	case StageIndex::SHOPSUB:

		break;
	case StageIndex::TAVERN:

		break;
	}

	if (onBattle == false) {

		app->map->Draw();
		app->guiManager->Draw();

		//PRINT THE PLAYER
		if (playerPtr != nullptr) {
			SDL_Rect rect = playerPtr->currentAnimation->GetCurrentFrame();
			if (playerPtr->PlayerErection == true) {
				app->render->DrawTexture(playerPtr->PlayerMTex, playerPtr->position.x, playerPtr->position.y, &rect);
			}
			if (playerPtr->PlayerErection == false) {
				app->render->DrawTexture(playerPtr->PlayerFTex, playerPtr->position.x, playerPtr->position.y, &rect);
			}
		}

		app->map->ReDraw();
	}

	if (npcListPtr != nullptr) {
		ListItem<NPC*>* npcInList;
		npcInList = npcListPtr->start;
		for (npcInList = npcListPtr->start; npcInList != NULL && ret == true; npcInList = npcInList->next)
		{
			if (npcInList->data->activeOnStage == app->stages->actualStage) {
				npcInList->data->spriteRect = npcInList->data->currentAnimation->GetCurrentFrame();
				app->render->DrawTexture(npcInList->data->spriteText, npcInList->data->position.x, npcInList->data->position.y, &npcInList->data->spriteRect);
			}
		}
	}

	return ret;
}

void Stages::ChangeStage(StageIndex newStage) {
	actualStage = newStage;

	// Reset map.cpp
	if (app->map->isEnabled() == true) {
		app->map->Disable();
		app->map->Enable();
		app->camera->FreeLimits();
	}

	switch (newStage)
	{
	case StageIndex::NONE:

		//app->map->RemoveCol();

		playerPtr = nullptr;
		delete playerPtr;

		npcListPtr = nullptr;
		delete npcListPtr;
		break;

	case StageIndex::TOWN:

		// Load Map
		if (app->map->isEnabled() == true) {

			app->map->Load("initial_town_map.tmx");

			playerPtr->position = { 950, 1000 };
			app->camera->OnTarget();

			LOG("Loading Town map");
		}

		break;
	case StageIndex::DOJO:

		// Load Map
		if (app->map->isEnabled() == true) {
			app->map->Load("initial_town_dojo.tmx");

			playerPtr->position = { 415, 270 };
			app->camera->OnTarget();

			LOG("Loading Dojo map");
		}

		break;
	case StageIndex::SHOP:

		// Load Map
		if (app->map->isEnabled() == true) {
			app->map->Load("initial_town_shop.tmx");

			playerPtr->position = { 255, 425 };
			app->camera->OnTarget();

			LOG("Loading Shop map");
		}

		break;
	case StageIndex::SHOPSUB:

		// Load Map
		if (app->map->isEnabled() == true) {
			app->map->Load("initial_town_under_shop.tmx");

			playerPtr->position = { 255, 80 };
			app->camera->OnTarget();

			LOG("Loading Shop lower floor map");
		}

		break;
	case StageIndex::TAVERN:

		// Load Map
		if (app->map->isEnabled() == true) {
			app->map->Load("initial_town_tavern.tmx");

			playerPtr->position = { 240, 550 };
			app->camera->OnTarget();

			LOG("Loading Tavern map");
		}

		break;
	default:

		break;
	}
}

// Called before quitting
bool Stages::CleanUp()
{

	return true;
}
