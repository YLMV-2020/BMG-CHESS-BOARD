#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int size = 56;
Vector2f offset(28, 28);

Sprite sprite[32]; //figures

/*
1-tower 2-horse
3-bishop 4-queen
5-king 6-pawn
*/

int board[8][8];

int checkPiece(char piece)
{
    switch (piece)
    {
    case 'p':
        return 6;
    case 'r':
        return 1;
    case 'b':
        return 3;
    case 'n':
        return 2;
    case 'q':
        return 4;
    case 'k':
        return 5;

    case 'P':
        return -6;
    case 'R':
        return -1;
    case 'B':
        return -3;
    case 'N':
        return -2;
    case 'Q':
        return -4;
    case 'K':
        return -5;

    case '/':
        return 0;
    }

    return piece;
}

void generatorBoard()
{
    int k = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            int n = board[i][j];
            if (!n) continue;
            int x = abs(n) - 1;
            int y = n > 0 ? 1 : 0;
            sprite[k].setTextureRect(IntRect(size * x, size * y, size, size));
            sprite[k].setPosition(size * j, size * i);
            k++;
        }
}

int drawChessBoard(const std::string& initPosition)
{
    int count = 0;

    std::string::const_iterator itBegin = initPosition.begin();
    std::string::const_iterator itEnd = initPosition.end();

    int i = 0, j = 0;

    for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
    {
        int piece = checkPiece(*it);

        if (piece == 0)
        {
            i++;
            j = 0;
            continue;
        }
        else if (piece >= '1' && piece <= '8')
            j += (piece - '0');
        else
        {
            count++;
            board[i][j++] = piece;
        }
    }
    return count;
}

int main()
{
    RenderWindow window(VideoMode(504, 504), "CHESS BOARD");

    /*------------------------------------------------------------------------*/
    std::string initPosition = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    int n = drawChessBoard(initPosition);
    /*------------------------------------------------------------------------*/

    Texture t1, t2;
    t1.loadFromFile("images/figures.png");
    t2.loadFromFile("images/board.png");

    Sprite sBoard(t2);
    for (int i = 0; i < n; i++) sprite[i].setTexture(t1);

    generatorBoard();

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sBoard);
        for (int i = 0; i < 32; i++) sprite[i].move(offset);
        for (int i = 0; i < 32; i++) window.draw(sprite[i]); window.draw(sprite[0]);
        for (int i = 0; i < 32; i++) sprite[i].move(-offset);
        window.display();
    }

    return 0;
}
