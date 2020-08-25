#include <Manager/manager.h>
#include <SoftwareSerial.h>

Wrist *wrist;
SoftwareSerial maestroSerial(COMMUNICATION::MAECOMM::RX, COMMUNICATION::MAECOMM::TX);
MicroMaestro * maestro;
Hand * hand;
Manager * manager;

void setup() {
  Pi::setup();

  wrist = new Wrist();
  Pi::write("\ndone wrist");
  maestroSerial.begin(9600);
  maestro = new MicroMaestro(maestroSerial);
  Pi::write("\ndone maestro");
  hand = new Hand(maestro);
  Pi::write("\ndone hand");
  hand->setup();
  Pi::write("hello");
  manager = new Manager(wrist, hand);
  
}

void loop()
{
  Pi::write("hello");
  manager->run();
}
