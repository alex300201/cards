//
//  main.cpp
//  poker
//
//  Created by alex on 01.09.2020.
//  Copyright © 2020 alex. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

template<size_t size>
class deck {
	static constexpr int shuffle_count = 100;

	using card_t = short;
private:

	card_t *cards_deck = new card_t[size];
	short curent_card = 0;
	std::string (*converter)(int){};
private:
	void shuffle() {
		for (size_t i = 0; i < shuffle_count; ++i) {
			std::swap(cards_deck[std::rand() % size], cards_deck[std::rand() % size]);
		}
	}


public:
	explicit deck(std::string (*convertor)(int)) {
		for (size_t i = 0; i < size; ++i) {
			cards_deck[i] = i;
		}
		this->shuffle();
		this->converter = convertor;
	}

	std::string draw_card() {
		if (curent_card < size) {
			return converter(curent_card++);
		} else {
			shuffle();
			curent_card = 0;
			return converter(curent_card++);
		}
	}

	int draw_card_seed() {
		if (curent_card < size) {
			return curent_card++;
		} else {
			shuffle();
			curent_card = 0;
			return curent_card++;
		}
	}

	card_t& operator[] (size_t i) { return cards_deck[i]; }
	const card_t& operator[] (size_t i) const { return cards_deck[i]; }
};

int main(int argc, const char *argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	return 0;
}
