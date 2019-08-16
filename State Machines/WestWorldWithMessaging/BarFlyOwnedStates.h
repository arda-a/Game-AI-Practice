#pragma once

//------------------------------------------------------------------------
//
//  Name:   BarFlyOwnedStates.h
//
//  Desc:   All the states that can be assigned to the BarFly class
//
//  Author: Arda A. Abaka
//
//------------------------------------------------------------------------
#include "fsm/State.h"

class BarFly;

/*Swearing is the global state here.*/
class BarFlyGlobalState : public State<BarFly>
{
private:

  BarFlyGlobalState() {}

  //copy ctor and assignment should be private
  BarFlyGlobalState(const BarFlyGlobalState&);
  BarFlyGlobalState& operator=(const BarFlyGlobalState&);

public:

  //this is a singleton
  static BarFlyGlobalState* Instance();

  virtual void Enter(BarFly* barfly) {}

  virtual void Execute(BarFly* barfly);

  virtual void Exit(BarFly* barfly) {}

  virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};


class FightWithMiner : public State<BarFly>
{
private:

  FightWithMiner() {}

  //copy ctor and assignment should be private
  FightWithMiner(const FightWithMiner&);
  FightWithMiner& operator=(const FightWithMiner&);

public:

  //this is a singleton
  static FightWithMiner* Instance();

  virtual void Enter(BarFly* barfly);

  virtual void Execute(BarFly* barfly);

  virtual void Exit(BarFly* barfly);

  virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};