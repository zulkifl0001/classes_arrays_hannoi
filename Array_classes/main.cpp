#include <iostream>
using namespace std;

//Q1-1-a
template <int N>
class Matrix
{
private:
    double data[N][N];
public:
    int const SIZE = N;
    Matrix<N>(); //constructor

    int getter(int i, int j); //method to get values at indices
    void setter(int i, int j,int val); //method to set values at indices
    void print(); //method to print the matrix
};

//constructor Q1-1-a
//initializes the matrix as an identity matrix
template<int N>
Matrix<N>::Matrix() {
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i==j){
                data[i][j]=1;//when i and j are equal, the location is given a value of 1
            }else{
                data[i][j]=0;//other values are initialized as 0s
            }
        }
    }
}

//getter Q1-1-b
//takes inputs i(row) and j(column) and returns the integer value at that location
template<int N>
int Matrix<N>::getter(int i,int j) {
    if (0<=i & i<N & 0<=j &j<N){

        return data[i][j];

    }
    else{
        cout<<"invalid range"<<endl;//if i or j are outside the range then an error is printed
    }
}

//setter Q1-1-b
//takes 3 inputs i(row),j(column) and val(value to be assigned)
template<int N>
void Matrix<N>::setter(int i, int j,int val){

    if (0<=i & i<N & 0<=j &j<N ) {
        data[i][j] = val;
    }
    else{
        cout<<"invalid range"<<endl;//if or j are outside the range then an error is printed
    }

}

//print method for self testing
template<int N>
void Matrix<N>::print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }


}



//adder Q1-2
//takes 2 matrices of size N , adds them and outputs a third matrix.
//passed by object value
template <int N>
Matrix<N> adder(Matrix<N> a,Matrix<N> b){
    Matrix<N> matrix;//declaring a temporary object that will be output
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

                matrix.setter(i, j, a.getter(i, j) + b.getter(i, j)); //taking vals using the getter function and setting them using the setter function

        }
    }

    return matrix;
}

//subtractor Q1-2
//takes 2 objects, subtracts them and outputs a third new object
//passed by object value
template <int N>
Matrix<N> subtractor(Matrix<N> a,Matrix<N> b){
    Matrix<N> matrix;//declaring a temporary object that will be output
    for(int i=0;i<N;i++) {
        for (int j = 0; j < N; j++) {
                matrix.setter(i, j, a.getter(i, j) - b.getter(i, j));//using getter to get the vals and using setter to set them after subtraction
        }
    }
    return matrix;//returns a new object of the class Matrix with size N
}

//multiplier Q1-2
//takes 2 matrices with size N, multiplies them, and outputs a matrix with size N
//passed by object value
template<int N>
Matrix<N>multiplier(Matrix<N> a,Matrix<N> b){
    Matrix<N> matrix;//declaring a temporary object that will be output

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp=0;
            //we need to add a third loop as multiplication involves the multiplication and summition a row of one matrix with the column of another
            for(int k=0;k<N;k++){
                temp+=a.getter(i,k)*b.getter(k,j); //adding up all the column row multiplications
            }
            matrix.setter(i,j,temp);//assigning the temp val to the suitable cell
        }
    }
    return matrix;
}


//Q1-3
//helper function for determinant
//takes a large matrix and an integer and returns a matrix of size N-1xN-1
//the integer is to tell which column to ignore while making the smaller array
template <int N>
Matrix<N-1> helper(Matrix<N> b,int x){
    Matrix<N-1> matrix;

    int row=0;

    for (int i=0;i<N;i++){
        int col=0;
        if(i==x)//skips the iteration when i becomes equal to the column num for which the cofactor is being taken
        {
            continue;
        }
        else{
            for (int j=1;j<N;j++)//we have j=1 as the first row is always ignored
            {

                matrix.setter(row,col,b.getter(i,j));//sets the values for the smaller array
                col+=1;
            }

        }
        row+=1;
    }

    return matrix;
}


//determinant Q1-3
//takes the input as the object and returns an integer value
//for a 1x1 array
int determinant(Matrix<1> a){
    return a.getter(0,0);//the determinant of a 1x1 matrix is itself
}

//Q1-3
//for a 2x2 array
int determinant(Matrix<2> a){
    return a.getter(0,0)*a.getter(1,1)-a.getter(1,0)*a.getter(0,1);
}

//Q1-3
//for any NxN array for N>2
//takes a matrix as input and gives an integer as the output
template<int N>
int determinant( Matrix<N> a) {
    int check=0;//used to see if the value at that column is to be added or subtracted while taking the determinant
    int det=0;

    for(int i=0;i<N;i++){

        if ((i+2)%2==0){
            check=1;
        }
        else{
            check=-1;
        }
        det+=check*determinant(helper(a,i))*a.getter(i,0);//using the helper function inside determinant recursively to get smaller matrices that can be used to calculate the determinant
    }
    return det;
}


int main(){

}