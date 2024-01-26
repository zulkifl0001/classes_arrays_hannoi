#include <iostream>
using namespace std;


//Q2-1-a
//declaring disk class
class disk{
private:
    int diameter; //diameter
public:
     disk(int n);//constructor

     int get_d();//method to get the diameter
};

//constructor for disk
disk::disk(int n){
    diameter=n;
}

//method to return the diameter
int disk::get_d() {
    return diameter;
}

//Q2-1-b
//declaring class hanoi
class Hanoi{
private:
    disk *A[20], *B[20], *C[20]; //the rods are modeled using array pointers

public:
    int count;//number of disks on the rod

    int beginning=0;// first rod
    int mid=1; //second rod
    int end=2;//third rod
    Hanoi(int n);//constructor
    void move(int from, int to);//method to move disks from one rod to another


    int print(); //print all rods with their disks

};

//Q2-1-c
//constructor
Hanoi::Hanoi(int n){
    count=n;

    //loop to create disk objects of increasing size and put them in the arrays
    for(int i=0;i<20;i++){
        if(n-i>-1){
            //only rod A has disks
            A[i]=new disk (n-i);
        }
        else{
            A[i]=new disk(0);
        }
        //rod b and c are empty
        B[i]=new disk(0);
        C[i]=new disk(0);
    }

}
int Hanoi::print() {
        for(int i=0;i<20;i++){
        cout<<(A[i]->get_d());
        cout<<(B[i]->get_d());
        cout<<(C[i]->get_d())<<endl;
}}



//Q2-1-d
//move
void Hanoi::move(int from,int to){
    int last=0,lastb=0,lastc=0;//first empty disk of a b and c

//find the first empty disk for A,B and C
    for (int i=0;i<20;i++){
        if(A[i]->get_d()==0){
            break;
        }
        else{
            last+=1;

        }
    }

    for (int i=0;i<20;i++){
        if(B[i]->get_d()==0){
            break;
        }
        else{
            lastb+=1;
        }
    }

    for (int i=0;i<20;i++){
        if(C[i]->get_d()==0){
            break;
        }
        else{
            lastc+=1;
        }
    }
    if(from!=to){
        if((from==0 or from==1 or from==2) and (to==0 or to==1 or to==2))//check if rod indices are valid
        {
            //A to B or C
            if(from==0) {

                switch (to) {
                    case 1:
                        if ((A[last - 1]->get_d() < B[lastb - 1]->get_d() or lastb == 0) and (A[last-1]->get_d())!=0) //checks to ensure that the move is not illegal
                        {

                            B[lastb] = A[last - 1];//move the previous disk from the first 0th disk of A to the first empty position of B
                            A[last - 1] = new disk(0);//replace the moved disk with a disk with diameter 0(no disk)
                            cout<<"disk "<<B[lastb]->get_d()<<" moved from rod 0 to 1"<<endl;
                        } else{
                            cout<<"move is illegal";
                        }

                        break;

                    case 2:
                        if ((A[last - 1]->get_d() < C[lastc - 1]->get_d() or lastc == 0) and (A[last-1]->get_d())!=0) {

                            C[lastc] = A[last - 1];
                            A[last - 1] = new disk(0);
                            cout<<"disk "<<C[lastc]->get_d()<<" moved from rod 0 to 2"<<endl;
                        } else{
                            cout<<"move is illegal";
                        }
                        break;
                }
            }

            //B to A or C
            if(from==1){

                switch (to) {
                    case 0:
                        if ((B[lastb - 1]->get_d() < A[last - 1]->get_d() or last == 0)and (B[lastb-1]->get_d())!=0 ){

                            A[last] = B[lastb - 1];
                            B[lastb - 1] = new disk(0);
                            cout<<"disk "<<A[last]->get_d()<<" moved from rod 1 to 0"<<endl;
                        } else{
                            cout<<"move is illegal";
                        }
                        break;
                    case 2:
                        if ((B[lastb - 1]->get_d() < C[lastc - 1]->get_d() or lastc == 0)and (B[lastb-1]->get_d())!=0 ){

                            C[lastc] = B[lastb - 1];
                            B[lastb - 1] = new disk(0);
                            cout<<"disk "<<C[lastc]->get_d()<<" moved from rod 1 to 2"<<endl;

                        } else{
                            cout<<"move is illegal";
                        }
                        break;
                }
            }
            //C to A or B
            if (from==2) {

                switch (to) {
                    case 0:
                        if ((C[lastc - 1]->get_d() < A[last - 1]->get_d() or last == 0)and (C[lastc-1]->get_d())!=0 ){

                            A[last] = C[lastc - 1];
                            C[lastc - 1] = new disk(0);
                            cout<<"disk "<<A[last]->get_d()<<" moved from rod 2 to 0"<<endl;

                        }
                        else{
                            cout<<"move is illegal";
                        }

                        break;

                    case 1:
                        if ((C[lastc - 1]->get_d() < B[lastb - 1]->get_d() or lastb == 0)and (C[lastc-1]->get_d())!=0 ){

                            B[lastb] = C[lastc - 1];
                            C[lastc - 1] = new disk(0);
                            cout<<"disk "<<B[lastb]->get_d()<<" moved from rod 2 to 1"<<endl;

                        }
                        else{
                            cout<<"move is illegal";
                        }
                        break;
                }

            }
        }else{
            cout<<"rod indices are invalid";
        }
    }
    else{
        cout<<"rod indices are invalid";
    }

}


//Q2-1-e
//solve
void solve_hanoi(Hanoi &a) //takes the input by reference as we must change the actual locations in a
{


    if(a.count==0 ){
        return;
    }
    else {

        int b=a.count;//a.count will not change back after the function returns so we must assign it to b and assign it back later
        a.count--;

        int temp=a.mid;
        a.mid=a.end;
        a.end=temp;

        int m=a.mid;//same reason as b with a.count
        int e=a.end;

        solve_hanoi(a);//recursive call

            a.count = b;//reassigning vals
            a.mid = e;
            a.end = m;

            a.move(a.beginning , a.end);//

        int c=a.count;
        a.count--;
        int temp1=a.mid;
        a.mid=a.beginning ;
        a.beginning =temp;

        int m1=a.mid;
        int be=a.beginning ;
        solve_hanoi(a);//second recursive call

        a.count = c;
        a.mid = be;
        a.beginning  = m1;

    }

}

//Q2-2
//print backwards
void print_backwards(char const *string){
    if (*string=='\0')//condition to break out of the recursive loop
    {
        return;
    }
    else{
        print_backwards(string+1);//starts printing from the last location
        cout<<*string;
    }
}

//Q2-3
//nth_prime
int nth_prime(int n){
    int a[100000];
    bool checker;
    a[0]=2;//first prime number is 2
    int *b;//pointer to a
    b=a;

    //looping over range where there could be prime numbers
    for(int i=2;i<n*n;i++){

        checker=false;

        for(int b=2;b<(i/2)+3;b++){
            //checking for prime numbers
            if(i%b==0 and i!=b){
                checker=true;
            }
        }
        //if checker false then number is prime
        if(!checker){
            *b=i;
            b=b+1;
        }
    }
    return a[n-1];//return the nth prime number
}

int main()
{

}