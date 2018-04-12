#include<iostream>
using namespace std;


class volume{

public:
float calcVolume(float lenght) // for calclating volume of cube
{
  return lenght*lenght*lenght;   // calclating an returning the volume pf cube
}

float calcVolume(float lenght, float breadth, float height)// for volume of cuboid
{
  return lenght*breadth*height;
}

float calcVolume (float radius, float lenght)// for claculating volume of cylinder
{

  return 3.14*r*r*h;
}

};


 int main()
  {



  return 0;
}
