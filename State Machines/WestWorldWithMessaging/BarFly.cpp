#include "BarFly.h"

bool BarFly::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void BarFly::Update()
{
  //set text color to red
  SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

  m_pStateMachine->Update();
}