#include "Player.h"

#include "App.h"
#include "Render.h"
#include "Audio.h"
#include "Camera.h"
#include "Textures.h"
#include "Input.h"
#include "Player.h"
#include "Log.h"
#include "Window.h"
#include "Scene.h"
#include "Map.h"
#include "Stages.h"
#include "Battle.h"
#include "FadeToBlack.h"
#include "Shop.h"

#include <time.h>

Player::Player( int x, int y) : Character(CharacterType::PLAYER)
{

	position = {x,y};

	//----------------------------------------------------------------------------------Overworld------------------------------------

	/*walkAnimDown.PushBack({ 9,10,31,46 });
	walkAnimDown.PushBack({ 62,8,31,46 });
	walkAnimDown.PushBack({ 114,10,31,46 });
	walkAnimDown.loop = true;
	walkAnimDown.speed = 0.006f;

	walkAnimUp.PushBack({ 9,218,31,46 });
	walkAnimUp.PushBack({ 62,221,31,46 });
	walkAnimUp.PushBack({ 114,218,31,47 });
	walkAnimUp.loop = true;
	walkAnimUp.speed = 0.006f;

	walkAnimL.PushBack({ 11,82,26,44 });
	walkAnimL.PushBack({ 64,80,26,45 });
	walkAnimL.PushBack({ 116,82,27,44 });
	walkAnimL.loop = true;
	walkAnimL.speed = 0.006f;

	walkAnimR.PushBack({ 11,153,27,44 });
	walkAnimR.PushBack({ 64,150,27,44 });
	walkAnimR.PushBack({ 116,153,27,44 });
	walkAnimR.loop = true;
	walkAnimR.speed = 0.006f;

	idleAnimR.PushBack({ 64,150,27,44 });
	idleAnimL.PushBack({ 64,80,26,45 });
	idleAnimUp.PushBack({ 62,221,31,46 });
	idleAnimDown.PushBack({ 62,8,31,46 });*/

	walkAnimDown.PushBack({ 0,0,48,64 });
	walkAnimDown.PushBack({ 48,0,48,64 });
	walkAnimDown.PushBack({ 96,0,48,64 });
	walkAnimDown.loop = true;
	walkAnimDown.speed = 0.006f;

	walkAnimUp.PushBack({ 0,192,48,64 });
	walkAnimUp.PushBack({ 48,192,48,64 });
	walkAnimUp.PushBack({ 96, 192,48,64 });
	walkAnimUp.loop = true;
	walkAnimUp.speed = 0.006f;

	walkAnimL.PushBack({ 0,64,48,64 });
	walkAnimL.PushBack({ 48,64,48,64 });
	walkAnimL.PushBack({ 96,64,48,64 });
	walkAnimL.loop = true;
	walkAnimL.speed = 0.006f;

	walkAnimR.PushBack({ 0,128,48,64 });
	walkAnimR.PushBack({ 48,128,48,64 });
	walkAnimR.PushBack({ 96,128,48,64 });
	walkAnimR.loop = true;
	walkAnimR.speed = 0.006f;

	idleAnimR.PushBack({ 48,128,48,64 });
	idleAnimL.PushBack({ 48,64,48,64 });
	idleAnimUp.PushBack({ 48,192,48,64 });
	idleAnimDown.PushBack({ 48,0,48,64 });

	//----------------------------------------------------------------------------------Battle Male------------------------------------

	idleBattleM.PushBack({ 0, 0, 140, 83 });
	idleBattleM.PushBack({ 140 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 280 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 420 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 560 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 700 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 840 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 980 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 1120 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 1260 , 0 , 140 , 83 });
	idleBattleM.PushBack({ 1400 , 0 , 140 , 83 });
	idleBattleM.loop = true;
	idleBattleM.speed = 0.015f;

	attackM.PushBack({ 0 , 83 , 140 , 83 });
	attackM.PushBack({ 140 , 83 , 140 , 83 });
	attackM.PushBack({ 280 , 83 , 140 , 83 });
	attackM.PushBack({ 420 , 83 , 140 , 83 });
	attackM.PushBack({ 560 , 83 , 140 , 83 });
	attackM.PushBack({ 700 , 83 , 140 , 83 });
	attackM.PushBack({ 0, 0, 140, 83 });
	attackM.PushBack({ 140 , 0 , 140 , 83 });
	attackM.PushBack({ 280 , 0 , 140 , 83 });
	attackM.PushBack({ 420 , 0 , 140 , 83 });
	attackM.PushBack({ 560 , 0 , 140 , 83 });
	attackM.PushBack({ 700 , 0 , 140 , 83 });
	attackM.PushBack({ 840 , 0 , 140 , 83 });
	attackM.PushBack({ 980 , 0 , 140 , 83 });
	attackM.PushBack({ 1120 , 0 , 140 , 83 });
	attackM.PushBack({ 1260 , 0 , 140 , 83 });
	attackM.PushBack({ 1400 , 0 , 140 , 83 });
	attackM.loop = false;
	attackM.speed = 0.008f;

	protectM.PushBack({ 0 , 581 , 140 , 83 });
	protectM.PushBack({ 140 , 581 , 140 , 83 });
	protectM.PushBack({ 280 , 581 , 140 , 83 });
	protectM.PushBack({ 420 , 581 , 140 , 83 });
	protectM.loop = true;
	protectM.speed = 0.006f;

	hitM.PushBack({ 0 , 249 , 140 , 83 });
	hitM.PushBack({ 140 , 249 , 140 , 83 });
	hitM.PushBack({ 280 , 249 , 140 , 83 });
	hitM.PushBack({ 420 , 249 , 140 , 83 });
	hitM.loop = true;
	hitM.speed = 0.006f;

	dieM.PushBack({ 0, 166, 140, 83 });
	dieM.PushBack({ 140 , 166 , 140 , 83 });
	dieM.PushBack({ 280 , 166 , 140 , 83 });
	dieM.PushBack({ 420 , 166 , 140 , 83 });
	dieM.PushBack({ 560 , 166 , 140 , 83 });
	dieM.PushBack({ 700 , 166 , 140 , 83 });
	dieM.PushBack({ 840 , 166 , 140 , 83 });
	dieM.PushBack({ 980 , 166 , 140 , 83 });
	dieM.PushBack({ 1120 , 166 , 140 , 83 });
	dieM.loop = false;
	dieM.speed = 0.006f;

	//----------------------------------------------------------------------------------Battle Female------------------------------------

	idleBattleF.PushBack({ 1 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 2 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 3 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 4 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 5 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 6 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 7 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 8 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 9 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 10 * 180 , 0 , 180 , 180 });
	idleBattleF.PushBack({ 11 * 180 , 0 ,  180 , 180 });
	idleBattleF.loop = true;
	idleBattleF.speed = 0.015f;

	attackF.PushBack({ 0 , 0 , 180 , 114 });
	attackF.PushBack({ 180 , 0 , 180 , 114 });
	attackF.PushBack({ 360 , 0 , 180 , 114 });
	attackF.PushBack({ 540 , 0 , 180 , 114 });
	attackF.PushBack({ 720 , 0 , 180 , 114 });
	attackF.PushBack({ 900 , 0 , 180 , 114 });
	attackF.PushBack({ 1080 , 0 , 180 , 114 });
	attackF.PushBack({ 0 , 456 , 180 , 114 });
	attackF.PushBack({ 180 , 456 , 180 , 114 });
	attackF.PushBack({ 360 , 456 , 180 , 114 });
	attackF.PushBack({ 540 , 456 , 180 , 114 });
	attackF.PushBack({ 720 , 456 , 180 , 114 });
	attackF.PushBack({ 900 , 456 , 180 , 114 });
	attackF.PushBack({ 1080 , 456 , 180 , 114 });
	attackF.PushBack({ 1260 , 456 , 180 , 114 });
	attackF.PushBack({ 1440 , 456 , 180 , 114 });
	attackF.PushBack({ 1620 , 456 , 180 , 114 });
	attackF.PushBack({ 1800 , 456 ,  180 , 114 });
	attackF.loop = false;
	attackF.speed = 0.008f;

	attackF2.PushBack({ 0 , 114 , 180 , 114 });
	attackF2.PushBack({ 180 , 114 , 180 , 114 });
	attackF2.PushBack({ 360 , 114 , 180 , 114 });
	attackF2.PushBack({ 540 , 114 , 180 , 114 });
	attackF2.PushBack({ 720 , 114 , 180 , 114 });
	attackF2.PushBack({ 900 , 114 , 180 , 114 });
	attackF2.PushBack({ 1080 , 114 , 180 , 114 });
	attackF2.PushBack({ 0 , 456 , 180 , 114 });
	attackF2.PushBack({ 180 , 456 , 180 , 114 });
	attackF2.PushBack({ 360 , 456 , 180 , 114 });
	attackF2.PushBack({ 540 , 456 , 180 , 114 });
	attackF2.PushBack({ 720 , 456 , 180 , 114 });
	attackF2.PushBack({ 900 , 456 , 180 , 114 });
	attackF2.PushBack({ 1080 , 456 , 180 , 114 });
	attackF2.PushBack({ 1260 , 456 , 180 , 114 });
	attackF2.PushBack({ 1440 , 456 , 180 , 114 });
	attackF2.PushBack({ 1620 , 456 , 180 , 114 });
	attackF2.PushBack({ 1800 , 456 ,  180 , 114 });
	attackF2.loop = false;
	attackF2.speed = 0.009f;

	attackChainF.PushBack({ 0 , 0 , 180 , 114 });
	attackChainF.PushBack({ 180 , 0 , 180 , 114 });
	attackChainF.PushBack({ 360 , 0 , 180 , 114 });
	attackChainF.PushBack({ 540 , 0 , 180 , 114 });
	attackChainF.PushBack({ 720 , 0 , 180 , 114 });
	attackChainF.PushBack({ 900 , 0 , 180 , 114 });
	attackChainF.PushBack({ 1080 , 0 , 180 , 114 });
	attackChainF.PushBack({ 0 , 114 , 180 , 114 });
	attackChainF.PushBack({ 180 , 114 , 180 , 114 });
	attackChainF.PushBack({ 360 , 114 , 180 , 114 });
	attackChainF.PushBack({ 540 , 114 , 180 , 114 });
	attackChainF.PushBack({ 720 , 114 , 180 , 114 });
	attackChainF.PushBack({ 900 , 114 , 180 , 114 });
	attackChainF.PushBack({ 1080 , 114 , 180 , 114 });
	attackChainF.PushBack({ 0 , 456 , 180 , 114 });
	attackChainF.PushBack({ 180 , 456 , 180 , 114 });
	attackChainF.PushBack({ 360 , 456 , 180 , 114 });
	attackChainF.PushBack({ 540 , 456 , 180 , 114 });
	attackChainF.PushBack({ 720 , 456 , 180 , 114 });
	attackChainF.PushBack({ 900 , 456 , 180 , 114 });
	attackChainF.PushBack({ 1080 , 456 , 180 , 114 });
	attackChainF.PushBack({ 1260 , 456 , 180 , 114 });
	attackChainF.PushBack({ 1440 , 456 , 180 , 114 });
	attackChainF.PushBack({ 1620 , 456 , 180 , 114 });
	attackChainF.PushBack({ 1800 , 456 ,  180 , 114 });
	attackChainF.loop = false;
	attackChainF.speed = 0.009f;

	protectF.PushBack({ 540 , 228 , 180 , 114 });
	protectF.loop = true;

	hitF.PushBack({ 0 , 798 , 180 , 114 });
	hitF.PushBack({ 180 , 798 , 180 , 114 });
	hitF.PushBack({ 360 , 798 , 180 , 114 });
	hitF.PushBack({ 540 , 798 , 180 , 114 });
	hitF.loop = true;
	hitF.speed = 0.006f;

	dieF.PushBack({ 0 , 228 , 180 , 114 });
	dieF.PushBack({ 180 , 228 , 180 , 114 });
	dieF.PushBack({ 360 , 228 , 180 , 114 });
	dieF.PushBack({ 540 , 228 , 180 , 114 });
	dieF.PushBack({ 720 , 228 , 180 , 114 });
	dieF.PushBack({ 900 , 228 , 180 , 114 });
	dieF.PushBack({ 1080 , 228 , 180 , 114 });
	dieF.PushBack({ 1260 , 228 , 180 , 114 });
	dieF.PushBack({ 1440 , 228 , 180 , 114 });
	dieF.PushBack({ 1620 , 228 , 180 , 114 });
	dieF.PushBack({ 1800 , 228 ,  180 , 114 });
	dieF.loop = false;
	dieF.speed = 0.006f;

	currentAnimation = &idleAnimR; //player start with idle anim

	name = "Rhen";
	configName = "player";

	margin = 10;
	colDownDistance = 47;
	colRightDistance = 9;

	baseCollider = app->collisions->AddCollider({ position.x + colRightDistance, position.y+ colDownDistance , 30,  24 }, Collider::Type::PLAYER, this);

	mapPosition = { 0,0 };
	battlePosition = { 150, 150 };

	isAlive = true;

	interactionButtonJustSpace.PushBack({ 83, 41, 36, 16 });
	interactionButtonJustSpace.loop = false;
}

