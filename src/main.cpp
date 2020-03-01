#include <StateMachine/StateMachine.h>


using namespace std;

StateMachine *sm;

void loop()
{
  using namespace MAESTRO;
  wrist = new Wrist();
  sm = new StateMachine();
  maestro = new MicroMaestro(maestroSerial);
  hand = new Hand(maestro);
  hand->setup();
  tm = new TaskManager(wrist, hand, sm);
  maestroSerial.begin(9600);
  Pi::setup();
  wrist->setup();
  //wrist = new Wrist(1);
  
}

int main()
{
  loop();

  delete safety;
  delete message;
  delete obj;
}