#include "Game.h"

Game::Game() : window(sf::VideoMode(650, 900), "2048"), board{Board()} // default window size
{
    // read in font
    if (!font.loadFromFile("ClearSans-Regular.ttf"))
    {
        exit(EXIT_FAILURE);
    }

    // test text
    text.setFont(font);
    text.setPosition(0,0);
    text.setCharacterSize(20);
    text.setString("asdf");
    text.setFillColor(sf::Color::Black);
    text.setOutlineColor(sf::Color::Black);

    // set font
    board.setFont(font);
    score.setFont(font);
    highScore.setFont(font);
    newGame.setFont(font);
    run_pause.setFont(font);

    // draw game
    draw();
}

Game::Game(int width, int height) : window(sf::VideoMode(width, height), "2048"), board{Board()} // remove with config file
{
    window.clear(sf::Color(251, 248, 239));
}

Game::~Game()
{
}

bool Game::isAlive()
{
    return window.isOpen();
}

void Game::draw()
{
    window.clear(sf::Color(251, 248, 239));
    window.draw(board);
    window.draw(text);
    window.display();
}

bool Game::pollEvent(sf::Event& event)
{
    return window.pollEvent(event);
}

void Game::processEvent (sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        window.close();
        return;
    case sf::Event::KeyReleased:
        processKeyReleased(event);
        return;
    case sf::Event::MouseButtonReleased:
        processMouseButtonReleased(event);
        return;
    default:
        return;
    }
}

void Game::processKeyReleased (sf::Event event)
{
    board.Move(event.key.code);
}

void Game::processMouseButtonReleased (sf::Event event)
{
    newGame.react(event);
    run_pause.react(event);

    // check if mouse click fell on button
    // call button action
}

