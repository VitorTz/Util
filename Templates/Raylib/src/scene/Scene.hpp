#pragma once
#include <memory>
#include "../constants.hpp"
#include "../util/SceneId.hpp"


namespace pk {


    class Scene {

    public:
        virtual ~Scene() = default;
        virtual void update(float dt) = 0;
        virtual void draw() = 0;

    };

    class LoadingScreen : public pk::Scene {

    public:
        LoadingScreen();
        void update(float dt) override;
        void draw() override;

    };

    class TitleScreen : public pk::Scene {

    public:
        TitleScreen();
        void update(float dt) override;
        void draw() override;

    };

    class LevelScreen : public pk::Scene {

    public:
        LevelScreen();
        void update(float dt) override;
        void draw() override;

    };

    class SceneManager : public pk::Scene {

    private:
        std::unique_ptr<pk::Scene> scene{};
        pk::SceneID sceneId{pk::MAIN_SCENE};
        bool shouldChangeScene{};
        
    private:
        void loadNextScene();

    public:
        void init();
        void changeScene(pk::SceneID sceneId);
        void update(float dt) override;
        void draw() override;

    };

    inline pk::SceneManager gSceneManager{};

}