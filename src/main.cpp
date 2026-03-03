#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>

#include "bn_sprite_items_dot.h"
#include "movement.h"
#include "Center.h"
#include "Orbiter.h"

// Maximum number of orbiters allowed on the screen
static constexpr int MAX_ORBITERS = 30;

int main()
{
    bn::core::init();

    Center center = Center({30, 40}, .05, 2);
    bn::vector<Orbiter, MAX_ORBITERS> orbiters = {};

    // Player-adjustable spawn settings:
    bn::fixed_point spawn_position = {0, 0};
    bn::fixed_point spawn_velocity = {0, 5};

    // Visual preview of where the next orbiter will spawn:
    bn::sprite_ptr spawn_preview = bn::sprite_items::dot.create_sprite(spawn_position);

    while(true)
    {
        // Hold L + D-pad to adjust spawn position:
        if(bn::keypad::l_held())
        {
            if(bn::keypad::left_held())
            {
                spawn_position.set_x(spawn_position.x() - 1);
            }
            if(bn::keypad::right_held())
            {
                spawn_position.set_x(spawn_position.x() + 1);
            }
            if(bn::keypad::up_held())
            {
                spawn_position.set_y(spawn_position.y() - 1);
            }
            if(bn::keypad::down_held())
            {
                spawn_position.set_y(spawn_position.y() + 1);
            }
        }

        // Hold R + D-pad to adjust spawn velocity:
        if(bn::keypad::r_held())
        {
            if(bn::keypad::left_held())
            {
                spawn_velocity.set_x(spawn_velocity.x() - 0.25);
            }
            if(bn::keypad::right_held())
            {
                spawn_velocity.set_x(spawn_velocity.x() + 0.25);
            }
            if(bn::keypad::up_held())
            {
                spawn_velocity.set_y(spawn_velocity.y() - 0.25);
            }
            if(bn::keypad::down_held())
            {
                spawn_velocity.set_y(spawn_velocity.y() + 0.25);
            }
        }

        // Update preview sprite position every frame:
        spawn_preview.set_position(spawn_position);

        // Add an orbiter when A is pressed if there's room:
        if(bn::keypad::a_pressed())
        {
            if(orbiters.size() < MAX_ORBITERS)
            {
                orbiters.push_back(Orbiter(spawn_position, spawn_velocity, center));
            }
        }

        // Remove an orbiter when B is pressed if there's at least one:
        if(bn::keypad::b_pressed())
        {
            if(orbiters.size() > 0)
            {
                orbiters.pop_back();
            }
        }

        center.update();

        for(Orbiter& orbiter : orbiters)
        {
            orbiter.update();
        }

        bn::core::update();
    }
}