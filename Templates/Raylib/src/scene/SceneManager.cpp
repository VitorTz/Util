#include "Scene.hpp"
#include <memory>


void pk::SceneManager::init() {
    this->loadNextScene();
}


void pk::SceneManager::loadNextScene() {
    switch (this->sceneId) { 
        case pk::TitleScreenId:
            this->scene = std::make_unique<pk::TitleScreen>();
            break;
        case pk::LevelScreenId:
            this->scene = std::make_unique<pk::LevelScreen>();
            break;
        case pk::LoadingScreenId:
            this->scene = std::make_unique<pk::LoadingScreen>();
            break;
        default:
            break;
    };
}


void pk::SceneManager::update(const float dt) {
    this->scene->update(dt);
}


void pk::SceneManager::draw() {
    this->scene->draw();
}


void pk::SceneManager::changeScene(const pk::SceneID sceneId) {
    this->shouldChangeScene = true;
    this->sceneId = sceneId;
}