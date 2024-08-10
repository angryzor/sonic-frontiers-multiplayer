using namespace app_cmn::camera;
using namespace app::camera;

thread_local char gPlayerId{ -1 };
static app::level::PlayerInformation* playerInfos[7]{};

template<typename R, typename... A>
R WithPlayerId(char playerId, R(*f)(A...), A... a) {
	char oldPlayerId = gPlayerId;
	gPlayerId = playerId;

	R res = f(a...);

	gPlayerId = oldPlayerId;

	return res;
}

template<typename R, typename... A>
R WithPlayerIdByCameraFrame(CameraFrame* cameraFrame, R(*f)(A...), A... a) {
	char oldPlayerId = gPlayerId;
	gPlayerId = cameraFrame->id / 2;

	R res = f(a...);

	gPlayerId = oldPlayerId;

	return res;
}

template<typename... A>
void WithPlayerIdByCameraFrame(CameraFrame* cameraFrame, void(*f)(A...), A... a) {
	char oldPlayerId = gPlayerId;
	gPlayerId = cameraFrame->id / 2;

	f(a...);

	gPlayerId = oldPlayerId;
}

template<typename R, typename... A>
R WithPlayerIdByPlayerObject(app::player::Player* playerObj, R(*f)(A...), A... a) {
	char oldPlayerId = gPlayerId;
	gPlayerId = playerObj->setupInfo.playerId;

	R res = f(a...);

	gPlayerId = oldPlayerId;

	return res;
}

template<typename... A>
void WithPlayerIdByPlayerObject(app::player::Player* playerObj, void(*f)(A...), A... a) {
	char oldPlayerId = gPlayerId;
	gPlayerId = playerObj->setupInfo.playerId;

	f(a...);

	gPlayerId = oldPlayerId;
}

template<typename R, typename... A>
R WithPlayerIdByPlayerObject(const hh::fnd::Handle<hh::fnd::Messenger>& playerObj, R(*f)(A...), A... a) {
	return WithPlayerIdByPlayerObject(static_cast<app::player::Player*>(playerObj.Get(hh::fnd::MessageManager::handleManager)), f, a...);
}

template<typename... A>
void WithPlayerIdByPlayerObject(const hh::fnd::Handle<hh::fnd::Messenger>& playerObj, void(*f)(A...), A... a) {
	WithPlayerIdByPlayerObject(static_cast<app::player::Player*>(playerObj.Get(hh::fnd::MessageManager::handleManager)), f, a...);
}

HOOK(bool, __fastcall, sub_1400A0A60, 0x1400A0A60, CameraController* controller) {
	return WithPlayerIdByCameraFrame(controller->cameraFrame, originalsub_1400A0A60, controller);
}

HOOK(bool, __fastcall, sub_1400A0FA0, 0x1400A0FA0, CameraParameter* a1, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A0FA0, a1, cameraFrame);
}

HOOK(bool, __fastcall, sub_1400A1100, 0x1400A1100, csl::math::Vector3* a1, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1100, a1, cameraFrame);
}

HOOK(bool, __fastcall, sub_1400A1200, 0x1400A1200, csl::math::Vector3* a1, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1200, a1, cameraFrame);
}

HOOK(bool, __fastcall, sub_1400A1260, 0x1400A1260, csl::math::Vector3* a1, csl::math::Vector3* a2, csl::math::Vector3* a3, app_cmn::camera::CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1260, a1, a2, a3, cameraFrame);
}

HOOK(app::level::PlayerInformation*, __fastcall, sub_1400A1300, 0x1400A1300, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1300, cameraFrame);
}

HOOK(float, __fastcall, sub_1400A13B0, 0x1400A13B0, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A13B0, cameraFrame);
}

HOOK(csl::math::Vector3*, __fastcall, sub_1400A1400, 0x1400A1400, csl::math::Vector3* retstr, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1400, retstr, cameraFrame);
}

HOOK(bool, __fastcall, sub_1400A1470, 0x1400A1470, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1470, cameraFrame);
}

HOOK(void, __fastcall, sub_1400A14C0, 0x1400A14C0, csl::math::Vector3* a1, csl::math::Vector3* a2, float a3, CameraFrame* cameraFrame) {
	WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A14C0, a1, a2, a3, cameraFrame);
}

HOOK(void, __fastcall, sub_1400A1580, 0x1400A1580, csl::math::Vector3* a1, csl::math::Vector3* a2, CameraFrame* cameraFrame) {
	WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1580, a1, a2, cameraFrame);
}

