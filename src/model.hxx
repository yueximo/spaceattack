#pragma once


#include "game_config.hxx"
#include "missile.hxx"
#include "eships.hxx"
#include <vector>
#include "ge211_time.hxx"



using Velocity = ge211::Dims<int>;


struct Model
{
    //consructor
    explicit Model(Game_config const& config = Game_config());



    double seconds_remaining() const;

    void set_game_over();

    void fire_missile();

    bool uship_hits_left();

    bool uship_hits_right();



    void move_left();

    void move_right();

    void eship1_move();
    void eship2_move();
    void eship3_move();

    void on_frame(double dt);

    Game_config const config;


    std::vector<Eship1> eships1;
    std::vector<Eship2> eships2;
    std::vector<Eship3> eships3;
    std::vector<Missile> player_missiles;

    Block uship;

    Missile missile;

    int player_health;

    double seconds_remaining_;

    Velocity vel;

    bool game_over;

    ge211::Random_source<int> random_x;


};