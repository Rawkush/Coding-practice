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
volume findVolume;
float lenght;
cout<<"enter the lenght of side of cube ";
cin>>lenght;
cout <<findVolume(lenght) << '\n';

//cout <<  << '\n';

  return 0;
}
