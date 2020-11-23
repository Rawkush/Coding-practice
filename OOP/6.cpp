// 6th problem statemnt solution

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

float calcVolume (float radius, float height)// for claculating volume of cylinder
{

  return 3.14*radius*radius*height;
}

};


 int main()
  {
volume find;
float lenght,breadth, height, radius;
cout<<"enter the lenght of side of cube ";
cin>>lenght;
cout <<"the volume of cube is: "<<find.calcVolume(lenght) << '\n';


cout <<"enter the lenght, breadth , height of cuboid"  << '\n';
cin >> lenght>>breadth>>height;
cout <<"volume of cuboid is: " <<find.calcVolume(lenght,breadth,height) << '\n';

cout << "enter the radius, height of cylinder" << '\n';
cin>>radius>>height;

cout << "the volume of clinder is:"<<find.calcVolume(radius,height) << '\n';

  return 0;
}
