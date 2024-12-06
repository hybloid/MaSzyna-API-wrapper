//
// Created by karol on 03.12.2024.
//

#pragma once
#include <godot_cpp/classes/node.hpp>
#include "../core/TrainPart.hpp"
#include "../engines/TrainEngine.hpp"

namespace godot {
    class TrainController;
    class TrainLightning final : public TrainPart {
            GDCLASS(TrainLightning, TrainPart);

        private:
            static void _bind_methods();
        protected:
            void _do_update_internal_mover(TMoverParameters *mover) override;
            void _do_fetch_state_from_mover(TMoverParameters *mover, Dictionary &state) override;
            void _do_fetch_config_from_mover(TMoverParameters *mover, Dictionary &config) override;
            void _register_commands() override;
            void _unregister_commands() override;
        public:
            /**
             * Generator for light power. Default value taken from internal mover
             */
            TrainEngine::TrainPowerSource light_source = TrainEngine::TrainPowerSource::POWER_SOURCE_GENERATOR;
            /**
             * Engine type of the generator
             */
            TrainEngine::TrainEngineType generator_engine = TrainEngine::TrainEngineType::ENGINE_TYPE_MAIN;
            /**
             * Accumulator capacity for an alternative light source. Default value from internal mover
             */
            double max_accumulator_voltage = 0.0;
            /**
             * Alternative generator for light power. Default value taken from internal mover
             */
            TrainEngine::TrainPowerSource alternative_light_source = TrainEngine::TrainPowerSource::POWER_SOURCE_ACCUMULATOR;
            /**
             * Accumulator capacity for an alternative light power source. Default value from internal mover
             */
            double alternative_max_voltage = 24.0;
            /**
             * Accumulator capacity for an alternative light power source. Default value from internal mover
             */
            double alternative_light_capacity = 495.0;
            /**
             * Accumulator recharge source for an alternative light power source. Default value from internal mover
             */
            TrainEngine::TrainPowerSource accumulator_recharge_source = TrainEngine::TrainPowerSource::POWER_SOURCE_GENERATOR;
            TrainLightning();
            ~TrainLightning() override = default;

            void set_light_source(TrainEngine::TrainPowerSource p_light_source);
            TrainEngine::TrainPowerSource get_light_source() const;
            void set_generator_engine(TrainEngine::TrainEngineType p_generator_engine);
            TrainEngine::TrainEngineType get_generator_engine() const;
            void set_max_accumulator_voltage(double p_max_accumulator_voltage);
            double get_max_accumulator_voltage() const;
            void set_alternative_light_source(TrainEngine::TrainPowerSource p_light_source);
            TrainEngine::TrainPowerSource get_alternative_light_source() const;
            void set_alternative_max_voltage(double p_max_accumulator_voltage);
            double get_alternative_max_voltage() const;
            void set_alternative_light_capacity(double p_max_accumulator_voltage);
            double get_alternative_light_capacity() const;
            void set_accumulator_recharge_source(TrainEngine::TrainPowerSource p_accumulator_recharge_source);
            TrainEngine::TrainPowerSource get_accumulator_recharge_source() const;
    };
} // namespace godot
