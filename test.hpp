#pragma once

/////////// General app function

// class for answers
class CorrectAnswers {
private:
	int correctAnswers;

public:
	CorrectAnswers() {
		this->correctAnswers = 0;
	}

	int getAnswers();
	CorrectAnswers operator++();

};

CorrectAnswers CorrectAnswers::operator++() {
	correctAnswers++;
	return *this;
}

int CorrectAnswers::getAnswers() {
	return correctAnswers;
}

// variable for count correct answers
CorrectAnswers correctAnswers;

void test(int questionNumber) {

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

	// loading "constatnt" textures for app
	sf::Texture chooseAnswerTexture, quitButtonTexture;
	if (!chooseAnswerTexture.loadFromFile("images/chooseAnswer.png")) {
		std::cout << "Texture loading error" << std::endl;
	}

	if (!quitButtonTexture.loadFromFile("images/menuQuit.png")) {
		std::cout << "Texture loading error" << std::endl;
	}

	// creating "constant" sprites for app
	sf::Sprite chooseAnswerSprite, quitButtonSprite;
	chooseAnswerSprite.setTexture(chooseAnswerTexture);
	chooseAnswerSprite.setPosition(0, 275);

	quitButtonSprite.setTexture(quitButtonTexture);
	quitButtonSprite.setPosition(370, 500);

	// if this is the first question
	if (questionNumber == 1) {

		// loading textures for question
		sf::Texture question1Texture, question1Answer1Texture, question1Answer2Texture, question1Answer3Texture;
		if (!question1Texture.loadFromFile("images/question1.png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question1Answer1Texture.loadFromFile("images/question1Answer1(correct).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question1Answer2Texture.loadFromFile("images/question1Answer2(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question1Answer3Texture.loadFromFile("images/question1Answer3(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		// creating and setting sprites for question
		sf::Sprite question1Sprite, question1Answer1Sprite, question1Answer2Sprite, question1Answer3Sprite;
		question1Sprite.setTexture(question1Texture);
		question1Sprite.setPosition(90, 50);
		question1Answer1Sprite.setTexture(question1Answer1Texture);
		question1Answer2Sprite.setTexture(question1Answer2Texture);
		question1Answer3Sprite.setTexture(question1Answer3Texture);
		question1Answer1Sprite.setPosition(-125, 325);
		question1Answer2Sprite.setPosition(-25, 325);
		question1Answer3Sprite.setPosition(75, 325);

		// creaing rectangles for buttons
		sf::IntRect quitButtonRect(580, 525, 180, 57);
		sf::IntRect question1Answer1Rect(160, 375, 26, 40);
		sf::IntRect question1Answer2Rect(260, 375, 30, 40);
		sf::IntRect question1Answer3Rect(354, 375, 40, 40);

		// variable to understanding which button pressed
		int chooseNum = 0;

		while (window.isOpen()) {
			
			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);
				question1Answer1Sprite.setColor(sf::Color::White);
				question1Answer2Sprite.setColor(sf::Color::White);
				question1Answer3Sprite.setColor(sf::Color::White);

				chooseNum = 0;

				// exit by user 
				if (event.type == sf::Event::Closed) {
					exit(0);
				}

				// if user put the cursor on the quit button
				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				// if user put the cursor on the first answer button
				if (question1Answer1Rect.contains(mousePos.x, mousePos.y)) {
					question1Answer1Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 2;
				}

				// if user put the cursor on the second answer button
				if (question1Answer2Rect.contains(mousePos.x, mousePos.y)) {
					question1Answer2Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 3;
				}

				// if user put the cursor on the third answer button
				if (question1Answer3Rect.contains(mousePos.x, mousePos.y)) {
					question1Answer3Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 4;
				}

				// if user pressed the left mouse button while cursor is on one of buttons
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					
					// user pressed on the quit button
					if (chooseNum == 1) {
						exit(0);
					}
					// user preseed on the button with correct answer
					if (chooseNum == 2) {
						++correctAnswers;
						window.close();
					}
					// user preseed on the button with incorrect answer
					if (chooseNum == 3) {
						window.close();
					}
					// user preseed on the button with incorrect answer
					if (chooseNum == 4) {
						window.close();
					}

				}

			}

			window.draw(question1Answer1Sprite);
			window.draw(question1Answer2Sprite);
			window.draw(question1Answer3Sprite);
			window.draw(chooseAnswerSprite);
			window.draw(quitButtonSprite);
			window.draw(question1Sprite);
			window.display();

		}

	}

	// if this is the second question 
	else if (questionNumber == 2) {
		
		// loading textures for question
		sf::Texture question2Texture, question2Answer1Texture, question2Answer2Texture, question2Answer3Texture;
		if (!question2Texture.loadFromFile("images/question2.png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question2Answer1Texture.loadFromFile("images/question2Answer1(correct).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question2Answer2Texture.loadFromFile("images/question2Answer2(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question2Answer3Texture.loadFromFile("images/question2Answer3(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		// creating and setting sprites for question
		sf::Sprite question2Sprite, question2Answer1Sprite, question2Answer2Sprite, question2Answer3Sprite;
		question2Sprite.setTexture(question2Texture);
		question2Sprite.setPosition(90, 50);
		question2Answer1Sprite.setTexture(question2Answer1Texture);
		question2Answer2Sprite.setTexture(question2Answer2Texture);
		question2Answer3Sprite.setTexture(question2Answer3Texture);
		question2Answer2Sprite.setPosition(-200, 325);
		question2Answer1Sprite.setPosition(0, 325);
		question2Answer3Sprite.setPosition(200, 325);

		// creating rectangles for buttons
		sf::IntRect quitButtonRect(580, 525, 180, 57);
		sf::IntRect question2Answer1Rect(240, 375, 120, 40);
		sf::IntRect question2Answer2Rect(40, 375, 115, 40);
		sf::IntRect question2Answer3Rect(448, 375, 105, 40);

		// variable to understanding which button pressed
		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);
				question2Answer1Sprite.setColor(sf::Color::White);
				question2Answer2Sprite.setColor(sf::Color::White);
				question2Answer3Sprite.setColor(sf::Color::White);

				chooseNum = 0;

				// exit by user
				if (event.type == sf::Event::Closed) {
					exit(0);
				}

				// if user put the cursor on the quit button
				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				// if user put the cursor on the first answer button
				if (question2Answer1Rect.contains(mousePos.x, mousePos.y)) {
					question2Answer1Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 2;
				}

				// if user put the cursor on the second answer button
				if (question2Answer2Rect.contains(mousePos.x, mousePos.y)) {
					question2Answer2Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 3;
				}

				// if user put the cursor on the third answer button
				if (question2Answer3Rect.contains(mousePos.x, mousePos.y)) {
					question2Answer3Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 4;
				}

				// if user pressed the left mouse button while cursor is on one of buttons
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					// user pressed on the quit button
					if (chooseNum == 1) {
						exit(0);
					}
					// user pressed on the button with correct answer
					if (chooseNum == 2) {
						++correctAnswers;
						window.close();
					}
					// user pressed on the button with correct answer
					if (chooseNum == 3) {
						window.close();
					}
					// user pressed on the button with correct answer
					if (chooseNum == 4) {
						window.close();
					}

				}

			}

			window.draw(question2Answer1Sprite);
			window.draw(question2Answer2Sprite);
			window.draw(question2Answer3Sprite);
			window.draw(chooseAnswerSprite);
			window.draw(quitButtonSprite);
			window.draw(question2Sprite);
			window.display();

		}
		
	}

	// if this is the third question 
	else if (questionNumber == 3) {

		// loading textures for question
		sf::Texture question3Texture, question3Answer1Texture, question3Answer2Texture, question3Answer3Texture;
		if (!question3Texture.loadFromFile("images/question3.png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question3Answer1Texture.loadFromFile("images/question3Answer1(correct).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question3Answer2Texture.loadFromFile("images/question3Answer2(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question3Answer3Texture.loadFromFile("images/question3Answer3(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		// creating and setting sprites for question
		sf::Sprite question3Sprite, question3Answer1Sprite, question3Answer2Sprite, question3Answer3Sprite;
		question3Sprite.setTexture(question3Texture);
		question3Sprite.setPosition(90, 50);
		question3Answer1Sprite.setTexture(question3Answer1Texture);
		question3Answer2Sprite.setTexture(question3Answer2Texture);
		question3Answer3Sprite.setTexture(question3Answer3Texture);
		question3Answer2Sprite.setPosition(-200, 325);
		question3Answer1Sprite.setPosition(0, 325);
		question3Answer3Sprite.setPosition(200, 325);

		// creating rectangles for buttons
		sf::IntRect quitButtonRect(580, 525, 180, 57);
		sf::IntRect question3Answer1Rect(245, 375, 110, 40);
		sf::IntRect question3Answer2Rect(35, 375, 130, 40);
		sf::IntRect question3Answer3Rect(420, 375, 160, 40);

		// variable to understanding which button pressed
		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);
				question3Answer1Sprite.setColor(sf::Color::White);
				question3Answer2Sprite.setColor(sf::Color::White);
				question3Answer3Sprite.setColor(sf::Color::White);

				chooseNum = 0;
				
				// exit by user
				if (event.type == sf::Event::Closed) {
					exit(0);
				}

				// if user put the cursor on the quit button
				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				// if user put the cursor on the button with correct answer
				if (question3Answer1Rect.contains(mousePos.x, mousePos.y)) {
					question3Answer1Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 2;
				}

				// if user put the cursor on the button with incorrect answer
				if (question3Answer2Rect.contains(mousePos.x, mousePos.y)) {
					question3Answer2Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 3;
				}
				
				// if user put the cursor on the button with incorrect answer
				if (question3Answer3Rect.contains(mousePos.x, mousePos.y)) {
					question3Answer3Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 4;
				}

				// if user pressed the left mouse button while cursor is on one of buttons
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					
					// user pressed on the quit button
					if (chooseNum == 1) {
						exit(0);
					}
					// user pressed on the button with correct answer
					if (chooseNum == 2) {
						++correctAnswers;
						window.close();
					}
					// user pressed on the button with incorrect answer
					if (chooseNum == 3) {
						window.close();
					}
					// user pressed on the button with incorrect answer
					if (chooseNum == 4) {
						window.close();
					}

				}

			}

			window.draw(question3Answer1Sprite);
			window.draw(question3Answer2Sprite);
			window.draw(question3Answer3Sprite);
			window.draw(chooseAnswerSprite);
			window.draw(quitButtonSprite);
			window.draw(question3Sprite);
			window.display();

		}
		
	}

	// if this is the fourth question 
	else if (questionNumber == 4) {

		// loading textures for question
		sf::Texture question4Texture, question4Answer1Texture, question4Answer2Texture, question4Answer3Texture;
		if (!question4Texture.loadFromFile("images/question4.png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question4Answer1Texture.loadFromFile("images/question4Answer1(correct).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question4Answer2Texture.loadFromFile("images/question4Answer2(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question4Answer3Texture.loadFromFile("images/question4Answer3(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		// creating and setting sprites for question
		sf::Sprite question4Sprite, question4Answer1Sprite, question4Answer2Sprite, question4Answer3Sprite;
		question4Sprite.setTexture(question4Texture);
		question4Sprite.setPosition(90, 50);
		question4Answer1Sprite.setTexture(question4Answer1Texture);
		question4Answer2Sprite.setTexture(question4Answer2Texture);
		question4Answer3Sprite.setTexture(question4Answer3Texture);
		question4Answer2Sprite.setPosition(300, 325);
		question4Answer1Sprite.setPosition(-75, 325);
		question4Answer3Sprite.setPosition(75, 375);

		// creating rectangles for buttons
		sf::IntRect quitButtonRect(580, 525, 180, 57);
		sf::IntRect question4Answer1Rect(40, 375, 370, 40);
		sf::IntRect question4Answer2Rect(482, 375, 235, 40);
		sf::IntRect question4Answer3Rect(257, 425, 235, 40);

		// variable to understanding which button pressed
		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);
				question4Answer1Sprite.setColor(sf::Color::White);
				question4Answer2Sprite.setColor(sf::Color::White);
				question4Answer3Sprite.setColor(sf::Color::White);

				chooseNum = 0;
				
				// exit by user
				if (event.type == sf::Event::Closed) {
					exit(0);
				}

				// if user put the cursor on the quit button
				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				// if user put the cursor on the button with correct answer
				if (question4Answer1Rect.contains(mousePos.x, mousePos.y)) {
					question4Answer1Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 2;
				}

				// if user put the cursor on the button with incorrect answer
				if (question4Answer2Rect.contains(mousePos.x, mousePos.y)) {
					question4Answer2Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 3;
				}

				// if user put the cursor on the button with incorrect answer
				if (question4Answer3Rect.contains(mousePos.x, mousePos.y)) {
					question4Answer3Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 4;
				}

				// if user pressed the left mouse button while cursor is on one of buttons
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					// user pressed on the quit button
					if (chooseNum == 1) {
						exit(0);
					}
					// user pressed on the button with correct answer
					if (chooseNum == 2) {
						++correctAnswers;
						window.close();
					}
					// user pressed on the button with incorrect answer
					if (chooseNum == 3) {
						window.close();
					}
					// user pressed on the button with incorrect answer
					if (chooseNum == 4) {
						window.close();
					}

				}

			}

			window.draw(question4Answer1Sprite);
			window.draw(question4Answer2Sprite);
			window.draw(question4Answer3Sprite);
			window.draw(chooseAnswerSprite);
			window.draw(quitButtonSprite);
			window.draw(question4Sprite);
			window.display();

		}

	}

	// if this is the fifth question
	else if (questionNumber == 5) {
		
		// loading textures for question
		sf::Texture question5Texture, question5Answer1Texture, question5Answer2Texture, question5Answer3Texture;
		if (!question5Texture.loadFromFile("images/question5.png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question5Answer1Texture.loadFromFile("images/question5Answer1(correct).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question5Answer2Texture.loadFromFile("images/question5Answer2(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}
		if (!question5Answer3Texture.loadFromFile("images/question5Answer3(incorrect).png")) {
			std::cout << "Texture loading error" << std::endl;
		}

		// creating and setting sprites for question
		sf::Sprite question5Sprite, question5Answer1Sprite, question5Answer2Sprite, question5Answer3Sprite;
		question5Sprite.setTexture(question5Texture);
		question5Sprite.setPosition(90, 50);
		question5Answer1Sprite.setTexture(question5Answer1Texture);
		question5Answer2Sprite.setTexture(question5Answer2Texture);
		question5Answer3Sprite.setTexture(question5Answer3Texture);
		question5Answer2Sprite.setPosition(250, 325);
		question5Answer1Sprite.setPosition(65, 375);
		question5Answer3Sprite.setPosition(-125, 325);

		// creating rectangles for buttons
		sf::IntRect quitButtonRect(580, 525, 180, 57);
		sf::IntRect question5Answer1Rect(270, 425, 190, 35);
		sf::IntRect question5Answer2Rect(350, 375, 400, 40);
		sf::IntRect question5Answer3Rect(75, 375, 199, 33);

		// variable to understanding which button pressed
		int chooseNum = 0;

		while (window.isOpen()) {

			window.clear(sf::Color(129, 181, 221));

			sf::Event event;

			while (window.pollEvent(event)) {

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				window.setMouseCursor(cursorArrow);

				quitButtonSprite.setColor(sf::Color::White);
				question5Answer1Sprite.setColor(sf::Color::White);
				question5Answer2Sprite.setColor(sf::Color::White);
				question5Answer3Sprite.setColor(sf::Color::White);

				chooseNum = 0;

				// exit by user
				if (event.type == sf::Event::Closed) {
					exit(0);
				}

				// if user put the cursor on the quit button
				if (quitButtonRect.contains(mousePos.x, mousePos.y)) {
					quitButtonSprite.setColor(sf::Color::Red);
					window.setMouseCursor(cursorHand);
					chooseNum = 1;
				}

				// if user put the cursor on the button with correct answer
				if (question5Answer1Rect.contains(mousePos.x, mousePos.y)) {
					question5Answer1Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 2;
				}

				// if user put the cursor on the button with incorrect answer
				if (question5Answer2Rect.contains(mousePos.x, mousePos.y)) {
					question5Answer2Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 3;
				}

				// if user put the cursor on the button with incorrect answer
				if (question5Answer3Rect.contains(mousePos.x, mousePos.y)) {
					question5Answer3Sprite.setColor(sf::Color::Green);
					window.setMouseCursor(cursorHand);
					chooseNum = 4;
				}

				// if user pressed the left mouse button while cursor is on one of buttons
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					// user pressed on the quit button
					if (chooseNum == 1) {
						exit(0);
					}
					// user pressed on the button with correct answer
					if (chooseNum == 2) {
						++correctAnswers;
						window.close();
					}
					// user pressed on the button with incorrect answer
					if (chooseNum == 3) {
						window.close();
					}
					// user pressed on the button with incorrect answer
					if (chooseNum == 4) {
						window.close();
					}

				}

			}

			window.draw(question5Answer1Sprite);
			window.draw(question5Answer2Sprite);
			window.draw(question5Answer3Sprite);
			window.draw(chooseAnswerSprite);
			window.draw(quitButtonSprite);
			window.draw(question5Sprite);
			window.display();

		}
			
	}

}