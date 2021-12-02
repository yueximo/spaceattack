/*******************************************/
/*** DO NOT CHANGE ANYTHING IN THIS FILE ***/
/*******************************************/

// Defines a struct for modeling the missile
// .

#pragma once

#include "game_config.hxx"
#include "eships.hxx"

#include <ge211.hxx>
#include <vector>
#include <iostream>


using Position = ge211::Posn<float>;


using Velocity = ge211::Dims<int>;

using Block = ge211::Rect<int>;



struct Missile
{

    Missile(Block const& uship, Game_config const&);

    Position top_left() const;

    Missile next(double dt) const;

    bool hits_eship1(Eship1) const;

    bool hits_eship2(Eship2) const;

    bool hits_eship3(Eship3) const;

    bool destroy_eship1(std::vector<Eship1>& bricks) const;

    bool destroy_eship2(std::vector<Eship2>& bricks) const;

    bool destroy_eship3(std::vector<Eship3>& bricks) const;


    int width;
    int height;


    Position center;

    Velocity velocity;

};

/// Compares two `Missile`s for equality. This may be useful for testing.
///
/// Two `Missile`s are equal if all their member variables are pairwise
/// equal.
bool
operator==(Missile const&, Missile const&);

/// Inequality for `Missile`s.
bool
operator!=(Missile const&, Missile const&);

/// Stream insertion (printing) for `Missile`. This can make your test
/// results easier to read.
std::ostream&
operator<<(std::ostream&, Missile const&);
