// Copyright (c) 2024 Veganimus Studios. All rights reserved.
//7/29/2024
//CLion
//Aaron

#ifndef CCGSTATBALANCER_CARDSTATS_H
#define CCGSTATBALANCER_CARDSTATS_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <map>

enum class CardType{None, Hunter, Character, Creature, Enemy, Equipment, Upgrade, Environment, Bounty, Boss, Event };

struct AttributeWeights{
    double attack_power_weight;
    double health_points_weight;
    double keyword_weight;
};

class CardStats{

public:
    CardStats(CardType card_type, int attack_power, int health_points, int keyword_values)
    {
        card_type_ = card_type;
        attack_power_ = attack_power;
        health_points_ = health_points;
        keyword_value_ = keyword_values;
    }
    ~CardStats() = default;
    //Getters
    [[nodiscard]] inline CardType Get_Card_Type() const
    {
        return card_type_;
    }


    [[nodiscard]] inline int Get_Attack_Power() const
    {
        return attack_power_;
    }

    [[nodiscard]] inline int Get_Health_Points() const
    {
        return health_points_;
    }
    [[nodiscard]] inline int Get_Keyword_Value() const
    {
        return keyword_value_;
    }
    [[nodiscard]] inline std::string CardTypeToString(CardType cardType) const{
        if(cardTypeToStr.find(cardType) != cardTypeToStr.end()) {
            return cardTypeToStr.at(cardType);
        }
        return "Invalid Card Type";
    }
    //Setters
    void Set_Card_Type(CardType& cT);
    void Set_Attack_Power(int& ap);
    void Set_Health_Points(int& hp);
    void Set_Keyword_Values(int& kV);

private:
    CardType card_type_ = CardType::None;
    int attack_power_ = 0;
    int health_points_ = 0;
    int keyword_value_ = 0;
    const std::map<CardType, std::string> cardTypeToStr {
            {CardType::None, "None"},
            {CardType::Hunter, "Hunter"},
            {CardType::Character, "Character"},
            {CardType::Creature, "Creature"},
            {CardType::Enemy, "Enemy"},
            {CardType::Equipment, "Equipment"},
            {CardType::Upgrade, "Upgrade"},
            {CardType::Environment, "Environment"},
            {CardType::Bounty, "Bounty"},
            {CardType::Boss, "Boss"},
            {CardType::Event, "Event"}
    };
};


#endif //CCGSTATBALANCER_CARDSTATS_H
