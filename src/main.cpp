<<<<<<< HEAD
#include <Manager/manager.h>
#include <SoftwareSerial.h>

Wrist *wrist;
SoftwareSerial maestroSerial(COMMUNICATION::MAECOMM::RX, COMMUNICATION::MAECOMM::TX);
MicroMaestro * maestro;
Hand * hand;
Manager * manager;

void setup()
=======
#include <StateMachine/StateMachine.h>


using namespace std;

StateMachine *sm;

void loop()
>>>>>>> 56c27451e4a8d46ff3a28472057928d88abf95b0
{
  Pi::setup();
  
  wrist = new Wrist();
  Pi::write("\ndone wrist");
  maestroSerial.begin(9600);
  maestro = new MicroMaestro(maestroSerial);
  Pi::write("\ndone maestro");
  hand = new Hand(maestro);
  Pi::write("\ndone hand");
  hand->setup();
<<<<<<< HEAD
  Pi::write("hello");
  manager = new Manager(wrist, hand);
=======
  tm = new TaskManager(wrist, hand, sm);
  maestroSerial.begin(9600);
  Pi::setup();
  wrist->setup();
  //wrist = new Wrist(1);
>>>>>>> 56c27451e4a8d46ff3a28472057928d88abf95b0
  
}

int main()
{
<<<<<<< HEAD
  Pi::write("hello");
  manager->run();
}
=======
  loop();

  delete safety;
  delete message;
  delete obj;
}
>>>>>>> 56c27451e4a8d46ff3a28472057928d88abf95b0
