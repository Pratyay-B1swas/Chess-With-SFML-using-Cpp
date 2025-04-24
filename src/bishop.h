#ifndef BISHOP_H  //Header guards
#define BISHOP_H

#include <iostream>
#include <vector>
#include "pieces.h"
using namespace std;

class Bishop : public Pieces
{
public:
    Bishop(int color);
    vector<Square> getMoves(Square cells[][8], int x, int y);
    sf::Texture blackBishop;
    sf::Texture whiteBishop;

protected:
private:
};

#endif