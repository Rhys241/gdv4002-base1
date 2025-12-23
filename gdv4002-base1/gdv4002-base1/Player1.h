#pragma once
#include "Vector2.h"

class Player1
{
    public:
        Player1();
        void Load();
        void init();
        void Update(float dt);
        void Render();
        void Rotate(float amount);
        void Thrust();
       
        float GetRotation() const { return m_rotation; }
        
        Vector2 m_position;

    private:
        float m_rotation;
        float m_speed;
        unsigned int m_textureID;
};
