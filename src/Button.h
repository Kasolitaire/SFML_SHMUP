#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
enum ButtonType{RESUME, EXIT};
class Button : public Drawable
{
public:
	Button(ButtonType type, FloatRect box);
	virtual void Update(const Time deltaTime, const Time totalTimeElapsed);

	virtual void OnHoverEnter();
	virtual void OnHoverExit();
	virtual bool GetHoverStatus();
	virtual void OnClick();
	ButtonType GetButtonType() const;
	virtual void draw(RenderTarget& target, RenderStates states) const override;
protected:
	Text m_text;
	RectangleShape m_gridBox;
	ButtonType m_buttonType;
	bool m_hovering;
};

