#pragma once

/////////// After test function

void postTest(int countCorrectAnswers) {

	// main window
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Test", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	// loading arrow and hand cursors
	sf::Cursor cursorArrow, cursorHand;
	if (!cursorArrow.loadFromSystem(sf::Cursor::Arrow)) {
		std::cout << "Cursor loading error" << std::endl;
	}

	if (!cursorHand.loadFromSystem(sf::Cursor::Hand)) {
		std::cout << "Cursor loading error" << std::endl;
	}

	// loading and setting icon for app
	sf::Image icon;
	if (!icon.loadFromFile("images/icon.png")) {
		std::cout << "Icon loading error" << std::endl;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	// loading "constatnt" texture for app
	sf::Texture quitButtonTexture;
	if (!quitButtonTexture.loadFromFile("images/menuQuit.png")) {
		std::cout << "Texture loading error" << std::endl;
	}
	
	// creating "constant" sprite for app
	sf::Sprite quitButtonSprite;
	quitButtonSprite.setTexture(quitButtonTexture);
	quitButtonSprite.setPosition(370, 500);

	// if user answered on 0 questions
	if (countCorrectAnswers == 0) {
		
		sf::Texture countAnswers0;
		if (!countAnswers0.loadFromFile("images/0correctAnswers.png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		sf::Sprite countAnswers0Sprite;
		countAnswers0Sprite.setTexture(countAnswers0);
		countAnswers0Sprite.setPosition(90, 50);

		sf::IntRect quitButtonRect(580, 525, 180, 57);

		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);

				chooseNum = 0;

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					if (chooseNum == 1) {
						exit(0);
					}

				}

			}

			window.draw(countAnswers0Sprite);
			window.draw(quitButtonSprite);
			window.display();

		}

	}

	// if user answered on 1 question
	else if (countCorrectAnswers == 1) {

		sf::Texture countAnswers1;
		if (!countAnswers1.loadFromFile("images/1correctAnswers.png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		sf::Sprite countAnswers1Sprite;
		countAnswers1Sprite.setTexture(countAnswers1);
		countAnswers1Sprite.setPosition(90, 50);

		sf::IntRect quitButtonRect(580, 525, 180, 57);

		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);

				chooseNum = 0;

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					if (chooseNum == 1) {
						exit(0);
					}

				}

			}

			window.draw(countAnswers1Sprite);
			window.draw(quitButtonSprite);
			window.display();

		}

	}

	// if user answered on 2 questions
	else if (countCorrectAnswers == 2) {

		sf::Texture countAnswers2;
		if (!countAnswers2.loadFromFile("images/2correctAnswers.png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		sf::Sprite countAnswers2Sprite;
		countAnswers2Sprite.setTexture(countAnswers2);
		countAnswers2Sprite.setPosition(90, 50);

		sf::IntRect quitButtonRect(580, 525, 180, 57);

		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);

				chooseNum = 0;

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					if (chooseNum == 1) {
						exit(0);
					}

				}

			}

			window.draw(countAnswers2Sprite);
			window.draw(quitButtonSprite);
			window.display();

		}

	}

	// if user answered on 3 questions
	else if (countCorrectAnswers == 3) {

		sf::Texture countAnswers3;
		if (!countAnswers3.loadFromFile("images/3correctAnswers.png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		sf::Sprite countAnswers3Sprite;
		countAnswers3Sprite.setTexture(countAnswers3);
		countAnswers3Sprite.setPosition(90, 50);

		sf::IntRect quitButtonRect(580, 525, 180, 57);

		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);

				chooseNum = 0;

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					if (chooseNum == 1) {
						exit(0);
					}

				}

			}

			window.draw(countAnswers3Sprite);
			window.draw(quitButtonSprite);
			window.display();

		}

	}

	// if user answered on 4 questions
	else if (countCorrectAnswers == 4) {

		sf::Texture countAnswers4;
		if (!countAnswers4.loadFromFile("images/4correctAnswers.png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		sf::Sprite countAnswers4Sprite;
		countAnswers4Sprite.setTexture(countAnswers4);
		countAnswers4Sprite.setPosition(90, 50);

		sf::IntRect quitButtonRect(580, 525, 180, 57);

		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);

				chooseNum = 0;

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					if (chooseNum == 1) {
						exit(0);
					}

				}

			}

			window.draw(countAnswers4Sprite);
			window.draw(quitButtonSprite);
			window.display();

		}

	}

	// if user answered on 5 questions
	else if (countCorrectAnswers == 5) {

		sf::Texture countAnswers5;
		if (!countAnswers5.loadFromFile("images/5correctAnswers.png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		sf::Sprite countAnswers5Sprite;
		countAnswers5Sprite.setTexture(countAnswers5);
		countAnswers5Sprite.setPosition(90, 50);

		sf::IntRect quitButtonRect(580, 525, 180, 57);

		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);

				chooseNum = 0;

				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					if (chooseNum == 1) {
						exit(0);
					}

				}

			}

			window.draw(countAnswers5Sprite);
			window.draw(quitButtonSprite);
			window.display();

		}

	}

}