#ifndef WORKSPACEMODEL_H
#define WORKSPACEMODEL_H

#include "IModel.h"

namespace ww
{
	class Entity;
	class TextField;
	class Button;
    class Tooltip;

	class WorkspaceModel : public IModel
	{
	private:
		Entity* _background;
		Entity* _factorySpace;
		TextField* _textFieldCreateFactory;
        
        Button* _settingButton;
        Button* _quitButton;
        
        Tooltip* _tooltip;

	protected:

	public:
		WorkspaceModel();
		~WorkspaceModel();

		static const std::string MODEL_NAME;

		Entity* getBackground();
		Entity* getFactorySpace();
		TextField* getTextFieldCreateFactory();
        
        Button* getSettingButton();
        Button* getQuitButton();
        
        Tooltip* getTooltip();
	};
}

#endif
