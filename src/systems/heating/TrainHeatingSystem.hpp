#pragma once

#include <godot_cpp/classes/node.hpp>
#include "../../core/TrainPart.hpp"
#include "../../maszyna/McZapkie/MOVER.h"
#include "../../mover_util/power_source/Mod.hpp"

namespace godot {
    class TrainHeatingSystem : public TrainPart {
            GDCLASS(TrainHeatingSystem, TrainPart)

            Ref<PowerSource> power_source;
            Ref<PowerSource> alternative_power_source;

            static void _bind_methods();
            void on_power_source_change();

            void _do_update_internal_mover(TMoverParameters *mover) override;
            void _do_fetch_state_from_mover(TMoverParameters *mover, Dictionary &state) override;
            void _register_commands() override { /** TBD */ };
            void _unregister_commands() override { /** TBD */ };

        protected:
        public:
            void _enter_tree() override;
            void _ready() override;
            // getters and setters
            void set_power_source(Ref<PowerSource> p_power_source);
            Ref<PowerSource> get_power_source() const;
            void set_alternative_power_source(Ref<PowerSource> p_alternative_power_source);
            Ref<PowerSource> get_alternative_power_source() const;
    };

} // namespace godot
