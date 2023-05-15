#include "Card_11.h"
#include"Player.h"

Card_11::Card_11(const CellPosition& pos) : Card(pos)
{
	cardNumber = 11;
}

void Card_11::ReadCardParameters(Grid* pGrid)
{

	pGrid->PrintErrorMessage("The amount of coins needed to buy all cells containing this card no. : ");
	price = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	pGrid->PrintErrorMessage("The amount of coins needed to be paid by other players passing this card : ");
	fees = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	pGrid->GetOutput()->ClearStatusBar();
	added = true;
}

void Card_11::transfereCardParameters(Card* pCard)
{
}

void Card_11::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	if (bought)
	{
		pGrid->Station(owner, fees, pPlayer);
		return;
	}

	pGrid->PrintErrorMessage("Please enter 1 if you'll buy all cells containing this card no. or 0 if you'll not");
	bought = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	if (bought)
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - price);
		owner = pPlayer->GetPlayerNum();
	}
}

Card_11 :: ~Card_11(void)
{
}