// Destructor
Player::~Player()
{}

bool Player::Awake(pugi::xml_node& config)
{
	LOG("Init Image library, ta guapa la libreria de imagenes llamada player");
	bool ret = true;
	LOG("Num in config: %d",config.child("exampleNumber").attribute("num").as_int());

	MaleChar = config.child("male").attribute("path").as_string();
	FemaleChar = config.child("female").attribute("path").as_string();
	electionfxChar = config.child("election").attribute("path").as_string();
	WalkfxChar = config.child("walkFx").attribute("path").as_string();
	interactionButtonChar = config.child("interactionButton").attribute("path").as_string();

	return ret;
}

bool Player::Start()
{
	LOG("start Player");
	bool ret = true;

	erectionFx = app->audio->LoadFx(electionfxChar);
	walkFx = app->audio->LoadFx(WalkfxChar);

	PlayerMTex = app->tex->Load(MaleChar);
	PlayerFTex = app->tex->Load(FemaleChar);
	BattleMTex = app->tex->Load("Assets/sprites/main_ch/mainChM/battle/mBattleSprite.png");
	/*BattleFTex = app->tex->Load("Assets/sprites/main_ch/mainChF/battle/fBattlesprite.png");*/
	BattleFTex = app->tex->Load("Assets/sprites/MainCh/MainChM/Combat/Idle.png");
	interactionButton = app->tex->Load(interactionButtonChar);

	male_character_face_gui = app->tex->Load("Assets/sprites/faces/mrotamascgui.png");
	female_character_face_gui = app->tex->Load("Assets/sprites/faces/ProtaFemgui.png");

	//player start with idle anim
	currentAnimation = &idleAnimDown;
	PlayerErection = 1;

	canMove = true;

	/*stats = new Stats(1, 20, 8 , 5, 5, 20);*/
	stats = new Stats(1, 20, 0, 0, 5, 20);

	wait, _wait = false;

	timeWalkingVer = 0;
	timeWalkingHor = 0;

	return ret;
}

