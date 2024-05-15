#include "Button.h"
#include "AssetManager.h"
#include "paths.h"

Button::Button(ButtonType type, const std::string buttonContent ,FloatRect box) : m_buttonType(type)
{
	/*m_gridBox.setSize(box.getSize());
	Vector2f vec = box.getPosition();
	m_gridBox.setOrigin(box.getOrigin()); 
	m_gridBox.setPosition(vec);
	m_gridBox.setFillColor(Color::Blue);
	m_text.setCharacterSize(50);
	m_text.setFont(AssetManager::GetFont(ASSETS_PATH + "Vermin Vibes 1989.ttf"));
	m_text.setString(buttonContent);*/
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

ButtonType Button::GetButtonType() const
{
	return m_buttonType;
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_gridBox);
	target.draw(m_text);
}