HOOK(void, __fastcall, sub_1400A1620, 0x1400A1620, csl::math::Vector3* a1, float a2, CameraFrame* cameraFrame) {
	WithPlayerIdByCameraFrame(cameraFrame, originalsub_1400A1620, a1, a2, cameraFrame);
}

HOOK(bool, __fastcall, sub_1400AD250, 0x1400AD250, CameraController* controller) {
	return WithPlayerIdByCameraFrame(controller->cameraFrame, originalsub_1400AD250, controller);
}

HOOK(void, __fastcall, sub_1400AD610, 0x1400AD610, CameraController* controller, float a2) {
	WithPlayerIdByCameraFrame(controller->cameraFrame, originalsub_1400AD610, controller, a2);
}

HOOK(void, __fastcall, sub_1400B2850, 0x1400B2850, CameraController* controller, float a2) {
	WithPlayerIdByCameraFrame(controller->cameraFrame, originalsub_1400B2850, controller, a2);
}

HOOK(void, __fastcall, sub_1400B2F40, 0x1400B2F40, CameraController* controller, float a2) {
	WithPlayerIdByCameraFrame(controller->cameraFrame, originalsub_1400B2F40, controller, a2);
}

HOOK(void, __fastcall, sub_1400B54C0, 0x1400B54C0, CameraController* controller) {
	WithPlayerIdByCameraFrame(controller->cameraFrame, originalsub_1400B54C0, controller);
}

HOOK(void, __fastcall, sub_1400B5580, 0x1400B5580, CameraController* controller, bool a2) {
	WithPlayerIdByCameraFrame(controller->cameraFrame, originalsub_1400B5580, controller, a2);
}

HOOK(void, __fastcall, sub_14099DD70, 0x14099DD70, app::player::PlayerStatePlugin* plugin, void* a2, float a3) {
	WithPlayerIdByPlayerObject(plugin->context->playerObject, originalsub_14099DD70, plugin, a2, a3);
}

HOOK(bool, __fastcall, sub_1462027E0, 0x1462027E0, csl::math::Vector3* a1, csl::math::Vector3* a2, csl::math::Vector3* a3, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_1462027E0, a1, a2, a3, cameraFrame);
}

HOOK(app::level::PlayerInformation::Unk3*, __fastcall, sub_146210630, 0x146210630, app::level::PlayerInformation::Unk3* retstr, CameraFrame* cameraFrame) {
	return WithPlayerIdByCameraFrame(cameraFrame, originalsub_146210630, retstr, cameraFrame);
}

HOOK(void, __fastcall, sub_14088AC20, 0x14088AC20, app::player::Sonic* self) {
	WithPlayerIdByPlayerObject(self, originalsub_14088AC20, self);
}

HOOK(void, __fastcall, sub_140886900, 0x140886900, app::player::Amy* self) {
	WithPlayerIdByPlayerObject(self, originalsub_140886900, self);
}

HOOK(void, __fastcall, sub_140888930, 0x140888930, app::player::Knuckles* self) {
	WithPlayerIdByPlayerObject(self, originalsub_140888930, self);
}

HOOK(void, __fastcall, sub_14088D0F0, 0x14088D0F0, app::player::Tails* self) {
	WithPlayerIdByPlayerObject(self, originalsub_14088D0F0, self);
}

HOOK(void, __fastcall, InputManager_Setup, 0x150547840, hh::game::InputManager* self, hh::game::InputManager::SetupInfo& setupInfo)
{
	setupInfo.internalPlayerInputCount = 2;
	return originalInputManager_Setup(self, setupInfo);
}

app::level::PlayerInformation* GetRealPlayerInformation(app::level::LevelInfo* levelInfo, char playerId);

HOOK(app::level::PlayerInformation*, __fastcall, LevelInfo_GetPlayerInformation, 0x140260290, app::level::LevelInfo* self, char playerId)
{
	//assert(gPlayerId != -1);
	return GetRealPlayerInformation(self, playerId == 0 && gPlayerId >= 0 ? gPlayerId : playerId);
}

app::level::PlayerInformation* GetRealPlayerInformation(app::level::LevelInfo* levelInfo, char playerId) {
	if (playerId == 0) return originalLevelInfo_GetPlayerInformation(levelInfo, playerId);
	else return playerInfos[playerId - 1];
}

