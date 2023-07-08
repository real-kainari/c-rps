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
        printf("�o�����I��ŉ������B(0:�O�[ / 1:�p�[ / 2:�`���L)\n");
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
            return "�O�[";
        case PAPER:
            return "�p�[";
        case SCISSORS:
            return "�`���L";
        default:
            return "";
    }
}

void judge(Hand player_hand, Hand computer_hand)
{
    printf("���Ȃ��̎��%s�ł��B\n", toHandText(player_hand));
    printf("�R���s���[�^�̎��%s�ł��B\n", toHandText(computer_hand));

    if (player_hand == computer_hand)
    {
        printf("���ʂ͈��������ł��B\n");
    }
    else if (
        (player_hand == ROCK && computer_hand == SCISSORS) ||
        (player_hand == PAPER && computer_hand == ROCK) ||
        (player_hand == SCISSORS && computer_hand == PAPER))
    {
        printf("���ʂ͂��Ȃ��̏����ł��B\n");
    }
    else
    {
        printf("���ʂ͂��Ȃ��̕����ł��B\n");
    }
}