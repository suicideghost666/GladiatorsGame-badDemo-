#ifndef _MENU_H_
#define _MENU_H_
#include "SFML/Graphics.hpp"
class Menu {
private:
	float x, y;
	int menuGap, menuMaxItems, fontSize, selectedItem;
	sf::Font font;
	sf::Text* mainMenu;
	sf::Color menuTextColor = sf::Color(237, 147, 0);
	sf::Color chosenItemColor = sf::Color::Red;
	sf::Color borderColor = sf::Color::Black;
	void setInitText(sf::Text& text, sf::String str, float x, float y) {
		text.setFont(font);
		text.setFillColor(menuTextColor);
		text.setString(str);
		text.setCharacterSize(fontSize);
		text.setOutlineThickness(3);
		text.setOutlineColor(borderColor);
		text.setPosition(x, y);
	};
	sf::RenderWindow& window;
public:
	Menu(sf::RenderWindow& window, float x, float y,
		int index, sf::String names[], int fontSize = 60, int step = 80)
		: window(window),x(x),y(y),fontSize(fontSize), menuGap(step) {
		if (!font.loadFromFile("fonts/lifehack-sans-3.otf")) exit(32);
		menuMaxItems = index;
		mainMenu = new sf::Text[menuMaxItems];
		for (int i = 0, ypos = this->y; i < menuMaxItems; i++, ypos += menuGap) {
			setInitText(mainMenu[i], names[i], this->x, ypos);
			mainMenu[selectedItem].setFillColor(menuTextColor);
			std::cout << "constructor" << mainMenu[i].getPosition().y << std::endl;
		}
		mainMenu[0].setFillColor(chosenItemColor);
	}
	~Menu() {
		delete[] mainMenu;
	}
	void draw() {
		for (int i = 0; i < menuMaxItems; i++) window.draw(mainMenu[i]);
	}
	void moveUp() {
		selectedItem--;
		if (selectedItem >= 0) {
			mainMenu[selectedItem].setFillColor(chosenItemColor);
			mainMenu[selectedItem + 1].setFillColor(menuTextColor);

		} 
		else {
			mainMenu[0].setFillColor(menuTextColor);
			selectedItem = menuMaxItems - 1;
			mainMenu[selectedItem].setFillColor(chosenItemColor);
		}

	}
	void moveDown() {
		selectedItem++;
		if (selectedItem < menuMaxItems) {
			mainMenu[selectedItem - 1].setFillColor(menuTextColor);
			mainMenu[selectedItem].setFillColor(chosenItemColor);

		}
		else {
			mainMenu[menuMaxItems - 1].setFillColor(menuTextColor);
			selectedItem = 0;
			mainMenu[selectedItem].setFillColor(chosenItemColor);
		}
	}
	void setColorTextMenu(sf::Color menuTextColor, sf::Color chosenItemColor, sf::Color borderColor) {
		this->menuTextColor = menuTextColor;
		this->chosenItemColor = chosenItemColor;
		this->borderColor = borderColor;
	}
	void alignMenu(int x, int y) {
		for (int i = 0; i < menuMaxItems; i++) {
			std::cout << mainMenu[i].getPosition().y;
			mainMenu[i].setPosition(mainMenu[i].getPosition().x + x, mainMenu[i].getPosition().y + y);
		}

	}
	int getSelectedMenuNumber() {
		return selectedItem;
	}
};
#endif // !_MENU_H_
