/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

#include "game_config.hxx"

// This is the default (and only) constructor for `Game_config`. It
// determines all the default values of all the member variables.
Game_config::Game_config()
        : scene_dims {1000, 768},
          uship_dims {60, 60},
          eship_dims{60,60},
          eship_spacing{eship_dims.width,eship_dims.height},

          //number of eships
          eship1total{5},
          eship2total{7},
          eship3total{8},

          //health
          ushiphealth{20},
          eship1health{1},
          eship2health{2},
          eship3health{3},

          seconds_remaining{30},

          //velocities
          missile_velocity_0 {0, 400},
          uship_velocity_0 {30, 0},
          eship1_velocity_0 {0, 2},
          eship2_velocity_0 {0, 2},
          eship3_velocity_0 {0, 3},

          //missile dims
          missile_dims({10,30}),



          side_margin {0},
          top_margin{0},
          bottom_margin {50}
{ }

ge211::Posn<int>
Game_config::uship_top_left_0() const
{
    ge211::Posn<int> result(scene_dims);
    result.x /= 2;
    return result.up_by(bottom_margin + uship_dims.height);
}

static int
div_w_spacing(int total, int divisor, int space)
{
    if (divisor < 0) {
        throw ge211::Client_logic_error("need at least 1 row & 1 column");
    }

    return (total - (divisor - 1) * space) / divisor;
}


ge211::Dims<int>
Game_config::eship1_dims() const
{
    int field_width = scene_dims.width - 2 * side_margin;
    int field_height = top_margin;
    int width = div_w_spacing(field_width, eship1total, eship_spacing.width);
    int height = div_w_spacing(field_height, eship1total, eship_spacing.height);
    return {width, height};
}
ge211::Dims<int>
Game_config::eship2_dims() const
{
    int field_width = scene_dims.width - 2 * side_margin;
    int field_height = top_margin;
    int width = div_w_spacing(field_width, eship2total, eship_spacing.width);
    int height = div_w_spacing(field_height, eship2total, eship_spacing.height);
    return {width, height};
}
ge211::Dims<int>
Game_config::eship3_dims() const
{
    int field_width = scene_dims.width - 2 * side_margin;
    int field_height = top_margin;
    int width = div_w_spacing(field_width, eship3total, eship_spacing.width);
    int height = div_w_spacing(field_height, eship3total, eship_spacing.height);
    return {width, height};
}