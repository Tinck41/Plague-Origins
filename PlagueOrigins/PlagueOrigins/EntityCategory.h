#pragma once

enum EntityCategory
{
    PLAYER = 0x0001,
    //NPC = 0x0002, // возможно стоит объединить 2 нижних.
    ENEMY_NPC = 0x0002,
    FRIENDLY_NPC = 0x0004,
    OBSTACLE = 0x0008,
    ENEMY_AGGRO_RADIUS = 0x0010,
    ATTACK_RADIUS = 0x0011
};