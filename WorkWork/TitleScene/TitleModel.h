#ifndef TITLEMODEL_H
#define TITLEMODEL_H

#include "IModel.h"

namespace ww
{
	class Entity;
	class Button;

	class TitleModel : public IModel
	{
	private:
		Entity* _background;
		Button* _startButton;
		Button* _optionsButton;
		Button* _quitButton;

		std::string _inputText;

	protected:

	public:
		TitleModel();
		~TitleModel();

		Entity* getBackground();
		Button* getStartButton();
		Button* getOptionsButton();
		Button* getQuitButton();

		static const std::string MODEL_NAME;;

		std::string & getInputText();
		void setInputText(const std::string & inputText);
	};
}

#endif
