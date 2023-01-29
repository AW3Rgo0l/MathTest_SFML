#pragma once

/////////// Start menu function

void menu() {

	// main window
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Menu", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	// loading arrow and hand cursors 
	sf::Cursor cursorArrow, cursorHand;
	if (!cursorArrow.loadFromSystem(sf::Cursor::Arrow)) {
		std::cout << "Cursor loading error" << std::endl;
	}

	if (!cursorHand.loadFromSystem(sf::Cursor::Hand)) {
		std::cout << "Cursor loading error" << std::endl;
	}

	// loading  and setting icon for app
	sf::Image icon;
	if (!icon.loadFromFile("images/icon.png")) {
		std::cout << "Icon loading error" << std::endl;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	// loading textures for buttons and other sprites
	sf::Texture quitButton, startButton, measureTexture, headerTexture, backgroundTexture;
	if (!backgroundTexture.loadFromFile("images/Background.jpg")) {
		std::cout << "Texture loading error" << std::endl;
	}
	if (!headerTexture.loadFromFile("images/HeaderMenu.png")) {
		std::cout << "Texture loading error" << std::endl;
	}
	if (!measureTexture.loadFromFile("images/Measure.png")) {
		std::cout << "Texture loading error" << std::endl;
	}
	if (!quitButton.loadFromFile("images/menuQuit.png")) {
		std::cout << "Texture loading error" << std::endl;
	}
	if (!startButton.loadFromFile("images/menuStartTest.png")) {
		std::cout << "Texture loading error" << std::endl;
	}

	// crating sprites and setting for buttons
	sf::Sprite quitButtonSprite, startButtonSprite, measureSprite, headerSprite, backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 0);
	headerSprite.setTexture(headerTexture);
	headerSprite.setPosition(110, 0);
	measureSprite.setTexture(measureTexture);
	measureSprite.setPosition(-170, 410);
	quitButtonSprite.setTexture(quitButton);
	quitButtonSprite.setPosition(370, 500);
	startButtonSprite.setTexture(startButton);
	startButtonSprite.setPosition(100, 200);

	// creating two rectangles for buttons
	sf::IntRect quitButtonRect(580, 525, 180, 57);
	sf::IntRect startButtonRect(200, 230, 396, 53);

	// variable to understanding which button pressed
	int chooseNum = 0;

	// main loop
	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			window.setMouseCursor(cursorArrow);

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			startButtonSprite.setColor(sf::Color::White);
			quitButtonSprite.setColor(sf::Color::White);
			headerSprite.setColor(sf::Color::White);
			measureSprite.setColor(sf::Color::White);

			chooseNum = 0;

			// window closed by user
			if (event.type == sf::Event::Closed) {
				exit(0);
			}

			// if user put the cursor on quit button
			if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
				quitButtonSprite.setColor(sf::Color::Red);
				window.setMouseCursor(cursorHand);
				chooseNum = 1;
			}

			// if user put the cursor on start button
			if (startButtonRect.contains(mousePos.x, mousePos.y)) {
				startButtonSprite.setColor(sf::Color::Green);
				window.setMouseCursor(cursorHand);
				chooseNum = 2;
			}

			// if user pressed the left mouse button while cursor is on one of the two buttons
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (chooseNum == 1) {
					exit(0); // quit button pressed
				}
				if (chooseNum == 2) {
					window.close(); // start button pressed
				}
			}

		}
		
		window.draw(backgroundSprite);
		window.draw(headerSprite);
		window.draw(measureSprite);
		window.draw(quitButtonSprite);
		window.draw(startButtonSprite);
		window.display();

	}

}