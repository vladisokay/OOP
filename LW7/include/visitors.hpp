#ifndef VISITORS_HPP
#define VISITORS_HPP

#include "npc.hpp"

class Visitor {
public:
    virtual bool visit(const std::shared_ptr<NPC>&) const = 0;
};

class SquirrelVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::SquirrelType:
                result = true;
                break;

            case NpcType::SlaveTraderType:
                result = false;
                break;
            
            case NpcType::KnightType:
                result = false;
                break;
        }
        return result;
    }
};

class SlaveTraderVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::SquirrelType:
                result = true;
                break;

            case NpcType::SlaveTraderType:
                result = false;
                break;
            
            case NpcType::KnightType:
                result = false;
                break;
        }
        return result;
    }
};

class KnightVisitor final : public Visitor {
public:
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::SquirrelType:
                result = false;
                break;

            case NpcType::SlaveTraderType:
                result = true;
                break;
            
            case NpcType::KnightType:
                result = false;
                break;
        }
        return result;
    }
};

class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
        std::shared_ptr<Visitor> result;
        switch (type) {
            case NpcType::KnightType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<KnightVisitor>());
                break;

            case NpcType::SlaveTraderType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<SlaveTraderVisitor>());
                break;

            case NpcType::SquirrelType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<SquirrelVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};

#endif