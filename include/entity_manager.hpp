#pragma once
#include <vector>

#include "entity.hpp"

enum class EntityType {
    BULLET
};


class EntityManager {
private:
    std::vector<Entity*> entities;
    Game* game;

public:
    EntityManager(Game * game);
    ~EntityManager();

    void addEntity(const int x, const int y, const EntityType type);

    void update(const int elapsed);
private:
    void releaseAll();
    void releaseDead();
};