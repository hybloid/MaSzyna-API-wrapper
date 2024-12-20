#pragma once

#include "PowerSource.hpp"

namespace godot {
    class InternalPowerSource : public PowerSource {
            GDCLASS(InternalPowerSource, PowerSource)
        public:
            TPowerType power_type = TPowerType::NoPower;

        protected:
            static void _bind_methods() { /** TBD */ };
            TPowerSource get_source_type() const override {
                return TPowerSource::InternalSource;
            }

            void update_mover_internal(TPowerParameters &p_power_parameters) const override {
                p_power_parameters.PowerType = power_type;
            }

            void fetch_state_internal(
                    const TPowerParameters &p_power_parameters, godot::Dictionary &state,
                    const godot::String &prefix) const override {
                state[prefix + godot::String("/power_type")] = static_cast<int>(p_power_parameters.PowerType);
                // PowerSouce::get_power_source_name(p_power_parameters.SourceType);
            }
    };

} // namespace godot
