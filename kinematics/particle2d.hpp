#ifndef PHI_KINEMATICS_PARTICLE2D_HPP
#define PHI_KINEMATICS_PARTICLE2D_HPP

#include "../vectors/vector2d.hpp"
#include "../scalars.hpp"
#include <string>
#include <cmath>

namespace phi {
    class Particle2D {
    public:
        std::string name;
        Vector2D position;
        Vector2D velocity = Vector2D(&0.0_m_s, &0.0_m_s);
        Vector2D acceleration = Vector2D(&0.0_m_s2, &0.0_m_s2);
        Vector2D drag = Vector2D(&0.0_m_s2, &0.0_m_s2);
        Mass mass;
        Particle2D(std::string __name, Vector2D __position, Vector2D __velocity, Mass __mass) : name(__name), position(__position), velocity(__velocity), mass(__mass) {}

        void update(Time dt) {
            position = position + (velocity * dt);
            velocity = velocity + (acceleration * dt);
            acceleration = acceleration + (drag / mass);
        }

        void applyForce(Vector2D force) {
            acceleration = acceleration + (force / mass);
        }
    };
}

#endif
