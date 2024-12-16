#pragma once

#include <godot_cpp/classes/node.hpp>
#include "../../core/TrainPart.hpp"
#include "../../maszyna/McZapkie/MOVER.h"

namespace godot {
    class TrainHeatingSystem : public TrainPart {
            GDCLASS(TrainHeatingSystem, TrainPart)

            static void _bind_methods();

        protected:
            void _do_update_internal_mover(TMoverParameters *mover) override;
            void _do_fetch_state_from_mover(TMoverParameters *mover, Dictionary &state) override;
            void _register_commands() override;
            void _unregister_commands() override;

        public:
            TrainHeatingSystem() = default;
            ~TrainHeatingSystem() override = default;
    };

} // namespace godot
