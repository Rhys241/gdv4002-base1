#pragma once
#include "Vector2.h"

class Player1
{
    public:
        Player1();

        void Update(float dt);
        void Render();

    private:
        Vector2 m_position;
        float m_roation;
        float m_speed;
};
