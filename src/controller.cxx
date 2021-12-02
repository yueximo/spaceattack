#include "controller.hxx"
#include "model.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}


void Controller::on_key(ge211::Key key)
{
    if (!model_.game_over) {
        if (key == ge211::Key::code('q')) {
            quit();
        }

        if (key == ge211::Key::code(' ')) {
            model_.fire_missile();
        }

        if (key == ge211::Key::left() and !(model_.uship_hits_left())) {
             model_.move_left();
        }
        if (key == ge211::Key::right() and !(model_.uship_hits_right())){
            model_.move_right();
        }

    }
}


void
Controller::on_mouse_up(ge211::Mouse_button, ge211::Posn<int>)
{
    model_.fire_missile();
}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