HOOK(hh::fnd::Handle<hh::fnd::Messenger>*, __fastcall, LevelInfo_GetPlayerObject, 0x14893A8E0, app::level::LevelInfo* self, hh::fnd::Handle<hh::fnd::Messenger>* retstr, char playerId) {
	auto* playerInfo = GetRealPlayerInformation(self, playerId);
	*retstr = playerInfo->playerObject.isSet ? playerInfo->playerObject.value : 0;
	return retstr;
}

HOOK(char, __fastcall, LevelInfo_GetPlayerIdFromPlayerObject, 0x14893D5E0, app::level::LevelInfo* self, hh::fnd::Handle<hh::fnd::Messenger>* playerObj) {
	for (char i = 0; i < 2; i++) {
		auto* playerInfo = GetRealPlayerInformation(self, i);
		if (playerInfo->playerObject.isSet && playerInfo->playerObject.value == *playerObj)
			return i;
	}
	return -1;
}

HOOK(hh::fnd::Handle<hh::fnd::Messenger>, __fastcall, CameraService_GetCameraFrame, 0x14648B710, hh::game::GameManager* gameMgr, int idx)
{
	//assert(gPlayerId != -1);
	return originalCameraService_GetCameraFrame(gameMgr, (gPlayerId == -1 ? 0 : gPlayerId) * 2 + idx);
}


app::level::StageData::AttributeFlags charaAttrFlags[] = {
	app::level::StageData::AttributeFlags::SONIC,
	app::level::StageData::AttributeFlags::TAILS,
	app::level::StageData::AttributeFlags::KNUCKLES,
	app::level::StageData::AttributeFlags::AMY,
};
class KeyEventHandler : public hh::fw::KeyEventHandler, public hh::game::GameManagerListener {
	virtual bool OnKeyDown(hh::fw::KeyEventArgs& keyEventArgs) override {
		if (keyEventArgs.scanCode == 0x27) {
			if (auto* gameManager = hh::game::GameManager::GetInstance())
			if (auto* fxParamMgr = gameManager->GetService<app::gfx::FxParamManager>()) {
				auto& stageConfig = fxParamMgr->sceneParameters[fxParamMgr->currentSceneParameters]->sceneData->stageConfig;
				if (auto* camSrv = gameManager->GetService<app::camera::CameraService>()) {
					camSrv->CreateDefaultCameraFrame(2, 1, 0, stageConfig.camera.zNear, stageConfig.camera.zFar, stageConfig.camera.fovy);
				}
			}
		}
		if (keyEventArgs.scanCode >= 0x22 && keyEventArgs.scanCode <= 0x25) {
			if (auto* gameManager = hh::game::GameManager::GetInstance()) {
			if (auto* levelInfo = gameManager->GetService<app::level::LevelInfo>())
			if (auto* fxParamMgr = gameManager->GetService<app::gfx::FxParamManager>())
				if (levelInfo->stageData->attributeFlags.test(charaAttrFlags[keyEventArgs.scanCode - 0x22])) {
					app::player::Player::Kill(gameManager, 1);
					app::player::Player::PlayerSetupInfo psi;
					psi.playerId = 1;
					psi.characterId = static_cast<app::player::CharacterIdU8>(keyEventArgs.scanCode - 0x22);
					psi.worldPos.m_Position = levelInfo->GetPlayerInformation(0)->position.value;
					psi.worldPos.m_Rotation = csl::math::Quaternion::Identity();
					psi.deadFallTime = fxParamMgr->sceneParameters[fxParamMgr->currentSceneParameters]->sceneData->stageConfig.common.deadFallTime;
					psi.deadline = fxParamMgr->sceneParameters[fxParamMgr->currentSceneParameters]->sceneData->stageConfig.common.deadline;
					psi.oceanSurface = fxParamMgr->sceneParameters[fxParamMgr->currentSceneParameters]->sceneData->stageConfig.common.oceanSurface;
					psi.unk6 = 1;
					psi.startType = app::player::Player::StartType::STAND;
					app::player::Player::Spawn(gameManager, psi);
				}
			}
		}
		//if (keyEventArgs.scanCode == 0x26) {
		//	auto* engine = static_cast<hh::gfx::RenderingEngineRangers*>(static_cast<hh::gfx::RenderManager*>(hh::gfx::RenderManager::GetInstance())->GetNeedleResourceDevice());
		//	engine->mainRenderUnit->pipelineInfo->globalParameterBuilder->unk4.reserve(2);
		//}
		return false;
	}
};

KeyEventHandler keyEventHandler;

