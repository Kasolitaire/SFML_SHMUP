#include "PauseMenu.h"

PauseMenu::PauseMenu(
	const RenderWindow& renderWindowConstant) :
	m_renderWindowConstant(&renderWindowConstant),
	m_resumeButton(ButtonType::RESUME, FloatRect(200, 200, 200, 200)),
	m_exitButton(ButtonType::EXIT, FloatRect(0, 0, 200, 200))
{
	m_tint.setSize(Vector2f(m_renderWindowConstant->getSize()));
	m_tint.setFillColor(Color(128, 128, 128, 128));
	m_paused = true;
}

void PauseMenu::Update(const Time deltaTime, const Time totalTimeElapsed)
{
}

void PauseMenu::draw(RenderTarget& target, RenderStates states) const
{
	if (m_paused) // only draws elements if paused
	{
		target.draw(m_tint);
		m_resumeButton.draw(target, states);
		//m_exitButton.draw(target, states);
	}
}
