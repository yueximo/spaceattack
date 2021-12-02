#include "model.hxx"
#include "game_config.hxx"
#include <catch.hxx>

Game_config const config;

//this test should be the same for eship2 and eship3 because they all act the
// same. no need to make unit test for eship2 and eship3
TEST_CASE("hits and destroys an eship1")
{
    Model m(config);

    m.eships1.clear();
    m.eships2.clear();
    m.eships3.clear();
    m.player_missiles.clear();

    //create a eship1 to use as a test
    Eship1 test = Eship1(100,100,m.config.eship1_dims().width, m.config
    .eship1_dims().height, m.config.eship1health, m.config.eship1_velocity_0,m.config);


    //check eships1 is still empty before we add something to the vecotr
    CHECK(m.eships1.empty());

    //add test eship1 to vector
    m.eships1.push_back(test);

    //check that the vector is now no longer empty
    CHECK(!m.eships1.empty());

    //check that we have not fired any missiles
    CHECK(m.player_missiles.empty());
    //fire missile. should load a missile into player_missiles

    //set upship position in a way that the missile lines up under the eship
    m.uship.x = 70;
    m.uship.y = 516;

    //fire the missile. should load it into the player_missiles vector
    m.fire_missile();
    //check that it is loaded in the vector
    CHECK(!m.player_missiles.empty());

    //move forward in time
    m.on_frame(1);

    //check that the missile is now gone after it hit the eship
    CHECK(m.player_missiles.empty());

    //check that the eship is now gone after it was hit by the missile
    CHECK(m.eships1.empty());


}

TEST_CASE("see if you lose when health reaches 0"){
    Model m(config);
    m.eships1.clear();
    m.eships2.clear();
    m.eships3.clear();

    m.player_health = 1;
    //set a ship that has its bottom 1 pixel away from bottom of scene
    Eship1 test = Eship1(0,736,m.config.eship2_dims().width, m.config
    .eship2_dims().height, m.config.eship2health, m.config.eship2_velocity_0,m.config);

    m.eships1.push_back(test);
    //move forward in time
    m.on_frame(1);

    //check if health was taken off and game ended
    CHECK(m.player_health == 0);
    CHECK(m.game_over);
}

TEST_CASE("do the eships move"){
    Model m(config);
    m.eships1.clear();
    m.eships2.clear();
    m.eships3.clear();

    m.seconds_remaining_ = m.config.seconds_remaining;

    Eship1 test1 = Eship1(0,0,m.config.eship1_dims().width, m.config
    .eship1_dims().height, m.config.eship1health, m.config.eship1_velocity_0,m.config);

    Eship2 test2 = Eship2(0,0,m.config.eship2_dims().width, m.config
    .eship2_dims().height, m.config.eship2health, m.config.eship2_velocity_0,m.config);

    Eship3 test3 = Eship3(0,0,m.config.eship3_dims().width, m.config
    .eship3_dims().height, m.config.eship3health, m.config.eship3_velocity_0,m.config);

    int past1 = test1.y;
    int past2 = test2.y;
    int past3 = test3.y;

    m.eships1.push_back(test1);
    m.eships2.push_back(test2);
    m.eships3.push_back(test3);

    //move forward in time for a while (because eships2 and eships 3 dont
    // begin moving until a certain period of time. so best to move forward a
    // lot so all have moven)
    for(int i = 0; i < 300000; i++) {
        m.on_frame(1);
    }

    //checks that the position of the eships that are further in time are now
    // greater than their past selves. so they have moved "downwards"
    CHECK(m.eships1[0].y > past1);
    CHECK(m.eships2[0].y > past2);
    CHECK(m.eships3[0].y > past3);
}


TEST_CASE("find position of missile") {
    Model m(config);

    m.player_missiles.clear();

    //fire missile. should load a missile into player_missiles
    m.fire_missile();

    //create a missile that is the future position of the missile
    Missile expected_missile(m.player_missiles[0].next(1));

    //move forward in time
    m.on_frame(1);

    //check if the current missile is now equal to the expected
    CHECK(m.player_missiles[0] == expected_missile);

    //check if the current missile is now equal to the expected
    CHECK(m.player_missiles[0].center == expected_missile.center);
}

TEST_CASE("game win by timer"){
    Model m(config);
    m.eships1.clear();
    m.eships2.clear();
    m.eships3.clear();
    //check that the game isn't over
    CHECK(!m.game_over);

    m.seconds_remaining_ = 1;
    //check it is not over still
    CHECK(!m.game_over);

    //move forward in time
    m.on_frame(1);

    //check that the seconds remaining is 0, so the game should end
    CHECK(m.seconds_remaining_ == 0);

    //check that game is over because the timer is now 0
    CHECK(m.game_over);
}

//this test should be the same for eship3 so no need to make a test with eship3
TEST_CASE("tests that eship2 have two health")
{
    Model m(config);
    m.eships1.clear();
    m.eships2.clear();
    m.eships3.clear();
    m.player_missiles.clear();

    //create a eship1 to use as a test
    Eship2 test = Eship2(100,100,m.config.eship2_dims().width, m.config
                                                                .eship2_dims().height, m.config.eship2health, m.config

                                                                                                               .eship2_velocity_0,m.config);
    //check eships1 is still empty before we add something to the vecotr
    CHECK(m.eships2.empty());

    //add test eship1 to vector
    m.eships2.push_back(test);

    //check that the vector is now no longer empty
    CHECK(!m.eships2.empty());

    //checks that the health of eship2 is what it should be, 2
    CHECK(m.eships2[0].health ==2);

    //check that we have not fired any missiles
    CHECK(m.player_missiles.empty());
    //fire missile. should load a missile into player_missiles

    //set upship position in a way that the missile lines up under the eship
    m.uship.x = 70;
    m.uship.y = 516;

    //fire the missile. should load it into the player_missiles vector
    m.fire_missile();
    //check that it is loaded in the vector
    CHECK(!m.player_missiles.empty());

    //move forward in time
    m.on_frame(1);

    //check that the missile is now gone after it hit the eship
    CHECK(m.player_missiles.empty());

    //chceks that the health of the eship1 is now subtracted by 1, so now 1
    CHECK(m.eships2[0].health ==1);

    //checks that the eship2 is still there
    CHECK(!m.eships2.empty());

    //fire the missile. should load it into the player_missiles vector
    m.fire_missile();
    //check that it is loaded in the vector
    CHECK(!m.player_missiles.empty());

    //move forward in time
    m.on_frame(1);

    //check that the missile is now gone after it hit the eship
    CHECK(m.player_missiles.empty());

    //chceks that the health of the eship1 is now subtracted by 1, so now 0
    CHECK(m.eships2[0].health ==0);

    //checks that the eship2 is now gone
    CHECK(m.eships2.empty());
}