HOOK(uint64_t, __fastcall, GameModeBootInit, 0x14734FB80, app::game::GameMode* self) {
	auto res = originalGameModeBootInit(self);

	auto* moduleAllocator = hh::fnd::MemoryRouter::GetModuleAllocator();
	playerInfos[0] = new (std::align_val_t(16), moduleAllocator) app::level::PlayerInformation{ moduleAllocator };


	hh::game::GameApplication::GetInstance()->AddKeyEventHandler(&keyEventHandler, 0);

	return res;
}

class PaneRenderUnit : public hh::needle::RenderUnit {
	unsigned int index;
public:
	PaneRenderUnit(const char* name, hh::needle::SupportFXAll* supportFX, uint8_t idx, unsigned int flags) : RenderUnit{ name, supportFX, static_cast<unsigned char>(0x80 + idx), flags }, index{ idx } {
		cameraId = 0;
		if (idx > 0)
			createSceneParamListeners = false;
	}

	virtual bool IsEnabled(const RenderInfo& renderInfo) override {
		return cameraId < renderInfo.renderParam.numViewports;
	}

	virtual void SetRenderDimensions(const RenderInfo& renderInfo) override {
		//auto& params = renderingPipelineExecContext->globalParameters;

		//float viewportInfo[4] = { cameraId == 0 ? 1.0f : 0.0f, cameraId == 1 ? 1.0f : 0.0f, cameraId == 2 ? 1.0f : 0.0f, cameraId == 3 ? 1.0f : 0.0f };
		//params->SetShaderParameterFloatByName("u_current_viewport_mask", viewportInfo, 1);

		//float screenInfo[4] = { 1280.0f, 720.0f, 0.0f, 0.001f };
		//params->SetShaderParameterFloatByName("u_screen_info", screenInfo, 1);
	}

	virtual void LoadRenderParams(const RenderInfo& renderInfo) override {
		RenderUnit::LoadRenderParams(renderInfo);
		pipelineInfo->renderParam.viewports[0] = pipelineInfo->renderParam.viewports[index];
	}
};

static hh::needle::intrusive_ptr<PaneRenderUnit> renderUnit2{};

HOOK(void, __fastcall, RenderingEngineRangers_SetupMainRenderUnit, 0x14F2C0DF0, hh::gfx::RenderingEngineRangers* self) {
	auto* staticAlloc = reinterpret_cast<csl::fnd::IAllocator*>(0x143CF5268);

	auto* renderingPipeline = new hh::needle::RenderingPipelineRangers{ staticAlloc, self->supportFX.modelInstanceRenderer };
	self->mainRenderingPipeline = renderingPipeline;

	auto* renderUnit1 = new PaneRenderUnit{ "MainScene", &self->supportFX, 0, 0x2000u };
	self->mainRenderUnit = renderUnit1;

	renderUnit1->LoadGlobalParams();
	renderUnit1->SetSceneName("MainScene");
	renderUnit1->SetPipeline(renderingPipeline);

	self->supportFX.AddRenderUnit(renderUnit1);

	renderUnit2 = new PaneRenderUnit{ "MainScene2", &self->supportFX, 1, 0x2000u };
	//self->mainRenderUnit = renderUnit2;

	renderUnit2->LoadGlobalParams();
	renderUnit2->SetSceneName("MainScene");
	renderUnit2->SetPipeline(renderingPipeline);

	self->supportFX.AddRenderUnit(renderUnit2);
	self->supportFX.mainSceneName = "MainScene";
}

HOOK(void, __fastcall, CachedShadowMapRenderJob_Render, 0x141036290, hh::needle::CachedShadowMapRenderJob* self, hh::needle::PipelineInfo* pipelineInfo) {
	if (self->viewportId < pipelineInfo->renderParam.numViewports && self->renderingPipeline)
	{
		auto renderTargetManager = pipelineInfo->supportFX->GetRenderManager()->renderTargetManager;
		unsigned long long jobMask;

		if (pipelineInfo->drawPassCount < 2) {
			jobMask = 0x1F;
		}
		else if (pipelineInfo->currentPass > 0 && pipelineInfo->sceneParamContainer->GetSceneParam<hh::needle::FxShadowMapParameter>()->isSet) {
			self->renderingPipeline->RenderMatchingJobs(pipelineInfo, (1ull << (pipelineInfo->currentPass - 1)) & 0xFull, true);
			return;
		}
		else {
			jobMask = 0x10ull;
		}

		if (self->unk119) {
			for (unsigned int i = 10; i <= 15; ++i)
				renderTargetManager->ClearDepthStencil({ i }, false);

			self->unk119 = 0;
		}

		self->renderingPipeline->RenderMatchingJobs(pipelineInfo, jobMask, true);
	}
}

