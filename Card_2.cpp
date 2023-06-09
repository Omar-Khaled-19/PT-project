#include "Card_2.h"

Card_2::Card_2(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

void Card_2::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 2 : Move to next ladder if exist. ");

	Ladder* pLadder = NULL;
	pLadder = pGrid->GetNextLadder(position);

	if (!pLadder)
		return;

	pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
	pLadder->Apply(pGrid, pPlayer);



}

Card_2::~Card_2()
{
}
