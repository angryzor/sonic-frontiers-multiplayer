/*

#include "MultiplayerCameraService.h"

using namespace app::camera;
using namespace app_cmn::camera;

void* app::camera::MultiplayerCameraService::GetRuntimeTypeInfo()
{
    return reinterpret_cast<void*>(0x143C7A8C8);
}

bool app::camera::MultiplayerCameraService::ProcessMessage(hh::fnd::Message& message)
{
    switch (message.ID) {
    case 8850:
        mutex2.Lock();

    default:
        return false;
    }
}

void app::camera::MultiplayerCameraService::OnAddedToGame()
{
    pGameManager->AddListener(this);
    pGameManager->RegisterGameStepListener(*this);

    if (!cameraManager)
        cameraManager = pGameManager->GetService<hh::game::CameraManager>();
    physicsWorld = pGameManager->GetService<hh::physics::PhysicsWorldBullet>();
}

void app::camera::MultiplayerCameraService::OnRemovedFromGame()
{
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; i < 3; i++) {
            cameraBridges[i][j].~CameraBridgeUnit();
        }
    }
    pGameManager->RemoveListener(this);
    pGameManager->UnregisterGameStepListener(*this);
}

void app::camera::MultiplayerCameraService::GameServiceAddedCallback(hh::game::GameService* gameService)
{
    if (cameraManager == nullptr && gameService->GetRuntimeTypeInfo() == reinterpret_cast<void*>(0x143CEEC58))
        cameraManager = static_cast<hh::game::CameraManager*>(gameService);

    if (physicsWorld == nullptr && gameService->GetRuntimeTypeInfo() == reinterpret_cast<void*>(0x143CE6EA0))
        physicsWorld = static_cast<hh::physics::PhysicsWorld*>(gameService);
}

void app::camera::MultiplayerCameraService::GameServiceRemovedCallback(hh::game::GameService* gameService)
{
    if (gameService == cameraManager)
        cameraManager = nullptr;

    if (gameService == physicsWorld)
        physicsWorld = nullptr;
}

void app::camera::MultiplayerCameraService::UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo)
{
    for (size_t i = 0; i < 2; i++) {
        //if (camInfo.timeLeftInZoom > 0.0) {
        //    camInfo.timeLeftInZoom -= gameStepInfo.updateInfo.deltaTime;

        //    if (camInfo.timeLeftInZoom <= 0.0) {
        //        auto hCameraFrame = camInfo.cameraBridges[0].cameraFrame;

        //        if (auto* cameraFrame = hh::fnd::MessageManager::GetMessengerByHandle(hCameraFrame)) {
        //            MsgCameraZoomEnd msgCameraZoomEnd{};
        //            SendMessageImm(hCameraFrame, msgCameraZoomEnd);

        //            if (auto* zoomExtension = cameraFrame->GetZoomExtension()) {
        //                zoomExtension->EndZoom();
        //            }
        //        }
        //    }
        //}

        app::level::PlayerInformation* playerInformation{};
        if (auto* levelInfo = gameManager->GetService<app::level::LevelInfo>())
            playerInformation = levelInfo->GetPlayerInformation(i);

        for (auto x : unk4) {
            // do stuff...
        }

        // do free camera stuff

        // do ui stuff
    }
}

app_cmn::camera::CameraFrame* app::camera::MultiplayerCameraService::CreateDefaultCameraFrame(int componentId, int viewportId, int priority, float nearClip, float farClip, float fov)
{
    return nullptr;
}

hh::fnd::Handle<hh::fnd::Messenger> app::camera::MultiplayerCameraService::GetCameraFrame(int index)
{
    return hh::fnd::Handle<hh::fnd::Messenger>();
}

hh::fnd::Handle<hh::fnd::Messenger> app::camera::MultiplayerCameraService::GetCameraFrame(hh::game::GameManager gameManager, int index)
{
    return hh::fnd::Handle<hh::fnd::Messenger>();
}

app::camera::MultiplayerCameraService::CameraBridgeUnit::~CameraBridgeUnit()
{
    if (auto* camFrame = static_cast<hh::game::GameObject*>(hh::fnd::MessageManager::GetMessengerByHandle(cameraFrame))) {
        camFrame->Kill();
        cameraFrame = nullptr;
        cameraBridge.SetCameraComponent(nullptr);
    }
}

*/
