// Copyright (c) 2024 Veganimus Studios. All rights reserved.
//7/29/2024
//CLion
//Aaron

#include "CardCostCalculator.h"
#include <iostream>


double CardCostCalculator::CalculateCardCost(CardStats& cardStats, const CardType& cardType)
{
    //Get the weights for the specified card type.
    const AttributeWeights& weights =  card_type_weights_[cardType];
    std::cout << "Weights = " << card_type_weights_[cardType].attack_power_weight << "," << card_type_weights_[cardType].health_points_weight<< std::endl;
    //Calculate weighted sum.
    double weight_sum = (weights.attack_power_weight * cardStats.Get_Attack_Power()) +
            (weights.health_points_weight * cardStats.Get_Health_Points()) +
            (weights.keyword_weight * cardStats.Get_Keyword_Value());


    std::cout << "Pre-Normalized cost is :" << weight_sum << std::endl;
   return weight_sum;
}

int CardCostCalculator::NormalizeCardCost(double& weight_sum, double normal)
{
    //Normalize the cost (maximum of 12)
    double normalization_factor = normal;
    double normalized_cost = std::min(12.0, weight_sum/normalization_factor);
    normalized_cost = std::max(1, std::min(12, (int)normalized_cost));
    return (int)normalized_cost;
}
