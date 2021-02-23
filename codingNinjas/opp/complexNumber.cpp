#include <iostream>
using namespace std;



class ComplexNumbers {
    // Complete this class

   private:
    int real1;
    int imaginary1;

   public:
    ComplexNumbers(int real1,int imaginary1){
        this->real1=real1;
        this->imaginary1=imaginary1;
    }
    void print(){
        cout<<this->real1<<" + "<<"i"<<this->imaginary1<<endl;
    }

    void plus(ComplexNumbers const & c2){
    	real1=this->real1+c2.real1;
     	imaginary1=this->imaginary1+c2.imaginary1;
        this->real1=real1;
        this->imaginary1=imaginary1;
    }

    //(x+yi)(u+vi) = (xu-yv)+(xv+yu)i

  void multiply(ComplexNumbers c2){
        real1=(this->real1 * c2.real1)-(this->imaginary1 * c2.imaginary1);
        imaginary1=(this->real1 * c2.imaginary1) + (this->imaginary1 * c2.real1);
        this->real1=real1;
        this->imaginary1=imaginary1;

    }







};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
}

