#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    ROCK,
    PAPER,
    SCISSORS
} Hand;

Hand getPlayerHand();
Hand getComputerHand();
void judge(Hand player_hand, Hand computer_hand);

void main()
{
    Hand player_hand = getPlayerHand();
    Hand computer_hand = getComputerHand();
    judge(player_hand, computer_hand);
}

Hand getPlayerHand()
{
    int hand = -1;

    while (hand < 0 || hand > 2)
    {
        printf("出す手を選んで下さい。(0:グー / 1:パー / 2:チョキ)\n");
        scanf("%d", &hand);
    }

    return (Hand)hand;
}

Hand getComputerHand()
{
    srand((unsigned int)time(NULL));
    return (Hand)(rand() % 3);
}

char *toHandText(Hand hand)
{
    switch (hand)
    {
        case ROCK:
            return "グー";
        case PAPER:
            return "パー";
        case SCISSORS:
            return "チョキ";
        default:
            return "";
    }
}

void judge(Hand player_hand, Hand computer_hand)
{
    printf("あなたの手は%sです。\n", toHandText(player_hand));
    printf("コンピュータの手は%sです。\n", toHandText(computer_hand));

    if (player_hand == computer_hand)
    {
        printf("結果は引き分けです。\n");
    }
    else if (
        (player_hand == ROCK && computer_hand == SCISSORS) ||
        (player_hand == PAPER && computer_hand == ROCK) ||
        (player_hand == SCISSORS && computer_hand == PAPER))
    {
        printf("結果はあなたの勝ちです。\n");
    }
    else
    {
        printf("結果はあなたの負けです。\n");
    }
}