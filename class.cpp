#include <iostream>
#include <string>

using namespace std;

class Dvig
{
private:
string marka;
int obiem;
double rashod;
double kolvobenz;
double way;
double rashodben(double way){	
double n=kolvobenz/way;
double m=rashod/n;
cout<<"rashod "<<n<<endl;
cout<<"on the remaining gasoline can go "<<m<<"km";
}
public:
Dvig(string marka1,int obiem1,double rashod1,double way1)
{
write(marka1,obiem1,rashod1,way1);
//zapravka(kolvobenz1);
//rashodben(way);
}

~Dvig()
{
cout<<marka<<" delete ";
}


double zapravka(double kolvobenz1){
kolvobenz=kolvobenz1;
cout<<"zapravaka: "<<kolvobenz;
}



void showAll(){
    cout<<"Marka:"<<marka<<endl;
    cout<<"volume of motor:"<<obiem<<endl;
    cout<<rashodben(way)<<endl;
}
void write(string marka1,int obiem1,double rashod1,double way1){
marka=marka1;
obiem=obiem1;
rashod=rashod1;
way=way1;	    
}
};
int main()
{
   Dvig obj("Jigul",50,5,120);
   obj.zapravka(20);
   
   obj.showAll();
//   delete obj;
   cout<<"The programm complete"<<endl;
}
