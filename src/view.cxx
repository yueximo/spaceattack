#include "view.hxx"
#include "model.hxx"


//background color
static ge211::Color const back_color{0,0,0};

View::View(Model const& model)
        : model_(model),
        uship_sprite{"playersprite2.png"},
        eship1_sprite{"spaceship1.png"},
        eship2_sprite{"spaceship2.png"},
        eship3_sprite{"spaceship3.png"},
        missile_sprite("missile.png"),
        back_sprite(model_.config.scene_dims,back_color),
        win_sprite("you_win.png"),
        lose_sprite("you_lose.png"),
        health_sprite({"Health: " + std::to_string(model_.player_health)},font),
        timer_sprite({"Seconds Remaining: " + std::to_string(model_
        .seconds_remaining())},font)
{ }

ge211::Dims<int>
View::initial_window_dimensions() const
{
    return model_.config.scene_dims;
}

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(back_sprite,{0,0},1);

    //win or lose sprites
    if (model_.game_over){
        if (model_.player_health>0) {
            set.add_sprite(win_sprite, {(model_.config.scene_dims.width / 2) -
            win_sprite.dimensions().width / 2,
            (model_.config.scene_dims.height / 2) - win_sprite.dimensions()
            .height / 2}, 10);
}
        if (model_.player_health<=0) {
            set.add_sprite(lose_sprite, {(model_.config.scene_dims.width / 2) -
                                        win_sprite.dimensions().width / 2,
                                        (model_.config.scene_dims.height / 2) - win_sprite.dimensions()
                                                                                          .height / 2}, 10);
        }
    }

    if (!model_.game_over){
        //timer
        timer_sprite = ge211::Text_sprite({"Seconds Remaining: " +
                                           std::to_string(model_.
                                           seconds_remaining())},font);
        set.add_sprite(timer_sprite,{10,0},3);

        //health indicator
        health_sprite = ge211::Text_sprite({"Health: " +std::to_string(model_.player_health)},font);
        set.add_sprite(health_sprite,{10,40},3);
        set.add_sprite(uship_sprite,{model_.uship.x,model_.uship.y},2);

        //shooting missiles
        for (Missile a : model_.player_missiles){
            set.add_sprite(missile_sprite, a.top_left().into<int>(), 2);
        }

        //creating the first wave
        double time_left = model_.seconds_remaining();
        double before_second_wave = (model_.config.seconds_remaining - (model_
                .config.seconds_remaining/3));

        //double secs_to_print = time_left/model_.config.eship1total;
        if (time_left >= before_second_wave) {
            for (Eship1 x: model_.eships1) {
                    set.add_sprite(eship1_sprite, {x.x, x.y}, 2);

            }
        }

        //creating the second wave
        time_left = model_.seconds_remaining();
        double before_third_wave = (model_.config.seconds_remaining - ((model_
                                                                       .config.seconds_remaining/3)*2));
        if (time_left >= before_third_wave && time_left < before_second_wave) {
            for (Eship2 y: model_.eships2) {
                set.add_sprite(eship2_sprite, {y.x,y.y}, 2);
            }
        }

        //creating the third wave
        time_left = model_.seconds_remaining();
        if (time_left > 0 && time_left < before_third_wave) {
            for (Eship3 z: model_.eships3) {
                set.add_sprite(eship3_sprite, {z.x,z.y}, 2);
            }
        }
    }
}
