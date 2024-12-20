#pragma once

#include "PowerSource.hpp"

namespace godot {
    /** https://en.wikipedia.org/wiki/Transducer */
    /** Note that's propably deprecated class, as current MaSzyna assets doesn't contain any fiz file with this kind of
     * power source */
    class TransducerPowerSource : public PowerSource {
            GDCLASS(TransducerPowerSource, PowerSource)

            // TODO: check default value
            double input_voltage = 0.0f;

        protected:
            static void _bind_methods();

            TPowerSource get_source_type() const override;

            void update_mover_internal(TPowerParameters &p_power_parameters) const override;
            void fetch_state_internal(
                    const TPowerParameters &p_power_parameters, godot::Dictionary &state,
                    const godot::String &prefix) const override;

        public:
            // GETTERS AND SETTERS
            double get_input_voltage() const;
            void set_input_voltage(double p_input_voltage);
    };
} // namespace godot
