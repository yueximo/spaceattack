/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

// Defines a struct to hold configuration parameters. You should try different
// values to ensure that your model and UI adjust appropriately. You can do this
// by creating an instance and then assigning its parameters before constructing
// a `Model`:
//
//     Game_config config;
//     config.brick_cols = 15;
//     config.ball_radius *= 2;
//     Model model(config);
//

#pragma once

#include <ge211.hxx>


struct Game_config
{
    // Constructs an instance with the default parameters.
    Game_config();

    // The dimensions of the whole window:
    ge211::Dims<int> scene_dims;

    // The dimensions of the user spaceship:
    ge211::Dims<int> uship_dims;

    // The dimensions of the enemy spaceship:
    ge211::Dims<int> eship_dims;

    ge211::Dims<int> eship_spacing;

    int eship1total;
    int eship2total;
    int eship3total;

    int ushiphealth;

    int eship1health;
    int eship2health;
    int eship3health;

    int seconds_remaining;

    // The ball's initial velocity {width, height}:
    ge211::Dims<int> missile_velocity_0;
    ge211::Dims<int> uship_velocity_0;
    ge211::Dims<int> eship1_velocity_0;
    ge211::Dims<int> eship2_velocity_0;
    ge211::Dims<int> eship3_velocity_0;

    //Radius of the missile:
    ge211::Dims<int> missile_dims;


    // Number of pixels from sides of screen to sides of enemy spaceship
    // formation:
    int side_margin;

    int top_margin;

    // Number of pixels from bottom of screen to bottom of user spaceship.
    int bottom_margin;

    ge211::Posn<int> uship_top_left_0() const;


    ge211::Dims<int> eship1_dims() const;
    ge211::Dims<int> eship2_dims() const;
    ge211::Dims<int> eship3_dims() const;


};

