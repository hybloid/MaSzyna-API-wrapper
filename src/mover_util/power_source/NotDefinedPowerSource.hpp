#pragma once

#include "PowerSource.hpp"

namespace godot {
    class NotDefinedPowerSource : public PowerSource {
            GDCLASS(NotDefinedPowerSource, PowerSource)
        public:
            PowerType power_type = NoPower;

        protected:
            static void _bind_methods() {
                ClassDB::bind_method(D_METHOD("get_power_type"), &NotDefinedPowerSource::get_power_type);
                ClassDB::bind_method(D_METHOD("set_power_type", "value"), &NotDefinedPowerSource::set_power_type);
                ADD_PROPERTY(
                        PropertyInfo(
                                Variant::INT, "power_type", PROPERTY_HINT_ENUM,
                                "NoPower,BioPower,MechPower,ElectricPower,SteamPower"),
                        "set_power_type", "get_power_type");
            };

            TPowerSource get_source_type() const override {
                return TPowerSource::NotDefined;
            }

            void update_mover_internal(TPowerParameters &p_power_parameters) const override {
                p_power_parameters.PowerType = PowerSource::cast(power_type);
            }

            void fetch_state_internal(
                    const TPowerParameters &p_power_parameters, godot::Dictionary &state,
                    const godot::String &prefix) const override {
                state[prefix + godot::String("/power_type")] = PowerSource::to_string(power_type);
            }

        public:
            // GETTERS AND SETTERS
            void set_power_type(const PowerType p_power_type) {
                power_type = p_power_type;
            }

            PowerType get_power_type() const {
                return power_type;
            }
    };
} // namespace godot
