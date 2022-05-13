#include "App.h"
#include "Inventory.h"

#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"

#include "Scene.h"
#include "Stages.h"
#include "GuiManager.h"
#include "FadeToBlack.h"
#include "Player.h"
#include "Camera.h"

#include "Battle.h"

Inventory::Inventory(App* application, bool start_enabled) : Module(application, start_enabled)
{
	name.Create("inventory");
}

Inventory::~Inventory()
{}

bool Inventory::Awake(pugi::xml_node& config)
{
	LOG("Awakening Inventory");
	bool ret = true;

	return ret;
}

bool Inventory::Start()
{
	LOG("Starting Inventory");

	// Block player movement
	app->scene->player->canMove = false;

	if (app->battle->isEnabled()) {
		inventoryOnBattle = true;
	}

	// Load party characters
	charactersOnUI = app->stages->partyListPtr;
	//itemsOnUI = app->stages->itemsList;

	// Load assets

	if (inventoryOnBattle == false) {
		inventoryBG = app->tex->Load("Assets/gui/inventory/ui_inventory.png");
	}
	else {
		inventoryBG = app->tex->Load("Assets/gui/inventory/ui_inventory_battle.png");
	}

	characterBG = app->tex->Load("Assets/gui/inventory/ui_inventory_char.png");

	// Esta deberia ir con un animation que cada frame sea cada arma
	//weaponType = app->tex->Load("Assets/gui/inventory/ui_inventory.png");

	// Buttons
	backButton = (GuiButton*)app->guiManager->CreateGuiControl(GuiControlType::BUTTON, 298, "Back", { (-app->camera->GetPos().x / 2) + 20, (-app->camera->GetPos().y / 2) + 10, 74, 32 }, this);
	statsButton = (GuiButton*)app->guiManager->CreateGuiControl(GuiControlType::BUTTON, 299, "Stats", { (-app->camera->GetPos().x / 2) + 20, (-app->camera->GetPos().y / 2) + 45, 74, 32 }, this);

	return true;
}

bool Inventory::PreUpdate()
{
	bool ret = true;

	// Get Inputs here

	return ret;
}

bool Inventory::Update(float dt)
{

	if (app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_UP) {
		Disable();
	}

	return true;
}

// Render bullshit
bool Inventory::PostUpdate()
{
	bool ret = true;

	int x = -app->camera->GetPos().x / 2;
	int y = -app->camera->GetPos().y / 2;

	//app->font->DrawText("Inventory is Open", x, y);

	//LOG("%d %d %d %d %d %d", x, y, app->camera->GetPos().x, app->camera->GetPos().y, app->scene->player->position.x, app->scene->player->position.y);

	// Draw UI

	app->render->DrawTexture(inventoryBG, x, y);
	
	// Checkear miembros de la party y imprimir sus carteles

	if (app->battle->isEnabled() == false) {
		ListItem<Character*>* ch = app->scene->partyList.start;

		int charX = x + 110,
			charY = y + 5;

		for (ch; ch != NULL; ch = ch->next)
		{
			app->render->DrawTexture(characterBG, charX, charY);

			app->render->DrawTexture(ch->data->spriteFace, charX + 15, charY + 20);

			app->font->DrawText(ch->data->name, charX + 25, charY - 2);
			charX += 130;
		}
	}

	return ret;
}

bool Inventory::CleanUp()
{
	LOG("Closing Inventory");

	// Allow player to move
	app->scene->player->canMove = true;

	inventoryOnBattle = false;

	buttonsIDCount = 300;

	backButton->state = GuiControlState::DISABLED;
	statsButton->state = GuiControlState::DISABLED;

	return true;
}

bool Inventory::OnGuiMouseClickEvent(GuiControl* control)
{
	switch (control->type)
	{		
	case GuiControlType::BUTTON:
	{
			//Checks the GUI element ID
		if (control->id == 298)
		{

			LOG("Click on Back");

			Disable();
		}

		if (control->id == 299)
		{
			LOG("Stats button");
		}
		
		for (int i = 300; i < buttonsIDCount; i++) {
			if (control->id == i) {
				// PRESS ON X BUTTON
			}
		}

		default: break;
		}
	}
	return true;
}
