#pragma once
#include "Vector2.h"

class Player1
{
    public:
        Player1();

        void Update(float dt);
        void Render();
        void Rotate(float amount);
        void Thrust();

    private:
        Vector2 m_position;
        float m_rotation;
        float m_speed;
        unsigned int m_textureID;
};
