#pragma once
#include <raylib.h>
#include "../util/TexturePool.hpp"
#include "../util/Direction.hpp"
#include "../util/types.hpp"


namespace pk {

    constexpr std::size_t NUM_COMPONENTS{2};

    typedef struct transform {
        Vector2 pos{};
        Vector2 size{};
        pk::zindex_t zindex{};
        pk::Direction direction{pk::Down};
        transform() = default;
        explicit transform(const pk::zindex_t zindex) : zindex(zindex) { }
    } transform_t;


    typedef struct sprite {
        Texture2D texture{};
        sprite() = default;
        explicit sprite(const char* fileName) : texture(pk::gAssetPool.get(fileName)) { }
    } sprite_t;

}