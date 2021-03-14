
#ifndef INITALIZATION_H
#define INITALIZATION_H

#include "CommandInterface.h"
#include <string>

using namespace std;

class CommandInterfaceExtend : public CommandInterface
{
private:
    class CutTransform : public TextTransform {
    private:
        string cutedText;
    public:
        void invokeOn(std::string& text, int startIndex, int endIndex) override {
            auto length = static_cast<size_t>(endIndex - startIndex);
            cutedText = text.substr(static_cast<size_t>(startIndex), length);
            text.erase(static_cast<size_t>(startIndex), length);
        }

    	string getCutedText() const
        {
            return this->cutedText;
        }
    };

    class PasteTransform : public TextTransform {
    private:
        shared_ptr<CutTransform> pasteText;
    public:
        PasteTransform(std::shared_ptr<CutTransform> cutPtr) : pasteText(std::move(cutPtr)) { };
    	
        void invokeOn(std::string& text, int startIndex, int endIndex) override {
            auto length = static_cast<size_t>(endIndex - startIndex);
            text.replace(startIndex, length, this->pasteText->getCutedText());
        }
    };
protected:
     std::vector<Command> initCommands() override{
         std::vector<Command> commands = CommandInterface::initCommands();
        const std::shared_ptr<CutTransform>& cutPtr = std::make_shared<CutTransform>();
        commands.push_back(Command("cut", cutPtr));
        commands.push_back(Command("paste", std::make_shared<PasteTransform>(cutPtr)));
        return commands;
    }
	
public:
    CommandInterfaceExtend(string& text) : CommandInterface(text) { this->init(); }
};

std::shared_ptr<CommandInterface>  buildCommandInterface(string& text)
{
    return make_shared<CommandInterfaceExtend>(text);
}



#endif // INITALIZATION_H