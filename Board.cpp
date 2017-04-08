#include "Board.h"

Board::Board()
{
    board.setFillColor(sf::Color(187, 173, 160)); // magic
    board.setPosition(50,300); // magic
    board.setSize(sf::Vector2f(550,550)); // magic
    board.setCornerPointCount(20);

    tilePadding = board.getSize().x/45; // (width = 4 tiles + 5 padding, 10 padding = 1 tile
    tileWidth = (board.getSize().x - tilePadding)/4 - tilePadding;
    sf::Vector2f tileSize(tileWidth, tileWidth);
    board.setCornersRadius(tilePadding/1.5);

    for (double ii{0}; ii<4; ++ii)
    {
        for (double jj{0}; jj<4; ++jj)
        {
            sf::Vector2f position(
                (board.getPosition().x + tilePadding) + (tileWidth + tilePadding)*jj,
                (board.getPosition().y + tilePadding) + (tileWidth + tilePadding)*ii
            );
            boardspaces.push_back(Boardspace(position, tileSize));
            tiles.push_back(Tile(position, tileSize, std::tuple<int,int>(ii,jj)));
        }
    }

    this->SpawnTile();
    this->SpawnTile();
}

Board::~Board()
{
    //dtor
}

void Board::setFont(sf::Font& font)
{
    for (Tile tile : tiles)
        tile.setFont(font);
}

void Board::Move (int direction)
{
    switch (direction) {
    case Left:
        break;
    case Dir::Right:
        break;
    case Dir::Up:
        break;
    case Dir::Down:
        break;
    }
}

void Board::SpawnTile ()
{
    // check for empty tiles
    this->checkForLoss();

    // select a tile where visible==false
    int tileNum = RandomInt(0,15);
    while (tiles[tileNum].getVisible())
        tileNum = RandomInt(0,15);

    // set text to 2 or 4 (90/10)
    if (RandomInt(0,9) == 9)
        tiles[tileNum].setText("4");
    else
        tiles[tileNum].setText("2");

    // set visible
    tiles[tileNum].setVisible(true);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(board, states);

    for (Boardspace space : boardspaces)
        target.draw(space, states);

    for (Tile tile : tiles)
        if (tile.getVisible())
            target.draw(tile, states);
}

int Board::RandomInt(int min, int max) // make util.cpp
{
    static std::random_device rd;
    static std::default_random_engine gen(rd());
    static std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

bool Board::checkForLoss()
{
    // should probably split these because you'll only every have to check for one or the other
    // check for empty spaces
    // check for ability to move
    return false;
}
