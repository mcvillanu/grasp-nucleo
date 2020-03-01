#include <StateMachine/StateMachine.h>


using namespace std;

StateMachine *sm;

void loop()
{
  sm->loop();
}

int main()
{
  loop();

  delete safety;
  delete message;
  delete obj;
}