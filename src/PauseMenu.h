#pragma once
#include "EventManager.h"
#include "Button.h"

class PauseMenu : public Drawable
{
public:
	PauseMenu(const RenderWindow& m_renderWindowConstant);
	void Update(const Time deltaTime, const Time totalTimeElapsed);
	void draw(RenderTarget& target, RenderStates states) const override;

private:
	const RenderWindow* m_renderWindowConstant;
	RectangleShape m_tint;
	Button m_resumeButton;
	Button m_exitButton;
	bool m_paused;
};

