#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.hpp"
#include "test.hpp"
#include "testResults.hpp"

int main() {

	int questionNumber = 0;

	menu();

	while (questionNumber <= 5) {
		questionNumber++;
		test(questionNumber);
	}

	postTest(correctAnswers.getAnswers());

	return 0;
}