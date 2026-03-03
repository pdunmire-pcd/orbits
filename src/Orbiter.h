#ifndef ORBITER_H
#define ORBITER_H

#include "bn_fixed_point.h"
#include "bn_sprite_ptr.h"

class Center;

/**
 * An object that orbits around a center. Orbits using Hooke's law, as if attached by a 2D spring.
 */
class Orbiter {
    public:
        Orbiter(bn::fixed_point starting_location, bn::fixed_point starting_velocity, Center& center);

        void update();

    private:
        bn::sprite_ptr _sprite;
        bn::fixed_point _velocity;
        Center& _center;
};

#endif