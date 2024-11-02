#include "AssetPool.hpp"
#include "util.hpp"
#include <cassert>



pk::AssetPool::AssetPool() {
    this->texturePool.reserve(256);
}


Texture2D pk::AssetPool::get(const char* fileName) {
    const std::size_t h = pk::hash(fileName);
    if (this->texturePool.find(h) == this->texturePool.end()) {
        Texture2D t = LoadTexture(fileName);
        assert(t.id > 0);
        this->texturePool.emplace(h, t);
    }
    return this->texturePool[h];
}


void pk::AssetPool::erase(const char* fileName) {
    const std::size_t h = pk::hash(fileName);
    if (this->texturePool.find(h) != this->texturePool.end()) {
        UnloadTexture(this->texturePool[h]);
    }
    this->texturePool.erase(h);
}


void pk::AssetPool::clear() {
    for (auto& pair : this->texturePool) {
        UnloadTexture(pair.second);
    }
    this->texturePool.clear();
}


std::size_t pk::AssetPool::size() const {
    return this->texturePool.size();
}