bool Player::PreUpdate()
{
	// DEBUG PLAYER POSITION
	if (app->input->GetKey(SDL_SCANCODE_P) == KEY_REPEAT) {
		LOG("position x %d y %d", position.x, position.y);
	}
	
	
	//if (app->scene->godmode) stats->SetStats();	
	
	// Show GUI if player isn't moving
	if (toggleGui == true && app->stages->actualStage != StageIndex::INTRODUCTION) {
		if (lastFramePos == position) {
			showGuiCont++;
			if (showGuiCont >= 120) {
				app->scene->guiactivate = true;
			}
		}
		else {
			showGuiCont = 0;
		}

		lastFramePos = position;
	}

	if (PlayerErection == true) {
		spriteFace = male_character_face_gui;
	}
	else {
		spriteFace = female_character_face_gui;
	}

	return true;
}

bool Player::Update(float dt) {
	bool ret = true;
	GamePad& pad = app->input->pads[0];
	
	if (!pad.r3 && !pad.l3)_wait = true;
	if (app->scene->pause == false && canMove == true && app->dialogs->dialoging == false) {

		if ((app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN) || pad.l3 && _wait && !PlayerErection && app->stages->actualStage==StageIndex::INTRODUCTION) {
			if (PlayerErection != true) {
				PlayerErection = true;
				name = "Rhen";
				app->audio->PlayFx(erectionFx);
			}	
			app->stages->elect = true;
			_wait = false;
		}
		if ((app->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN) || pad.l3 && _wait && PlayerErection && app->stages->actualStage == StageIndex::INTRODUCTION) {
			if (PlayerErection != false) {
				PlayerErection = false;
				name = "Briar";
				app->audio->PlayFx(erectionFx);
			}
			app->stages->elect = true;
			_wait = false;
		}

		if (app->fade->fading == false && app->stages->actualStage != StageIndex::INTRODUCTION) {
			MovementPlayer(dt);
		}
	}

	baseCollider->rect.x = position.x + colRightDistance;
	baseCollider->rect.y = position.y + colDownDistance;

	return ret;
}

