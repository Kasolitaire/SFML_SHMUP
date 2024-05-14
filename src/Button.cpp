#include "Button.h"

Button::Button(ButtonType type, FloatRect box) : m_buttonType(type)
{
	m_gridBox.setSize(box.getSize());
	Vector2f vec = box.getPosition();
	m_gridBox.setOrigin(box.getOrigin());
	m_gridBox.setPosition(vec);
	m_gridBox.setFillColor(Color::Blue);
}

void Button::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	OnHoverEnter();
	OnHoverExit();
	OnClick();
}

void Button::OnHoverEnter()
{
}

void Button::OnHoverExit()
{
}

bool Button::GetHoverStatus()
{
	return m_hovering;
}

void Button::OnClick()
{
}

ButtonType Button::GetButtonType()
{
	return m_buttonType;
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_text);
	target.draw(m_gridBox);
}
