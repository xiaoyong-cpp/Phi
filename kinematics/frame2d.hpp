#ifndef PHI_KINEMATICS_FRAME2D_HPP
#define PHI_KINEMATICS_FRAME2D_HPP

#include "../vectors/vector2d.hpp"
#include "particle2d.hpp"
#include "../scalars.hpp"
#include <vector>
#include <map>
#include <string>

namespace phi {
    class Frame2D {
    private:
        struct RelativeInformation {
            Vector2D offset;
            Pure angle;
            Frame2D* target;

            RelativeInformation() = default;
            RelativeInformation(Vector2D offset, Pure angle, Frame2D* target) : offset(offset), angle(angle), target(target) {}
        };

        std::map<std::string, RelativeInformation> relative_informations;
    public:
        std::string name;
        std::map<std::string, Particle2D*> particles;
        Frame2D() = default;
        Frame2D* getRelative(const std::string& name) {
            return relative_informations[name].target;
        }

        void addRelative(Vector2D offset, Pure angle, Frame2D* target) {
            relative_informations[target->name] = RelativeInformation(offset, angle, target);
            target->relative_informations[name] = RelativeInformation(-offset, -angle, this);
        }
    };
}

#endif
