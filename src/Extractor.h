#ifndef EXTRACTOR
#define EXTRACTOR

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>


class Extractor {
public:
	Extractor(std::string fileName, char openingToken = '<', char closingToken = '>') : openingToken{ openingToken }, closingToken{ closingToken } {
		fill(fileName); //fill the choices and random ordering vector
		shuffle(); //randomize the random ordering vector
		for (const auto& choice : choices) {
			auto variables = findVariables(choice);
			for (const auto& variable : variables) {
				nested.emplace(variable, Extractor("categories/" + variable + ".txt"));
			}
		}
	}


	std::string extract() const {
		std::random_device dev;
		std::mt19937 rng{ dev() };
		std::uniform_int_distribution<std::mt19937::result_type> distribution(0, choices.size() - 1);
		auto extracted = choices[distribution(rng)];

		//now check whether the choice has variables, if so extract them too
		return replaceVariables(extracted);

	}


	std::string extractNext() {
		if (currentElement >= choices.size()) {
			return "Sono state estratte tutte le categorie! Premi 'r' per mischiarle di nuovo";
		}
		return replaceVariables(choices[randomOrdering[currentElement++]]);
	}


	void shuffle() {
		std::random_device dev;
		std::default_random_engine rng{ dev() };
		std::shuffle(std::begin(randomOrdering), std::end(randomOrdering), rng);
		currentElement = 0;
	}


	const std::vector<std::string>& getChoices() const {
		return choices;
	}



private:

	void fill(std::string fileName) {
		std::ifstream file{ fileName };
		std::string line;
		int i = 0; //used to fill the random ordering vector
		while (std::getline(file, line)) {
			choices.push_back(line);
			randomOrdering.push_back(i++); //fill the random ordering vector
		}
	}


	std::vector<std::string> findVariables(std::string choice) const {
		std::vector<std::string> variables;
		for (int i = 0; i < choice.size(); ++i) {
			if (choice[i] == openingToken) {
				std::string variable;
				while (choice[++i] != closingToken) {
					variable += choice[i];
				}
				variables.push_back(variable);
			}
		}
		return variables;
	}



	std::string replaceVariables(std::string choice) const {
		std::string res;
		for (int i = 0; i < choice.size(); ++i) {
			if (choice[i] == openingToken) {
				std::string variable;
				while (choice[++i] != closingToken) {
					variable += choice[i];
				}
				res += nested.at(variable).extract();
			}
			else {
				res += choice[i];
			}
		}
		return res;
	}





	std::vector<std::string> choices;
	std::map<std::string, Extractor> nested;

	std::vector<int> randomOrdering;
	int currentElement;

	char openingToken, closingToken;
};


#endif