#pragma once

#include <godot_cpp/classes/resource.hpp>
// #include <godot_cpp/godot.hpp>
#include "../../maszyna/McZapkie/MOVER.h"

namespace godot {
    class PowerSource : public Resource {
            GDCLASS(PowerSource, Resource)
        protected:
            PowerSource() = default;
            ~PowerSource() override = default;

            static void _bind_methods();

            /** Returns the internal MOVER.h representaion of the kind of power */
            virtual TPowerSource get_source_type() const = 0;

            /** Updates the MOVER.h representation of the power source */
            virtual void update_mover_internal(TPowerParameters &p_power_parameters) const = 0;

            /** Fetches the state of the power source into the Godot state Dictionary. */
            virtual void fetch_state_internal(
                    const TPowerParameters &p_power_parameters, Dictionary &state, const String &prefix) const = 0;

        public:
            enum PowerType { NoPower, BioPower, MechPower, ElectricPower, SteamPower };

            static TPowerType cast(PowerType p);
            static String to_string(PowerType p);
            static PowerType from_string(const String &p);

            /** Translates internal enum into readable form */
            static String get_power_source_name(TPowerSource s);

            /** Updates the MOVER.h representation of the power source */
            void update_mover(TPowerParameters &p_power_parameters) const;

            /** Fetches the state of the power source into the Godot state Dictionary. */
            void fetch_state(const TPowerParameters &p_power_parameters, Dictionary &state, const String &prefix) const;
    };
} // namespace godot

VARIANT_ENUM_CAST(PowerSource::PowerType);
