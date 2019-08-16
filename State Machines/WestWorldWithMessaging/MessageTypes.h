#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_Whatchalookingat,
  Msg_ThrowFist,
  Msg_DodgeFist
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  case Msg_Whatchalookingat:

    return "Whatchalookingat";

  case Msg_ThrowFist:

    return "ThrowFist";

  case Msg_DodgeFist:

    return "DodgeFist";

  default:

    return "Not recognized!";
  }
}

#endif