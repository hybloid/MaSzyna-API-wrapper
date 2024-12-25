#include "PowerSource.hpp"

namespace godot {

    void PowerSource::_bind_methods() {
        BIND_ENUM_CONSTANT(NoPower)
        BIND_ENUM_CONSTANT(BioPower)
        BIND_ENUM_CONSTANT(MechPower)
        BIND_ENUM_CONSTANT(ElectricPower)
        BIND_ENUM_CONSTANT(SteamPower)
        ADD_SIGNAL(MethodInfo(POWER_SOURCE_CHANGED));
    }

    void PowerSource::update_state(TPowerParameters &p_power_parameters) const {
        p_power_parameters.SourceType = get_source_type();
    }

    void PowerSource::fetch_state(
            const TPowerParameters &p_power_parameters, godot::Dictionary &state, const godot::String &prefix) const {
        state[prefix + godot::String("/source_type")] = get_power_source_name(p_power_parameters.SourceType);
    }

    TPowerType PowerSource::cast(PowerType p) {
        switch (p) {
            case NoPower:
                return TPowerType::NoPower;
            case BioPower:
                return TPowerType::BioPower;
            case MechPower:
                return TPowerType::MechPower;
            case ElectricPower:
                return TPowerType::ElectricPower;
            case SteamPower:
                return TPowerType::SteamPower;
            default:
                return TPowerType::NoPower;
        }
    }

    String PowerSource::to_string(PowerType p) {
        switch (p) {
            case NoPower:
                return "NoPower";
            case BioPower:
                return "BioPower";
            case MechPower:
                return "MechPower";
            case ElectricPower:
                return "ElectricPower";
            case SteamPower:
                return "SteamPower";
            default:
                return "NoPower";
        }
    }

    PowerSource::PowerType PowerSource::from_string(const godot::String &p) {
        if (p == "NoPower") {
            return NoPower;
        } else if (p == "BioPower") {
            return BioPower;
        } else if (p == "MechPower") {
            return MechPower;
        } else if (p == "ElectricPower") {
            return ElectricPower;
        } else if (p == "SteamPower") {
            return SteamPower;
        } else {
            return NoPower;
        }
    }

    String PowerSource::get_power_source_name(const TPowerSource s) {
        switch (s) {
            case TPowerSource::NotDefined:
                return "NotDefined";
            case TPowerSource::InternalSource:
                return "InternalSource";
            case TPowerSource::Transducer:
                return "Transducer";
            case TPowerSource::Generator:
                return "Generator";
            case TPowerSource::Accumulator:
                return "Accumulator";
            case TPowerSource::CurrentCollector:
                return "CurrentCollector";
            case TPowerSource::PowerCable:
                return "PowerCable";
            case TPowerSource::Heater:
                return "Heater";
            case TPowerSource::Main:
                return "Main";
            default:
                return "Unknown";
        }
    };
} // namespace godot
