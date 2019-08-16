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
  SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(barfly->ID()) << ": *Drinking heavily..*";
}

bool BarFlyGlobalState::OnMessage(BarFly* barfly, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

  switch (msg.Msg)
  {
  case Msg_Whatchalookingat:
  {
    cout << "\nMessage handled by " << GetNameOfEntity(barfly->ID()) << " at time: "
      << Clock->GetCurrentTime();

    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    cout << "\n" << GetNameOfEntity(barfly->ID()) <<
      ": Hey you ! Whatcha lookin at !?";

    barfly->GetFSM()->ChangeState(FightWithMiner::Instance());
  }

  return true;

  }

  return false;
}


//------------------------------------------------------------------------Fighting state

FightWithMiner* FightWithMiner::Instance()
{
  static FightWithMiner instance;

  return &instance;
}


void FightWithMiner::Enter(BarFly* barfly)
{
  cout << "\n" << GetNameOfEntity(barfly->ID()) << ": Gonna fight you, just wait there ! *Walks over to him*";
  barfly->SetFighting(true);
}


void FightWithMiner::Execute(BarFly* barfly)
{
  SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(barfly->ID()) << ": *Throws a fist to the miner!*";

  Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
    barfly->ID(),    //ID of sender
    ent_Miner_Bob,   //ID of recipient
    Msg_ThrowFist,   //the message
    NO_ADDITIONAL_INFO);
}

void FightWithMiner::Exit(BarFly* barfly)
{
  SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  cout << "\n" << GetNameOfEntity(barfly->ID()) << ": Next time I'ma beat you up!";
}


bool FightWithMiner::OnMessage(BarFly* barfly, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

  switch (msg.Msg)
  {
  case Msg_DodgeFist:
  {
    cout << "\nMessage handled by " << GetNameOfEntity(barfly->ID()) << " at time: "
      << Clock->GetCurrentTime();

    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    cout << "\n" << GetNameOfEntity(barfly->ID()) <<
      ": Grrrrr!!";

    barfly->GetFSM()->RevertToPreviousState();
  }

  return true;

  }

  return false;
}