// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "missile.hxx"

#include "eships.hxx"

#include "game_config.hxx"

// Computes where the missile should be when it's stuck to the paddle:
// centered above it, 1 pixel up.
static Position
missile_pos(
        Block const& block,
        Game_config const& config)
{
    Position topleft = ge211::Posn<float>(block.top_left());
    Position p2 = Position(topleft.right_by(((block.width)/2)));
    Position p3 = Position(topleft.up_by(1 + config.missile_dims.height/2));
    Position result = Position (p2.x, p3.y);
    return result;
}

// It won't compile without this, so you get it for free.

Missile::Missile(Block const& uship, Game_config const& config)
        :
        width(config.missile_dims.width),
        height(config.missile_dims.height),
          center(missile_pos(uship, config)),
          velocity(Velocity(config.missile_velocity_0))
{ }

Position
Missile::top_left() const
{
    Position missilecenter = Missile::center;
    Position p2 = Position(missilecenter.left_by(Missile::width));
    Position p3 = Position(missilecenter.up_by(Missile::height/2));

    Position final = Position(p2.x,p3.y);

    return final;
}


//detecting where the missile is after it
Missile
Missile::next(double dt) const
{
    Missile result(*this);

    int missileyv = Missile::velocity.height;

    Position epic = Missile::center;
    Position p3 = Position(epic.up_by(missileyv * dt));
    Position end = Position(epic.x,p3.y);

    result.center = end;

    return result;
}

//IF HITS A ENEMY SHIP WITH MISSILE
bool
Missile
::hits_eship1(Eship1 eship1) const
{

    //its similar to brick out where we see if it hits and destroys. BUT IT
    // IS NOT DESTROYING IT STAYS IN THE VECTOR. I feel like its collision
    // detection but i checked the math and it works. i can show you the game

    Position missilecenter = Missile::center;
    int h = Missile::height/2;
    int w = Missile::width/2;

    Position missileright = Position(missilecenter.right_by
            (w));
    Position missileleft = Position(missilecenter.left_by(w));
    Position missileup = Position(missilecenter.up_by(h));
    Position missiledown = Position(missilecenter.down_by(h));

    Position eshipcenter = Position(eship1.x,eship1.y);
    eshipcenter = Position(eshipcenter.right_by(eship1.width/2));
    eshipcenter = Position(eshipcenter.down_by(eship1.height/2));

    int eshipwidth = eship1.width/2;
    int eshipheight = eship1.height/2;


    Position eshipright = Position(eshipcenter.right_by(eshipwidth));
    Position eshipleft = Position(eshipcenter.left_by(eshipwidth));
    Position eshipup = Position(eshipcenter.up_by(eshipheight));
    Position eshipdown = Position(eshipcenter.down_by(eshipheight));

    if (missileright.x < eshipleft.x || eshipright.x < missileleft.x ||
    missiledown.y <eshipup.y || eshipdown.y <missileup.y){

        return false;
    }
    else{

        return true;
    }

}



bool
Missile
::hits_eship2(Eship2 eship2) const
{
    Position missilecenter = Missile::center;
    int h = Missile::height/2;
    int w = Missile::width/2;
    Position missileright = Position(missilecenter.right_by(w));
    Position missileleft = Position(missilecenter.left_by(w));
    Position missileup = Position(missilecenter.up_by(h));
    Position missiledown = Position(missilecenter.down_by(h));

    Position eshipcenter = Position(eship2.x,eship2.y);
    eshipcenter = Position(eshipcenter.right_by(eship2.width/2));
    eshipcenter = Position(eshipcenter.down_by(eship2.height/2));

    int eshipwidth = eship2.width/2;
    int eshipheight = eship2.height/2;
    Position eshipright = Position(eshipcenter.right_by(eshipwidth));
    Position eshipleft = Position(eshipcenter.left_by(eshipwidth));
    Position eshipup = Position(eshipcenter.up_by(eshipheight));
    Position eshipdown = Position(eshipcenter.down_by(eshipheight));

    if (missileright.x < eshipleft.x || eshipright.x < missileleft.x ||
        missiledown.y <eshipup.y || eshipdown.y < missileup.y){
        return false;
    }

    else{

        return true;
    }

}



bool
Missile
::hits_eship3(Eship3 eship3) const
{
    Position missilecenter = Missile::center;
    int h = Missile::height/2;
    int w = Missile::width/2;

    Position missileright = Position(missilecenter.right_by(w));
    Position missileleft = Position(missilecenter.left_by(w));
    Position missileup = Position(missilecenter.up_by(h));
    Position missiledown = Position(missilecenter.down_by(h));

    Position eshipcenter = Position(eship3.x,eship3.y);
    eshipcenter = Position(eshipcenter.right_by(eship3.width/2));
    eshipcenter = Position(eshipcenter.down_by(eship3.height/2));

    int eshipwidth = eship3.width/2;
    int eshipheight = eship3.height/2;
    Position eshipright = Position(eshipcenter.right_by(eshipwidth));
    Position eshipleft = Position(eshipcenter.left_by(eshipwidth));
    Position eshipup = Position(eshipcenter.up_by(eshipheight));
    Position eshipdown = Position(eshipcenter.down_by(eshipheight));

    if (missileright.x < eshipleft.x || eshipright.x < missileleft.x ||
        missiledown.y <eshipup.y || eshipdown.y < missileup.y){
        return false;
    }
    else{

        return true;
    }

}


bool
Missile::destroy_eship1(std::vector<Eship1>& eship1) const
{
    size_t count = 0;
    for (Eship1& l : eship1) {

        if (hits_eship1(l)) {
            l.health = l.health - 1;
            if (l.health == 0) {
                std::swap(eship1.at(count), eship1.back());
                eship1.pop_back();


            }
            return true;

        }
        count = count + 1;
    }
    return false;
}


bool
Missile::destroy_eship2(std::vector<Eship2>& eship2) const
{
    size_t count = 0;
    for (Eship2& la : eship2) {
        if (hits_eship2(la)) {
            la.health = la.health - 1;
            if (la.health == 0) {
                std::swap(eship2.at(count), eship2.back());
                eship2.pop_back();
            }
            return true;


        }
        count = count + 1;
    }
    return false;
}


bool
Missile::destroy_eship3(std::vector<Eship3>& eship3) const
{
    size_t count = 0;
    for (Eship3& lam : eship3){
        if (hits_eship3(lam)) {

            lam.health = lam.health - 1;
            if (lam.health == 0) {
                std::swap(eship3.at(count), eship3.back());
                eship3.pop_back();

            }
            return true;
        }
        count = count + 1;
    }
    return false;
}


bool
operator==(Missile const& a, Missile const& b)
{
    if (a.width == b.width && a.height == b.height && a.center == b.center
    && a.velocity == b.velocity){
        return true;
    }
    return false;
}

bool
operator!=(Missile const& a, Missile const& b)
{
    return !(a == b);
}

std::ostream&
operator<<(std::ostream& o, Missile const& ball)
{
    // You may have seen this message when running your tests. It
    // would be more helpful if it showed the contents of each ball,
    // right? So you can make that happen by making this print the
    // contents of the ball (however you like).
    o << "Missile{";
    o << "TODO: see the bottom of missile.cxx for more info";
    return o << "}";
}