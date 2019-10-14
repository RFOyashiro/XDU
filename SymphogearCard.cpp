#include "SymphogearCard.h"

SymphogearCard::SymphogearCard()
{
    std::string line;
    std::ifstream Input ("SymphogearCardList.txt");
    std::getline(Input, line);
    while (line != "0") {
        Card card;
        unsigned CardNumber = std::stoi(line);
        std::getline(Input, line);
        card.Name = line;
        std::getline(Input, line);
        card.Element = line;
        std::getline(Input, line);
        card.Rarity = line;
        List.insert(std::make_pair(CardNumber, card));
        std::getline(Input, line);
    }
}
