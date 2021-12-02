// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "model.hxx"
#include "ge211_time.hxx"
#include "eships.hxx"




Model::Model(Game_config const& config)
        : config(config),
          uship(Block::from_top_left(config.uship_top_left_0(),
                                      config.uship_dims)),

          missile(uship,config),
          player_health(config.ushiphealth),
          seconds_remaining_(config.seconds_remaining),
          vel(config.uship_velocity_0),
          game_over(false),
          random_x(config.side_margin, config.scene_dims.width - config
          .side_margin)

{
    float xcoord1 = config.side_margin;
    float ycoord1 = 0;

    for (int i = 0; i<config.eship1total; i++) {

            Eship1 one
                    (xcoord1, ycoord1, config.eship1_dims().width, config
                            .eship1_dims().height,
                            config.eship1health, config.eship1_velocity_0,
                            config);

           while((xcoord1>=(one.x-config.eship_dims.width) and
                    (xcoord1<=(one.x+config.eship_dims.width))) or ((xcoord1
                    - config.eship_dims.width < 0) or (xcoord1 + config
                    .eship_dims.width > config .scene_dims.width))){

                xcoord1 = random_x(config.side_margin,
                                  config.scene_dims.width - config
                                           .side_margin);
            }
        eships1.push_back(one);
    }

    float xcoord2 = config.side_margin;
    float ycoord2 = 0;

    for (int i = 0; i<config.eship2total; i++){

        Eship2 two = Eship2(xcoord2,ycoord2,config.eship2_dims().width, config
                .eship2_dims().height, config.eship2health, config
                .eship2_velocity_0,config);
        while((xcoord2>=(two.x-config.eship_dims.width) and
                (xcoord2<=(two.x+config.eship_dims.width))) or ((xcoord2
                                                                 - config
                                                                 .eship_dims.width < 0) or (xcoord2 + config
                .eship_dims.width > config .scene_dims.width))){
            xcoord2 =
                    random_x(config.side_margin,
                             config.scene_dims.width - config
                                     .side_margin);
        }
        eships2.push_back(two);
    }


    float xcoord3 = config.side_margin;
    float ycoord3 = 0;


    for (int i = 0; i<config.eship3total; i++){

        Eship3 three = Eship3(xcoord3,ycoord3,config.eship3_dims().width, config
                .eship3_dims().height, config.eship3health, config
                .eship3_velocity_0,config);

        while((xcoord3>=(three.x-config.eship_dims.width) and
               (xcoord3<=(three.x+config.eship_dims.width))) or ((xcoord3
               - config.eship_dims.width < 0) or (xcoord3 + config
                .eship_dims.width > config .scene_dims.width))){
            xcoord3 =
                    random_x(config.side_margin,
                             config.scene_dims.width - config
                                     .side_margin);
        }
        eships3.push_back(three);
    }
}



double
Model::seconds_remaining() const
{
    return seconds_remaining_;
}

void
Model::set_game_over()
{
    game_over = true;
}

bool
Model::uship_hits_left()
{
    int left = uship.center().x - uship.width/2;
    if (left <= 0){
        return true;
    }
    else{
        return false;
    }
}

bool
Model::uship_hits_right(){
    int right = uship.center().x + uship.width/2;

    if (right >= config.scene_dims.width){
        return true;
    }
    else{
        return false;
    }
}

//fires a missile, stores a missile in a vector and places it above the uship
void
Model::fire_missile()
{
    missile = Missile(uship,config);
    player_missiles.push_back(missile);
}

void
Model::move_left()
{
    uship.x = uship.x - config.uship_velocity_0.width;
}

void
Model::move_right()
{
    uship.x = uship.x + config.uship_velocity_0.width;
}

void
Model::eship1_move()
{
    for (Eship1& x : eships1){
        x.y += config.eship1_velocity_0.height;
    }
}

void
Model::eship2_move()
{
    for (Eship2& x : eships2){
        x.y += config.eship2_velocity_0.height;
    }
}

void
Model::eship3_move()
{
    for (Eship3& x : eships3){
        x.y += config.eship3_velocity_0.height;
    }
}


void
Model::on_frame(double dt)
{

    //decrease seconds_remaining
    seconds_remaining_ -= dt;

    if (!game_over) {

        //destroying the ships if a missile hits it and updates the missile
        for (Missile& b: player_missiles){
            if (b.next(dt).destroy_eship1(eships1) or b.next(dt)
                                                       .destroy_eship2(eships2) or b.next(dt).destroy_eship3(eships3)){
                player_missiles.pop_back();
            }

            b = b.next(dt);
        }

        //moving eship 1
        double time_left = seconds_remaining();
        double before_second_wave = (config.seconds_remaining - (config.seconds_remaining/3));
        if(time_left >= before_second_wave){
            eship1_move();
        }

        //moving eship2
        time_left = seconds_remaining();
        double before_third_wave = (config.seconds_remaining - ((config.seconds_remaining/3)*2));
        if (time_left >= before_third_wave && time_left < before_second_wave) {
            eship2_move();
        }

        //moving eship3
        time_left = seconds_remaining();
        if (time_left > 0 && time_left < before_third_wave) {
            eship3_move();
        }

        //health off if ships hit the bottom
        for (Eship1& e : eships1) {
            if (e.eship1_hits_bottom(config)) {
                Model::player_health = Model::player_health - 1;
            }
        }

        for (Eship2& ep : eships2) {
            if (ep.eship2_hits_bottom(config)) {
                Model::player_health = Model::player_health - 2 ;
            }
        }

        for (Eship3& epi : eships3) {
            if (epi.eship3_hits_bottom(config)) {
                Model::player_health = Model::player_health - 3;
            }
        }
    }
    //losing conditions
    if (seconds_remaining() <= 0) {
        set_game_over();
    }

    if (Model::player_health <= 0) {
        set_game_over();
    }

}
