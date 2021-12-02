/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

// Defines a struct for modeling the eship
// .

#pragma once

#include "game_config.hxx"
#include <ge211.hxx>


using Position = ge211::Posn<float>;


using Velocity = ge211::Dims<int>;

using Block = ge211::Rect<int>;

struct Eship1 : Block
{
    Eship1(Coordinate x, Coordinate y, Coordinate width, Coordinate height,
           int health, Velocity vel, Game_config const&);

    int x;
    int y;
    int height;
    int width;
    int health;

    Velocity vel;

    bool eship1_hits_bottom(Game_config const&) const;

    std::vector<Eship1> eships1;


};

struct Eship2 : Block
{
    Eship2(Coordinate x, Coordinate y, Coordinate width, Coordinate height,
           int health, Velocity vel, Game_config const&);

    int x;
    int y;
    int height;
    int width;
    int health;
    Velocity vel;


    bool eship2_hits_bottom(Game_config const&) const;

    std::vector<Eship2> eships2;


};

struct Eship3: Block
{
    Eship3(Coordinate x, Coordinate y, Coordinate width, Coordinate height,
           int health, Velocity vel, Game_config const&);

    int x;
    int y;
    int height;
    int width;
    int health;
    Velocity vel;

    bool eship3_hits_bottom(Game_config const&) const;

    std::vector<Eship3> eships3;


};

