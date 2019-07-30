#include "BarFlyOwnedStates.h"
#include "MinerOwnedStates.h"
#include "BarFly.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state

BarFlyGlobalState* BarFlyGlobalState::Instance()
{
  static BarFlyGlobalState instance;

  return &instance;
}


void BarFlyGlobalState::Execute(BarFly* barfly)
{
  //1 in 10 chance of needing the bathroom (provided she is not already
  //in the bathroom)
  /*if ((RandFloat() < 0.1) &&
    !barfly->GetFSM()->isInState(*VisitBathroom::Instance()))
  {
    barfly->GetFSM()->ChangeState(VisitBathroom::Instance());
  }*/
}

bool BarFlyGlobalState::OnMessage(BarFly* barfly, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

  /*switch (msg.Msg)
  {
  case Msg_HiHoneyImHome:
  {
    cout << "\nMessage handled by " << GetNameOfEntity(barfly->ID()) << " at time: "
      << Clock->GetCurrentTime();

    SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    cout << "\n" << GetNameOfEntity(barfly->ID()) <<
      ": Hi honey. Let me make you some of mah fine country stew";

    wife->GetFSM()->ChangeState(CookStew::Instance());
  }

  return true;

  }*///end switch

  return false;
}