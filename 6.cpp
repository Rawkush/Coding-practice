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
volume find;
float lenght,breadth, height, radius;
cout<<"enter the lenght of side of cube ";
cin>>lenght;
cout <<find.calcVolume(lenght) << '\n';


cout <<"enter the lenght, breadth , height of cuboid"  << '\n';
cin >> lenght>>breadth>>height;
cout << find.calcVolume(lenght,breadth,height) << '\n';



  return 0;
}
