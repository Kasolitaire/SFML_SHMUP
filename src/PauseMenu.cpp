#include "PauseMenu.h"

PauseMenu::PauseMenu(
	const RenderWindow& renderWindowConstant) :
	m_renderWindowConstant(&renderWindowConstant),
	m_resumeButton(ButtonType::RESUME, "Resume", FloatRect(renderWindowConstant.getSize().x / 2, 100, 100, 50)),
	m_exitButton(ButtonType::EXIT, "Exit" , FloatRect(0, 0, 200, 200)), m_keyReleased(true)
{
	m_tint.setSize(Vector2f(m_renderWindowConstant->getSize()));
	m_tint.setFillColor(Color(128, 128, 128, 128));
	m_paused = false;
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

void PauseMenu::HandleEvents(Event& event)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape && m_keyReleased)
	{
		m_paused = !m_paused;
		m_keyReleased = false;
		std::cout << "sfsfsf";
	}
	else if (event.type == Event::KeyReleased)
		m_keyReleased = true;
}

bool PauseMenu::GetPausedStatus()
{
	return m_paused;
}
