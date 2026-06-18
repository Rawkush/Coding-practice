class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 360 degree  = 12 hours = 12*60 min
        if(hour == 12) hour = 0;
        if(minutes == 60) minutes = 0;

        int hoursToMin = hour*5;
        // cout<<hour<<" "<<hoursToMin<<endl;
        // after ever 60 min one hour changes, which basically covers 5 min distance 
        double offset =  (5.0/60.0)*minutes; // this is the numnber of minute diestnace hour key moved
        double hourKeyPos = hoursToMin + offset;
        // cout<<hoursToMin<<" "<< offset<<endl;
        // no convert the keys points to angle assuming the starting is from 0
        double anglePerMin = 360.0/60.0;
        double hangle = anglePerMin * hourKeyPos;
        double mangle = anglePerMin * minutes;

        // cout<< hangle << " "<<mangle;
        double a1 = abs(hangle - mangle);
        double a2 = 360.0-abs(hangle - mangle);
        return min(a1, a2);
    }
};