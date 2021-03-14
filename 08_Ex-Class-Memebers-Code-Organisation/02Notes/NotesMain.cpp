#include <iostream>
#include <string>
#include <vector>

#include "NoteName.h"
#include "SolfegeNoteNaming.h"

template<typename Naming> // SolfegeNoteNaming
class NoteParser {
	Naming translator;
public:
	NoteName translate(const std::string& noteText) const {
		return translator.operator()(noteText);
	}
};

int main() {
	NoteParser<SolfegeNoteNaming> parser;

	std::vector<NoteName> notes;
	std::string noteText;
	while (std::cin >> noteText && noteText != "end") {
		NoteName note = parser.translate(noteText);
		notes.push_back(note);
	}

	for (NoteName note : notes) {
		std::cout << note << " ";
	}

	return 0;
}