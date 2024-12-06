#pragma once
#include <godot_cpp/classes/node.hpp>
#include "../core/TrainPart.hpp"
#include "../maszyna/McZapkie/MOVER.h"


namespace godot {
    class TrainController;
    class TrainEngine : public TrainPart {
            GDCLASS(TrainEngine, TrainPart)
        public:
            static void _bind_methods();
            TypedArray<Dictionary> motor_param_table;

            enum TrainEngineType {
                ENGINE_TYPE_NONE,
                ENGINE_TYPE_DUMB,
                ENGINE_TYPE_WHEELS_DRIVEN,
                ENGINE_TYPE_ELECTRIC_SERIES_MOTOR,
                ENGINE_TYPE_ELECTRIC_INDUCTION_MOTOR,
                ENGINE_TYPE_DIESEL,
                ENGINE_TYPE_STEAM,
                ENGINE_TYPE_DIESEL_ELECTRIC,
                ENGINE_TYPE_MAIN
            };

            enum TrainPowerSource {
                POWER_SOURCE_NOT_DEFINED,
                POWER_SOURCE_INTERNAL,
                POWER_SOURCE_TRANSDUCER,
                POWER_SOURCE_GENERATOR,
                POWER_SOURCE_ACCUMULATOR,
                POWER_SOURCE_CURRENTCOLLECTOR,
                POWER_SOURCE_POWERCABLE,
                POWER_SOURCE_HEATER,
                POWER_SOURCE_MAIN
            };

            enum TrainPowerType {
                POWER_TYPE_NONE,
                POWER_TYPE_BIO,
                POWER_TYPE_MECH,
                POWER_TYPE_ELECTRIC,
                POWER_TYPE_STEAM
            };

        protected:
            virtual TrainEngineType get_engine_type() = 0;
            void _do_update_internal_mover(TMoverParameters *mover) override;
            void _do_fetch_state_from_mover(TMoverParameters *mover, Dictionary &state) override;
            void _do_fetch_config_from_mover(TMoverParameters *mover, Dictionary &config) override;
            void _register_commands() override;
            void _unregister_commands() override;

        public:
            TypedArray<Dictionary> get_motor_param_table() const;
            void set_motor_param_table(const TypedArray<Dictionary> &p_wwlist);
            void main_switch(bool p_enabled);

            TrainEngine();
            ~TrainEngine() override = default;
    };
} // namespace godot
VARIANT_ENUM_CAST(TrainEngine::TrainEngineType);
VARIANT_ENUM_CAST(TrainEngine::TrainPowerSource);
VARIANT_ENUM_CAST(TrainEngine::TrainPowerType);