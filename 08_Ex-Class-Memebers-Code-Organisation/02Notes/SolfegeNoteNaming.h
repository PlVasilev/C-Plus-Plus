#ifndef SOLFEGE_NOTE_NAMING_H
#define SOLFEGE_NOTE_NAMING_H

struct SolfegeNoteNaming
{
	NoteName operator()(const std::string& noteName) const
	{
        if (noteName == "Do") {
            return { 'C' };
        }
        else if (noteName == "Re") {
            return { 'D' };
        }
        else if (noteName == "Mi") {
            return { 'E' };
        }
        else if (noteName == "Fa") {
            return { 'F' };
        }
        else if (noteName == "Sol") {
            return { 'G' };
        }
        else if (noteName == "La") {
            return { 'A' };
        }
        else if (noteName == "Si") {
            return { 'B' };
        }
        else {
            return { '?' };
        }
	}
};

#endif // !SOLFEGE_NOTE_NAMING_H