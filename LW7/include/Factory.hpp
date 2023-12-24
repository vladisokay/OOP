#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "npc.hpp"
#include "Knight.hpp"
#include "SlaveTrader.hpp"
#include "Squirrel.hpp"
#include "Observer.hpp"

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const NpcType& type, int x, int y) {
        std::shared_ptr<NPC> result;
        if (type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::SquirrelType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(x, y));
                    break;

                case NpcType::SlaveTraderType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<SlaveTrader>(x, y));
                    break;

                case NpcType::KnightType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Knight>(x, y));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> CreateNPC(std::istream& is) {
        std::shared_ptr<NPC> result;
        int type{0};
        if (is >> type && type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::SquirrelType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(is));
                    break;

                case NpcType::SlaveTraderType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<SlaveTrader>(is));
                    break;

                case NpcType::KnightType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Knight>(is));
                    break;

                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }
        
        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};

#endif

