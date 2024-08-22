// Copyright (c) 2024 Veganimus Studios. All rights reserved.
//7/29/2024
//CLion
//Aaron

#include "CardStats.h"
#include <iostream>

void CardStats::Set_Card_Type(CardType& cT)
{
    //CardType{None, Hunter, Character, Creature, Enemy, Equipment, Upgrade, Environment, Bounty, Boss, Event };
    card_type_ = cT;
}

void CardStats::Set_Attack_Power(int& ap)
{
    attack_power_ = ap;
}

void CardStats::Set_Health_Points(int& hp)
{
    health_points_ = hp;
}

void CardStats::Set_Keyword_Values(int& kV)
{
   keyword_value_ = kV;
}

