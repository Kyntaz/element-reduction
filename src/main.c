#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned int length;
    char* values;
} Cards;

typedef struct {
    Cards cards;
    unsigned int i1, i2;
} CardsPairIter;

Cards readCards() {
    Cards cards;
    scanf("%d", &(cards.length));
    cards.values = (char*) malloc(cards.length);
    for (int i = 0; i < cards.length; i++) {
        cards.values[i] = getchar();
    }
    return cards;
}

void writeCards(Cards cards) {
    for (int i = 0; i < cards.length; i++) {
        if (cards.values[i] != 0) {
            putchar(cards.values[i]);
        }
    }
}

void freeCards(Cards cards) {
    free(cards.values);
}

CardsPairIter makeCardsPairIter(Cards cards) {
    CardsPairIter iter = { cards, 0, 0 };
    return iter;
}

void getCards(CardsPairIter iter, char* card1, char* card2) {
    *card1 = iter.cards.values[iter.i1];
    *card2 = iter.cards.values[iter.i2];
}

bool canReduce(char card1, char card2) {
    return (card1 == 'F' && card2 == 'W') ||
        (card1 == 'W' && card2 == 'F') ||
        (card1 == 'E' && card2 == 'A') ||
        (card1 == 'A' && card2 == 'E');
}

bool tryReducePair(CardsPairIter iter) {
    char card1, card2;
    getCards(iter, &card1, &card2);
    if (canReduce(card1, card2)) {
        iter.cards.values[iter.i1] = 0;
        iter.cards.values[iter.i2] = 0;
        return true;
    }
    return false;
}

void advanceI2(CardsPairIter* iter) {
    while (iter->i2 < iter->cards.length && iter->cards.values[iter->i2] == 0) {
        iter->i2++;
    }
}

bool next(CardsPairIter* iter) {
    advanceI2(iter);
    iter->i1 = iter->i2;
    iter->i2++;
    advanceI2(iter);
    return iter->i2 < iter->cards.length;
}

bool tryReduce(Cards cards) {
    CardsPairIter iter = makeCardsPairIter(cards);
    bool hasReduced = 0;
    while (next(&iter)) {
        hasReduced = hasReduced || tryReducePair(iter);
    }
    return hasReduced;
}

void reduce(Cards cards) {
    while (tryReduce(cards)) {}
}

int main() {
    Cards cards = readCards();
    reduce(cards);
    writeCards(cards);
    freeCards(cards);
    return 0;
}
