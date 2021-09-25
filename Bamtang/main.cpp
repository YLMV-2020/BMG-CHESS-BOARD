#include <SFML/Graphics.hpp>

using namespace sf;

int size = 56;
Vector2f offset(28, 28);

Sprite f[32]; //figures

/*
1-tower 2-horse
3-bishop 4-queen
5-king 6-pawn
*/

int board[8][8]{ 0 };

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

void loadPosition()
{
    int k = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            int n = board[i][j];
            if (!n) continue;
            int x = abs(n) - 1;
            int y = n > 0 ? 1 : 0;
            f[k].setTextureRect(IntRect(size * x, size * y, size, size));
            f[k].setPosition(size * j, size * i);
            k++;
        }
}

void drawChessBoard(const std::string& initPosition)
{
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
        else if (isdigit(piece))
            for (; j < (piece - '0'); j++)
                board[i][j] = 0;
        else
            board[i][j++] = piece;
    }

    loadPosition();
}

int main()
{
    RenderWindow window(VideoMode(504, 504), "CHESS BOARD");

    Texture t1, t2;
    t1.loadFromFile("images/figures.png");
    t2.loadFromFile("images/board.png");

    for (int i = 0; i < 32; i++) f[i].setTexture(t1);
    Sprite sBoard(t2);

    /*------------------------------------------------------------------------*/
    std::string initPosition = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    drawChessBoard(initPosition);
    /*------------------------------------------------------------------------*/

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
       
        ////// draw  ///////
        window.clear();
        window.draw(sBoard);
        for (int i = 0; i < 32; i++) f[i].move(offset);
        for (int i = 0; i < 32; i++) window.draw(f[i]); window.draw(f[0]);
        for (int i = 0; i < 32; i++) f[i].move(-offset);
        window.display();
    }

    return 0;
}
