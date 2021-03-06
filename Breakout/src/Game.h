#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "SpriteRenderer.h"
#include "GameLevel.h"

enum class EDirection
{
    Up,
    Right,
    Down,
    Left
};

enum class EGameState
{
    Active,
    Menu,
    Win
};

// <is collision, what direction, difference vector center - closest point>
typedef std::tuple<bool, EDirection, glm::vec2> Collision;

class Game
{
public:
    Game(unsigned int width, unsigned int height);
    ~Game();

    void Init();

    void ProcessInput(float dt);
    void Update(float dt);
    void Render();

    void DoCollisions();

    EGameState GetState()
    {
        return m_state;
    };

    void ResetLevel();
    void ResetPlayer();

public:
    bool m_keys[1024];

private:
    EGameState m_state;
    unsigned m_width, m_height;
    std::vector<GameLevel> m_levels;
    unsigned int m_currentLevel;
};