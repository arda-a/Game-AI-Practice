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

  virtual void Enter(BarFly* wife) {}

  virtual void Execute(BarFly* wife);

  virtual void Exit(BarFly* wife) {}

  virtual bool OnMessage(BarFly* wife, const Telegram& msg);
};


class Drink : public State<BarFly>
{
private:

  Drink() {}

  //copy ctor and assignment should be private
  Drink(const Drink&);
  Drink& operator=(const Drink&);

public:

  //this is a singleton
  static Drink* Instance();

  virtual void Enter(BarFly* wife) {}

  virtual void Execute(BarFly* wife);

  virtual void Exit(BarFly* wife) {}

  virtual bool OnMessage(BarFly* wife, const Telegram& msg);
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

  virtual void Enter(BarFly* wife) {}

  virtual void Execute(BarFly* wife);

  virtual void Exit(BarFly* wife) {}

  virtual bool OnMessage(BarFly* wife, const Telegram& msg);
};