#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){

    double sum,sum_pow2,sum2,sum3;
    for(int i=0;i<N;i++){
        sum 		+= A[i];
        sum_pow2 	+= pow(A[i],2);
        sum2 		+= log10(A[i]); 
        sum3 		+= 1/A[i];
    }
    
    double c[N];
    for(int i=0;i<N;i++)		c[i]=A[i];
    
    double x;
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            if(c[j]>c[j+1]){
                x		=c[j];
                c[j]	=c[j+1];
                c[j+1]	=x;
            }
        }
    }

    B[0]=sum/N;
    B[1]=sqrt((sum_pow2/N)-pow((sum/N),2));
    B[2]=pow(10,(sum2/N));
    B[3]=N/sum3;
    B[4]=c[N-1];
    B[5]=c[0];
}