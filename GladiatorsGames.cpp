
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "BossGladiator.h"
#include "SamuraiGladiator.h"
void InitText(sf::Text& text, float xpos, float ypos, std::string str, int sizeFont = 60,
	sf::Color menuTextColor = sf::Color::White, int bord = 0, sf::Color borderColor = sf::Color::Black) {
	text.setCharacterSize(sizeFont);
	text.setPosition(xpos, ypos);
	text.setString(str);
	text.setFillColor(menuTextColor);
	text.setOutlineThickness(bord);
	text.setOutlineColor(borderColor);
}
void selectCharacters() {
	sf::RenderWindow selection(sf::VideoMode::getDesktopMode(), L"Выбор персонажа", sf::Style::Fullscreen);
	selection.setVerticalSyncEnabled(true);
	sf::RectangleShape backgroundPlay(sf::Vector2f(1920, 1080));
	sf::Texture background;
	if (!background.loadFromFile("assets/background/selection.jpg")) exit(-1);
	backgroundPlay.setTexture(&background);
}
void gameStart() {
	sf::RenderWindow play(sf::VideoMode::getDesktopMode(), L"Бой", sf::Style::Fullscreen);
	sf::RectangleShape backgroundPlay(sf::Vector2f(1920, 1080));
	play.setVerticalSyncEnabled(true);
	sf::Texture background;
	if (!background.loadFromFile("assets/background/octagon.jpg")) exit(1);
	backgroundPlay.setTexture(&background);
	sf::Clock clock1, clock2;
	BossGladiator boss(0, 200, 9, 9);
	SamuraiGladiator samurai(600, -50, 8, 8);
	//
	while (play.isOpen())
	{
		sf::Event event;
		while (play.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					play.close();
				}
			}
		}
		if (clock1.getElapsedTime().asSeconds() > 0.15f) {
			boss.idle();
			clock1.restart();
		}
		if (clock2.getElapsedTime().asSeconds() > 0.15f) {
			samurai.idle();
			clock2.restart();
		}


		play.clear();
		//play.draw(backgroundPlay);
		boss.draw(play);
		samurai.draw(play);
		play.display();
	}
}



int main()
{
	setlocale(LC_ALL, "RUS");
	sf::RenderWindow window;

	window.create(sf::VideoMode::getDesktopMode(), L"Моя игра", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);
	window.setVerticalSyncEnabled(true);
	float width = sf::VideoMode::getDesktopMode().width;
	float height = sf::VideoMode::getDesktopMode().height;

	sf::RectangleShape background(sf::Vector2f(width, height));
	sf::Texture textureWindow;
	if (!textureWindow.loadFromFile("assets/background/colosseum.jpg")) return 4;
	background.setTexture(&textureWindow);

	sf::Font font;
	if (!font.loadFromFile("fonts/lifehack-sans-3.otf")) return 5;
	sf::Text Titul;
	Titul.setFont(font);
	InitText(Titul, 700, 75, "GLADIATORS", 150, sf::Color(237, 147, 0), 3);
	sf::String nameMenu[]{ L"Старт",L"Выход" };
	
	Menu menu(window, 950, 350, 2, nameMenu, 150, 300);
	menu.setColorTextMenu(sf::Color(237, 147, 0), sf::Color::Red, sf::Color::Black);

	menu.alignMenu(-140,0);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					menu.moveUp();
				}
				if (event.key.code == sf::Keyboard::Down) {
					menu.moveDown();
				}
				if (event.key.code == sf::Keyboard::Return) {
					switch (menu.getSelectedMenuNumber()) {
					case 0: 
						gameStart();
						break;
					case 1:
						exit(1);
					}
				}
			}
		}
		window.clear();
		window.draw(background);
		window.draw(Titul);
		menu.draw();
		window.display();
	}
	
}

