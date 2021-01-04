#include <iostream>
#include "Vec2.h"

class Polynomio
{
public:
    class Block
    {
    public:
        Vec2 pos;
    };

public:
    Block blocks[4];
    Vec2 midPos;
    void Rotate();
};

void Polynomio::Rotate()
{
    for(int i = 0; i < 4; ++i)
    {
        if(blocks[i].pos.y == midPos.y && blocks[i].pos.x == midPos.x)
        {
            continue;
        }
        Vec2 relVec = blocks[i].pos - midPos;

        Vec2 rotVec( 0 * relVec.x + 1 * relVec.y, -1 * relVec.x + 0 * relVec.y );

        blocks[i].pos = midPos + rotVec;
    }
}

void Print(const Polynomio& poly, const int& width, const int& height)
{
    for(int y = 0; y < height; ++y)
    {
        std::cout << '0';
        for(int x = 0; x < width; ++x)
        {
            bool hasPrinted = false;
            for(int i = 0; i < 4; ++i)
            {
                if(poly.blocks[i].pos.y == y && poly.blocks[i].pos.x == x)
                {
                    std::cout << 'b';
                    hasPrinted = true;
                }
            }
            if(!hasPrinted)
            {
                std::cout << ' ';
            }
        }
        std::cout << '0';
        std::cout << std::endl;
    }
    for(int i = 0 ; i < width + 2; ++i)
    {
        std::cout << '0';
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    int height = 20, width = 10;
    Polynomio poly;
    //std::vector<char> map(10 * 20, ' ');

    // L 모양
    poly.blocks[0].pos.x = width / 2;
    poly.blocks[0].pos.y = 0;

    poly.blocks[1].pos.x = width / 2;
    poly.blocks[1].pos.y = 1;

    poly.blocks[2].pos.x = width / 2;
    poly.blocks[2].pos.y = 2;

    poly.blocks[3].pos.x = width / 2 + 1;
    poly.blocks[3].pos.y = 2;

    poly.midPos.x = poly.blocks[1].pos.x;
    poly.midPos.y = poly.blocks[1].pos.y;


    Print(poly, width, height);
    
    poly.Rotate();
    Print(poly, width, height);

    poly.Rotate();
    Print(poly, width, height);

    poly.Rotate();
    Print(poly, width, height);

    poly.Rotate();
    Print(poly, width, height);

    return 0;
}