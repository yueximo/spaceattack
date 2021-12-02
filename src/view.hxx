#pragma once

#include "model.hxx"
#include <ge211.hxx>

struct Model;

struct View
{
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    ge211::Dims<int> initial_window_dimensions() const;

    Model const& model_;
    ge211::Image_sprite const uship_sprite;
    ge211::Image_sprite const eship1_sprite;
    ge211::Image_sprite const eship2_sprite;
    ge211::Image_sprite const eship3_sprite;
    ge211::Image_sprite const missile_sprite;
    ge211::Rectangle_sprite const back_sprite;
    ge211::Image_sprite const win_sprite;
    ge211::Image_sprite const lose_sprite;
    ge211::Font const font{"sans.ttf", 25};
    ge211::Text_sprite health_sprite;
    ge211::Text_sprite timer_sprite;







};
