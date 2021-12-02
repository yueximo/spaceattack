// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include <iostream>
#include "eships.hxx"

#include "game_config.hxx"



Eship1::Eship1(Coordinate x, Coordinate y, Coordinate width, Coordinate
        height, int health,Velocity vel, Game_config const& config)
        :x(x),
         y(y),
         height(config.eship_dims.height),
         width(config.eship_dims.width),
         health(config.eship1health),
         vel(config.eship1_velocity_0)
{}

bool
Eship1::eship1_hits_bottom(Game_config const& config) const
{
    Position eship1bottom = Position (Eship1::x, Eship1::y);
    eship1bottom = eship1bottom.right_by(Eship1::width/2);
    eship1bottom = eship1bottom.down_by(Eship1::height/2);

    int bottom = eship1bottom.y;
    int bottom_scene = (config.scene_dims.height);

    if (bottom == (bottom_scene)){

        return true;
    }

    else{
        return false;
    }

}


Eship2::Eship2(Coordinate x, Coordinate y, Coordinate width, Coordinate
        height,int health, Velocity vel, Game_config const& config)
        :x(x),
         y(y),
         height(config.eship_dims.height),
         width(config.eship_dims.width),
         health(config.eship2health),
         vel(config.eship2_velocity_0)
{}

bool
Eship2::eship2_hits_bottom(Game_config const& config) const
{
    Position eship2bottom = Position (Eship2::x, Eship2::y);
    eship2bottom = eship2bottom.right_by(Eship2::width/2);
    eship2bottom = eship2bottom.down_by(Eship2::height/2);

    int bottom = eship2bottom.y;
    int bottom_scene = (config.scene_dims.height);

    if (bottom == (bottom_scene)){
        return true;
    }

    else{
        return false;
    }

}

Eship3::Eship3(Coordinate x, Coordinate y, Coordinate width, Coordinate
                height,int health, Velocity vel, Game_config const& config)
        :x(x),
         y(y),
         height(config.eship_dims.height),
         width(config.eship_dims.width),
         health(config.eship3health),
         vel(config.eship3_velocity_0)
{}
bool
Eship3::eship3_hits_bottom(Game_config const& config) const
{
    Position eship3bottom = Position (Eship3::x, Eship3::y);
    eship3bottom = eship3bottom.right_by(Eship3::width/2);
    eship3bottom = eship3bottom.down_by(Eship3::height/2);

    int bottom = eship3bottom.y;

    int bottom_scene = (config.scene_dims.height);

    if (bottom == (bottom_scene)){
        return true;
    }
    else{
        return false;
    }

}



