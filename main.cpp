#include "CardCostCalculator.h"
#include "CardStats.h"
using namespace std;

#include <map>
#include <string>
#include <iostream>
#include <functional>


CardType Parse_Card_Type(const std::string &cT)
{
    static std::map<std::string, CardType> mapStringToCardType = {
            {"Hunter",      CardType::Hunter},
            {"Character",   CardType::Character},
            {"Creature",    CardType::Creature},
            {"Enemy",       CardType::Enemy},
            {"Equipment",   CardType::Equipment},
            {"Upgrade",     CardType::Upgrade},
            {"Environment", CardType::Environment},
            {"Bounty",      CardType::Bounty},
            {"Boss",        CardType::Boss},
            {"Event",       CardType::Event}
    };

    CardType type = CardType::None;

    // Check if string representation found in the map
    auto it = mapStringToCardType.find(cT);
    if (it != mapStringToCardType.end()) {
        type = it->second;
    }

    std::cout << "Card type set to " << cT << std::endl;
    return type;
}

int Validate_Value(int value, int min_value, int max_value)
{
    value = std::max(min_value, std::min(max_value, value));
    value = (value / 5) * 5; // Round to nearest multiple of 5.
    return value;
}

int Validate_Attack_Power(int value)
{
    int original = value;
    int attack = Validate_Value(value, 0, 50);
    std::cout << "Attack Power adjusted by " << original - attack << std::endl;
    return attack;
}

int Validate_Health_Points(int value)
{
    int original = value;
    int health = Validate_Value(value, 0, 200);
    std::cout << "Health Points adjusted by " << original - health << std::endl;
    return health;
}

int Validate_Keyword_Values(int value)
{
    if(value > 24)
    {
        std::cout << "Your keyword value total exceeds the max of 24. Please adjust." << std::endl;
    }
    return value;
}

double Normalize(double card_weight) {
    double normal = 3.5;
    if (card_weight <= 65.0 && card_weight >= 45.0) {
        normal = 2.0;
    } else if(card_weight < 45.0 && card_weight >= 25.0) {
        normal = 3.0;
    }
    return normal;
}

int GetInput(const std::string& message, const std::function<int(int)>& validator) {
    int input = 0;
    std::cout << message << std::endl;
    std::cin >> input;
    if(input > 0) {
        input = validator(input);
        std::cout << "You have set the value to " << input << std::endl;
    }
    return input;
}

void DisplayCardStats(const CardStats& card, const int& cost) {
    std::cout << "\n=====================================\n";
    std::cout << "  Type: " << card.CardTypeToString(card.Get_Card_Type()) << "       Cost:"<< cost <<"\n";
    std::cout << "-------------------------------------\n";
    std::cout << "  Attack Power: " << card.Get_Attack_Power() << "\n";
    std::cout << "  HP: " << card.Get_Health_Points() << "\n";
    std::cout << "  Keyword Value: " << card.Get_Keyword_Value() << "\n";
    std::cout << "=====================================\n";
}

int main() {
    double card_weight = 0.0;
    char continue_input = ' ';

    while(continue_input != 'x' || card_weight > 65 || continue_input == 'c') {
        std::cout << "Card Types: None, Hunter, Character, Creature, Enemy, Equipment, Upgrade, Environment, Bounty, Boss, Event" << std::endl;
        std::string typeInput;
        std::cin >> typeInput;
        CardType newCardType = Parse_Card_Type(typeInput);
        int cost;
        int attack = GetInput("Please enter the attack power (5 - 50):", Validate_Attack_Power);
        int health = GetInput("Please enter the health points (5 - 200):", Validate_Health_Points);
        int keyword = GetInput("Please enter the total keyword values (1 - 24):", Validate_Keyword_Values);

        CardStats* newCard = new CardStats(newCardType, attack, health, keyword);
        CardCostCalculator* costCalculator = new CardCostCalculator();
        card_weight = costCalculator->CalculateCardCost(*newCard, newCardType);
        if(card_weight > 65) {
            std::cout << "This card is out of the normalization range. Please adjust the attributes." << std::endl;
        } else {
            cost = costCalculator->NormalizeCardCost(card_weight, Normalize(card_weight));
            std::cout << "The cost of this card is " << cost << std::endl;
        }
        DisplayCardStats(*newCard, cost);
        std::cout << "Press 'x' to exit, 'c' to continue:" << std::endl;
        std::cin >> continue_input;

        delete newCard;
        delete costCalculator;
    }

    return 0;
}