bool Player::PostUpdate()
{
	bool ret = true;

	if (printInteractionButt == true) {
		app->render->DrawTexture(interactionButton, position.x + 5, position.y, &interactionButtonJustSpace.GetCurrentFrame());
	}
	printInteractionButt = false;

	return true;
}

bool Player::CleanUp() {

	//Collisions
	app->collisions->RemoveCollider(baseCollider);
	app->collisions->RemoveCollider(battleCollider);

	baseCollider = nullptr;
	delete baseCollider;

	//Animations
	currentAnimation = nullptr;
	delete currentAnimation;

	//Textures
	app->tex->UnLoad(spriteTex);
	app->tex->UnLoad(PlayerFTex);
	app->tex->UnLoad(PlayerMTex);

	return true;
}

void Player::MovementPlayer(float dt) {
	speed = 0.2 * dt;

	GamePad& pad = app->input->pads[0];

	walkFxCooldown -= dt;
	int cooldown = 450;

	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT || pad.left_y < -0.5f || pad.up) {
		

		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT || pad.left_x < -0.5f || pad.left) {
			if (timeWalkingHor < timeWalkingVer) {
				position.x -= speed;
				timeWalkingHor++;
				timeWalkingVer++;
				if (currentAnimation != &walkAnimL) {
					currentAnimation = &walkAnimL;
				}

				if (walkFxCooldown < 0) {
					app->audio->PlayFx(walkFx);
					walkFxCooldown = cooldown;
				}
			}
		}
		else if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT || pad.left_x > 0.5f || pad.right) {
			if (timeWalkingHor < timeWalkingVer) {
				position.x += speed;
				timeWalkingHor++;
				timeWalkingVer++;
				if (currentAnimation != &walkAnimR) {
					currentAnimation = &walkAnimR;
				}

				if (walkFxCooldown < 0) {
					app->audio->PlayFx(walkFx);
					walkFxCooldown = cooldown;
				}
			}
		}
		else {
			position.y -= speed;
			timeWalkingVer++;
			timeWalkingHor = 0;
			if (currentAnimation != &walkAnimUp) {
				currentAnimation = &walkAnimUp;
			}

			if (walkFxCooldown < 0) {
				app->audio->PlayFx(walkFx);
				walkFxCooldown = cooldown;
			}
		}
	}
	else if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT || pad.left_y > 0.5f || pad.down) {
		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT || pad.left_x < -0.5f || pad.left) {
			if (timeWalkingHor < timeWalkingVer) {
				position.x -= speed;
				timeWalkingHor++;
				timeWalkingVer++;
				if (currentAnimation != &walkAnimL) {
					currentAnimation = &walkAnimL;
				}

				if (walkFxCooldown < 0) {
					app->audio->PlayFx(walkFx);
					walkFxCooldown = cooldown;
				}
			}
		}
		else if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT || pad.left_x > 0.5f || pad.right) {
			if (timeWalkingHor < timeWalkingVer) {
				position.x += speed;
				timeWalkingHor++;
				timeWalkingVer++;
				if (currentAnimation != &walkAnimR) {
					currentAnimation = &walkAnimR;
				}

				if (walkFxCooldown < 0) {
					app->audio->PlayFx(walkFx);
					walkFxCooldown = cooldown;
				}
			}
		}
		else {
			position.y += speed;
			timeWalkingVer++;
			if (currentAnimation != &walkAnimDown) {
				currentAnimation = &walkAnimDown;
			}

			if (walkFxCooldown < 0) {
				app->audio->PlayFx(walkFx);
				walkFxCooldown = cooldown;
			}
		}
	}
	else if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT || pad.left_x < -0.5f || pad.left) {
		position.x -= speed;
		timeWalkingHor++;
		if (currentAnimation != &walkAnimL) {
			currentAnimation = &walkAnimL;
		}

		if (walkFxCooldown < 0) {
			app->audio->PlayFx(walkFx);
			walkFxCooldown = cooldown;
		}
	}
	else if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT || pad.left_x > 0.5f || pad.right) {
		position.x += speed;
		timeWalkingHor++;
		if (currentAnimation != &walkAnimR) {
			currentAnimation = &walkAnimR;
		}

		if (walkFxCooldown < 0) {
			app->audio->PlayFx(walkFx);
			walkFxCooldown = cooldown;
		}
	}
	else {
		if (currentAnimation == &walkAnimR) {
			currentAnimation = &idleAnimR;
		}
		else if(currentAnimation == &walkAnimL) {
			currentAnimation = &idleAnimL;
		}
		else if (currentAnimation == &walkAnimUp) {
			currentAnimation = &idleAnimUp;
		}
		else if (currentAnimation == &walkAnimDown) {
			currentAnimation = &idleAnimDown;
		}
		timeWalkingHor = 0;
		timeWalkingVer = 0;
	}

	currentAnimation->Update(dt);
}

