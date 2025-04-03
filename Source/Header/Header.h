#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include <vector>
#include <random>

std::vector<std::string> words = {"programming", "test", "HelloWorld", "blag", "CPP", "python", "minecraft"};

int getRandomNumber(int x) {
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(0, x);
	return distrib(gen);
}

std::vector<std::string> GenerateWords(int x) {
	
	std::vector<std::string> generatedWords = {};
	
	int i = 0;

	while (i < x) {
		int r = getRandomNumber(words.size()-1);
		generatedWords.push_back(words[r]);
		i++;
	}

	return generatedWords;
}

void StartGame() {

	std::string word;
	int score = 0;   

	while (true) {
		int count = 0;
		
		std::vector<std::string> generatedWords = GenerateWords(10);

		while (count < 10) {

			system("cls");

			for (int i = 0; i < generatedWords.size();i++) {
				std::cout << generatedWords[i] << " ";
			}
			std::cout << std::endl << "score :" << score;

			char key;
			key = _getch();

			if (key == 13) {
				word = "";
			}
			else if (key == 8) {
				word = word.substr(0, word.size() - 1);
			}
			else

			word += key;

			if (word == generatedWords[0]) {

				generatedWords.erase(generatedWords.begin());
				system("cls");
				score++;
				count++;

				word = "";
			}
		}
	}
}

