#pragma once
#include "base/window_element.hpp"
#include "entity_manager.hpp"
#include "bullet_panel.hpp"
#include "score_panel.hpp"

// Main game class, controls the whole game
class Game: public WindowElement{
private:
    EntityManager entity_manager;
    BulletPanel bullet_panel;
    ScorePanel score_panel;

    bool is_over;
    bool is_stopped;
    
    int score;

    int asteroid_interval = 400000;
    int asteroid_generation_chance;
    int ammuniation_generation_chance;
    int generation_count = 0;
public:
    Game();
    ~Game();

    void update(const int elapsed);
    void draw();

    bool isOver();

    EntityManager* getEntityManager();

    void stop();
    void resume();

    void addScore(const int dscore);
    void nullifyScore();
private:
    void gameOverScreen();

    void generateAsteroids();    

    void restart();
    void exit();
};
