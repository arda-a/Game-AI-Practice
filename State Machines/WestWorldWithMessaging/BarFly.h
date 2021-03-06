#ifndef BARFLY_H
#define BARFLY_H
//------------------------------------------------------------------------
//
//  Name: MinersWife.h
//
//  Desc: class to implement Miner Bob's wife.
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "fsm/State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "BarFlyOwnedStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"


class BarFly : public BaseGameEntity
{
private:

  //an instance of the state machine class
  StateMachine<BarFly>* m_pStateMachine;

  location_type   m_Location;

  bool m_fighting;

public:

  BarFly(int id) :m_Location(location_type::saloon),
    m_fighting(false),
    BaseGameEntity(id)

  {
    //set up the state machine
    m_pStateMachine = new StateMachine<BarFly>(this);

    m_pStateMachine->SetCurrentState(BarFlyGlobalState::Instance());
  }

  ~BarFly() { delete m_pStateMachine; }


  //this must be implemented
  void          Update();

  //so must this
  virtual bool  HandleMessage(const Telegram& msg);

  StateMachine<BarFly>* GetFSM()const { return m_pStateMachine; }

  //----------------------------------------------------accessors
  location_type Location()const { return m_Location; }
  void          ChangeLocation(location_type loc) { m_Location = loc; }
  
  bool          Fighting()const { return m_fighting; }
  void          SetFighting(bool val) { m_fighting = val; }
};

#endif