//static hh::needle::SCullGroupSetting cullSettings[9 * 2]{};
//
//HOOK(void, __fastcall, WorldRenderingPipeline_Setup, 0x154C029B0, hh::needle::WorldRenderingPipeline* self, hh::needle::WorldRenderingPipeline::SetupInfo& setupInfo) {
//	setupInfo.renderParameters.cullingGroupSettings = cullSettings;
//	originalWorldRenderingPipeline_Setup(self, setupInfo);
//}

BOOL WINAPI DllMain(_In_ HINSTANCE hInstance, _In_ DWORD reason, _In_ LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:

		//WRITE_MEMORY(0x146A5F3CE, unsigned int, 0x1C000000);
		//// set rendermanager numMainViewports to 2
		WRITE_MEMORY(0x14F382288, uint8_t, 2);

		// load the same viewport settings for all viewports
		WRITE_MEMORY(0x14F3822C9, uint8_t, 0x48, 0x89, 0xCA, 0x90);

		WRITE_MEMORY(0x143CFB388, unsigned long, 0);

		//WRITE_NOP(0x140D1732C, 5);
		//WRITE_NOP(0x140D17337, 5);
		//WRITE_NOP(0x140D160B1, 5);
		////WRITE_NOP(0x140D1732C, 5);
		////WRITE_NOP(0x140D1732C, 5);

		//// set pipeline viewport count to 2
		//WRITE_MEMORY(0x14FA98FE1, unsigned int, 2);


		//WRITE_MEMORY(0x14FA990D1, unsigned int, 9);




		// always get global params for viewport 0, even when rendering other viewports
		//WRITE_MEMORY(0x14104E33F, uint8_t, 0x48, 0x8B, 0x00, 0x90);



		// don't cap number of viewports in async jobs by global param count
		//WRITE_MEMORY(0x141048EF4, uint8_t, 0x90, 0x90, 0x90);



		//memcpy(cullSettings, reinterpret_cast<void*>(0x1415F9D80), sizeof(hh::needle::SCullGroupSetting) * 9);
		//memcpy(cullSettings + 9, reinterpret_cast<void*>(0x1415F9D80), sizeof(hh::needle::SCullGroupSetting) * 9);

		//INSTALL_HOOK(WorldRenderingPipeline_Setup);

		INSTALL_HOOK(CachedShadowMapRenderJob_Render);
		INSTALL_HOOK(RenderingEngineRangers_SetupMainRenderUnit);
		INSTALL_HOOK(LevelInfo_GetPlayerObject);
		INSTALL_HOOK(LevelInfo_GetPlayerInformation);
		INSTALL_HOOK(LevelInfo_GetPlayerIdFromPlayerObject);
		INSTALL_HOOK(CameraService_GetCameraFrame);

		INSTALL_HOOK(sub_1400A0A60);
		INSTALL_HOOK(sub_1400A0FA0);
		INSTALL_HOOK(sub_1400A1100);
		INSTALL_HOOK(sub_1400A1200);
		INSTALL_HOOK(sub_1400A1260);
		INSTALL_HOOK(sub_1400A1300);
		INSTALL_HOOK(sub_1400A13B0);
		INSTALL_HOOK(sub_1400A1400);
		INSTALL_HOOK(sub_1400A1470);
		INSTALL_HOOK(sub_1400A14C0);
		INSTALL_HOOK(sub_1400A1580);
		INSTALL_HOOK(sub_1400A1620);
		INSTALL_HOOK(sub_1400AD250);
		INSTALL_HOOK(sub_1400AD610);
		INSTALL_HOOK(sub_1400B2850);
		INSTALL_HOOK(sub_1400B2F40);
		INSTALL_HOOK(sub_1400B54C0);
		INSTALL_HOOK(sub_1400B5580);
		INSTALL_HOOK(sub_14099DD70);
		INSTALL_HOOK(sub_1462027E0);
		INSTALL_HOOK(sub_146210630);
		INSTALL_HOOK(sub_14088AC20);
		INSTALL_HOOK(sub_140886900);
		INSTALL_HOOK(sub_140888930);
		INSTALL_HOOK(sub_14088D0F0);

		INSTALL_HOOK(InputManager_Setup);
		INSTALL_HOOK(GameModeBootInit);
		break;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