void Player::OnCollision(Collider* col1, Collider* col2) {

	if (col1 == baseCollider && col2->type == Collider::WALL && !app->scene->godmode) {

		//Cant move Left
		if (col2->rect.x + col2->rect.w > col1->rect.x					&&
			col2->rect.x + col2->rect.w < col1->rect.x + col1->rect.w	&&
			col1->rect.y < col2->rect.y + col2->rect.h - margin			&&
			col1->rect.y + col1->rect.h > col2->rect.y + margin) {
		
			this->position.x = col2->rect.x + col2->rect.w - colRightDistance;
		}

		//Cant move Right
		if (col2->rect.x > col1->rect.x									&&
			col2->rect.x < col1->rect.x + col1->rect.w					&&
			col1->rect.y < col2->rect.y + col2->rect.h - margin			&&
			col1->rect.y + col1->rect.h > col2->rect.y + margin) {
			
			this->position.x = col2->rect.x - col1->rect.w - colRightDistance;
		}

		//Cant move Up
		if (col2->rect.y + col2->rect.h > col1->rect.y					&&
			col2->rect.y + col2->rect.h < col1->rect.y + col1->rect.h	&&
			col1->rect.x + col1->rect.w > col2->rect.x + margin			&&
			col1->rect.x < col2->rect.x + col2->rect.w - margin) {
			
			this->position.y = col2->rect.y + col2->rect.h - colDownDistance;
		}
		//Cant move Down
		if (col2->rect.y < col1->rect.y + col1->rect.h					&&
			col2->rect.y > col1->rect.y									&&
			col1->rect.x + col1->rect.w > col2->rect.x + margin			&&
			col1->rect.x < col2->rect.x + col2->rect.w - margin) {
			
			this->position.y = col2->rect.y - col1->rect.h - colDownDistance;
		}
	}

	if (col1 == baseCollider && col2->type == Collider::INSTANT) {

		//Collision with enemy

		ListItem<NormalEnemy*>* normalEnemyInList;

		for (normalEnemyInList = app->scene->normalEnemyList.start; normalEnemyInList != NULL; normalEnemyInList = normalEnemyInList->next)
		{
			if (normalEnemyInList->data->activeOnStage == app->stages->actualStage) {
				if (normalEnemyInList->data->GetCollider() != nullptr) {
					if (normalEnemyInList->data->GetCollider() == col2 && app->battle->isEnabled() == false) {

						app->battle->entitiesInBattle[0] = this;
						app->battle->entitiesInBattle[4] = normalEnemyInList->data;

						if (app->stages->partyListPtr->At(1) != nullptr) {
							app->battle->entitiesInBattle[1] = app->stages->partyListPtr->At(1)->data;

							srand(time(NULL));
							int enemySpawnChance = (rand() % 100);

							if (enemySpawnChance >= 2) {
								srand(time(NULL));
								int enemyType = (rand() % 3);
								if (enemyType == 0) {
									NormalEnemy* bat = (NormalEnemy*)app->entities->CreateEntity(NormalEnemyType::BAT, 0, 0);
									bat->onlyInBattle = true;
									app->scene->normalEnemyList.add(bat);
									app->battle->entitiesInBattle[5] = bat;
								}
								else if (enemyType == 1) {

									NormalEnemy* flyingEye = (NormalEnemy*)app->entities->CreateEntity(NormalEnemyType::FLYING_EYE, 0, 0);
									flyingEye->onlyInBattle = true;
									app->scene->normalEnemyList.add(flyingEye);
									app->battle->entitiesInBattle[5] = flyingEye;
								}
								else if (enemyType == 2) {
									NormalEnemy* skeleton = (NormalEnemy*)app->entities->CreateEntity(NormalEnemyType::SKELETON, 0, 0);
									skeleton->onlyInBattle = true;
									app->scene->normalEnemyList.add(skeleton);
									app->battle->entitiesInBattle[5] = skeleton;

								}


							}
						}







						//app->battle->normalEnemyInBattle = normalEnemyInList->data;
						//app->battle->CurrentEnemyType = EnemyInBattleType::NORMAL;
						app->battle->Enable();
					}
				}
			}
			
			
		}

		//Collision with entrance
		for (int i = 0; i < MAX_ENTRIES; i++) {
			if (app->map->mapEntries[i] != nullptr) {
				if (app->map->mapEntries[i]->col == col2) {

					switch (app->map->mapEntries[i]->id) 
					{
						case 0:

							switch (app->stages->actualStage)
							{
							case StageIndex::NONE:

								break;
							case StageIndex::TOWN:

								LOG("Loading Shop map");
								townPos = { position.x, position.y + townPosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::SHOP);

								break;
							case StageIndex::DOJO:

								LOG("Loading town map");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::SHOP:

								LOG("Loading Shop sub level map");
								app->fade->DoFadeToBlack(StageIndex::SHOPSUB);

								break;
							case StageIndex::SHOPSUB:

								LOG("Loading Shop map");
								shopPosOn = true;
								app->fade->DoFadeToBlack(StageIndex::SHOP);

								break;
							case StageIndex::TAVERN:

								LOG("Loading town map");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::TOWER0:

								LOG("Loading floor 1 map");
								tower0Pos = { position.x, position.y + tower0PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER1);

								break;
							case StageIndex::TOWER1:

								LOG("Loading tower map");
								tower1Pos = { position.x, position.y - tower1PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER0);

								break;
							case StageIndex::TOWER2:

								LOG("Loading floor 3 map");
								tower2Pos = { position.x, position.y + tower2PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER3);

								break;
							case StageIndex::TOWER3:

								LOG("Loading floor 2 map");
								tower3Pos = { position.x, position.y - tower3PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER2);

								break;
							}

							break;
						case 1:

							switch (app->stages->actualStage)
							{
							case StageIndex::NONE:

								break;
							case StageIndex::TOWN:

								LOG("Loading Tower map");
								townPos = { position.x, position.y + townPosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER0);

								break;
							case StageIndex::DOJO:

								LOG("Returning to town");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::SHOP:

								LOG("Loading town map");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::TAVERN:

								LOG("Loading town map");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::TOWER0:

								LOG("Loading town map");
								tower0Pos = { position.x, position.y - tower0PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::TOWER1:

								LOG("Loading tower map");
								tower1Pos = { position.x, position.y - tower1PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER0);

								break;
							case StageIndex::TOWER2:

								LOG("Loading floor 1 map");
								tower2Pos = { position.x, position.y - tower2PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER1);

								break;
							case StageIndex::TOWER3:

								LOG("Loading floor 2 map");
								tower3Pos = { position.x, position.y - tower3PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER2);

								break;
							}
							break;
						case 2:

							switch (app->stages->actualStage)
							{
							case StageIndex::NONE:

								break;
							case StageIndex::TOWN:

								LOG("Loading Tower map");
								townPos = { position.x, position.y + townPosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER0);

								break;
							case StageIndex::DOJO:

								LOG("Returning to town");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::SHOP:

								LOG("Loading town map");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::TOWER0:

								LOG("Loading floor 1 map");
								tower0Pos = { position.x, position.y + tower0PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER1);

								break;
							case StageIndex::TOWER1:

								LOG("Loading tower map");
								tower1Pos = { position.x, position.y - tower1PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER0);

								break;
							case StageIndex::TOWER2:

								LOG("Loading floor 2 map");
								tower2Pos = { position.x, position.y - tower2PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER1);

								break;
							}

							break;
						case 3:
							switch (app->stages->actualStage)
							{
							case StageIndex::NONE:

								break;
							case StageIndex::TOWN:

								LOG("Loading Tavern map");
								townPos = { position.x, position.y + townPosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TAVERN);

								break;
							case StageIndex::DOJO:

								LOG("Returning to town");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::SHOP:

								LOG("Loading town map");
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::TOWER0:

								LOG("Loading town map");
								tower0Pos = { position.x, position.y - tower0PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWN);

								break;
							case StageIndex::TOWER1:

								LOG("Loading floor 2 map");
								tower1Pos = { position.x, position.y + tower1PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER2);

								break;
							case StageIndex::TOWER2:

								LOG("Loading floor 1 map");
								tower2Pos = { position.x, position.y - tower2PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER1);

								break;
							}
							
							break;
						case 4:
							switch (app->stages->actualStage)
							{
							case StageIndex::TOWN:

								LOG("Loading Tavern map");
								townPos = { position.x, position.y + townPosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TAVERN);

								break;
							case StageIndex::TOWER1:

								LOG("Loading floor 2 map");
								tower1Pos = { position.x, position.y + tower1PosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::TOWER2);
								break;
							}

							break;
						default:
							if (app->stages->actualStage == StageIndex::DOJO) {
								LOG("Returning to town");
								app->fade->DoFadeToBlack(StageIndex::TOWN);
							}
							if (app->stages->actualStage == StageIndex::TOWN) {
								LOG("going to dojo");
								townPos = { position.x, position.y + townPosYAxisfix };
								app->fade->DoFadeToBlack(StageIndex::DOJO);
							}
							break;
					}
				}
			}
		}
	}

	if (col1 == baseCollider && col2->type == Collider::INTERACT) {

		// NPC COLLISIONS (Press Space)

		if (app->dialogs->dialoging == false) {
	
			for (ListItem<Entity*>* entityInList = app->entities->entityList.start; entityInList != NULL; entityInList = entityInList->next)
			{
				if (entityInList->data->activeOnStage == app->stages->actualStage) {
					
					if (entityInList->data->GetCollider() != nullptr) {
						if (entityInList->data->GetCollider() == col2) {
							switch (entityInList->data->npcID)
							{
							case 1:
								Interact(NPCType::COCK, cockDialog);
								break;
							case 2:
								Interact(NPCType::MERCHANT, merchantDialog);
								break;
							case 3:
								Interact(NPCType::BARKEEPER, barkeeperDialog);
								break;
							case 4:
								Interact(NPCType::TRAINER, trainerDialog);
								break;
							case 5:										
								Interact(NPCType::EMILIO, emilioDialog);
								break;
							case 7:
								Interact(NPCType::FUENTE, fuenteDialog);
								break;
							case 8:
								Interact(NPCType::CARTELSUDTOWN, cartelSudTownDialog);
							default:
								break;
							}
						}
					}
				}
			}
		}
	}
}

void Player::Interact(NPCType npc, const char* dialog[DIALOG_LENGHT]) {

	GamePad& pad = app->input->pads[0];

	if (!pad.a) wait = true;

	if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN || pad.a && wait == true) {
		app->dialogs->CreateDialog(npc, dialog);
		if (npc == NPCType::FUENTE) {
			for (ListItem<Character*>* characterList = app->scene->partyList.start; characterList != NULL; characterList = characterList->next) {
				characterList->data->stats->health = characterList->data->stats->maxHealth;
				characterList->data->isAlive = true;
				dieM.Reset();
				dieF.Reset();
				characterList->data->deathAnim.Reset();
			}
			
		}
		if (npc == NPCType::MERCHANT) {
			app->shop->Enable();
		}
		wait = false;
	}
	printInteractionButt = true;
}