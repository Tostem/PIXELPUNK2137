#include "Game.h"

void Game::initWindow()
{
	this->okno_gry = new sf::RenderWindow(sf::VideoMode(800, 600), "Cyber Drunk", sf::Style::Close | sf::Style::Titlebar);
}

Game::~Game()
{
	delete this->okno_gry;
}

Game::Game()
{

}

void Game::updateSFMLEvents()
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::run()
{

}