// Copyright (c) 2024 Veganimus Studios. All rights reserved.
//7/29/2024
//CLion
//Aaron
#pragma once
#ifndef CCGSTATBALANCER_CARDCOSTCALCULATOR_H
#define CCGSTATBALANCER_CARDCOSTCALCULATOR_H

#include "CardStats.h"
class CardCostCalculator {

public:

    std::unordered_map<CardType, AttributeWeights> card_type_weights_  ={
            {CardType::None,{0.45,0.25,0.3}},
            {CardType::Hunter, {0.45,0.25,0.3}},
            {CardType::Character,{0.45,0.25,0.3}},
            {CardType::Creature, {0.45,0.25,0.3}},
            {CardType::Enemy,{0.45,0.25,0.3}},
            {CardType::Equipment,{0.25,0.25,0.5}},
            {CardType::Upgrade,{0.25,0.25,0.5}},
            {CardType::Environment,{0.0,0.0,1.0 * 3.0}},
            {CardType::Bounty,{0.0,0.0,1.0 * 3.0}},
            {CardType::Boss,{0.0,0.6 * 2.0,0.4 * 2.0}},
            {CardType::Event,{0.0,0.0,1.0 * 3.0}}
    };


double CalculateCardCost(CardStats& cardStats, const CardType& cardType);

int NormalizeCardCost(double& cost, double normal);

};


#endif //CCGSTATBALANCER_CARDCOSTCALCULATOR_H
