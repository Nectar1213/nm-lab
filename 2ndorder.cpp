

#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
float function_one (float x, float y, float z)
{
    return (x * z + 1);
}
float function_two (float x, float y, float z)
{
    return (- x * y);
}
void calculate_and_display (float x0, float y0, float z0, float h, float xn)
{
    float n, k1, k2, k3, k4, k, l1, l2, l3, l4, l; 
    n = (round) ((xn - x0) / h + 1);
    for (int i = 0; i < n; i++)

    {
        cout <<"("<<i+1<<") "<< "X" << i << " = " << x0 << ", Y" << i <<" = " <<y0 << ", Z" << i << " = " << z0<< endl;
        k1 = h * function_one (x0, y0, z0);
        l1 = h * function_two (x0, y0, z0);
        k2 = h * function_one (x0 + h/2, y0 + k1/2, z0 + l1/2);
        l2 = h * function_two (x0 + h/2, y0 + k1/2, z0 + l1/2);
        k3 = h * function_one (x0 + h/2, y0 + k2/2, z0 + l2/2);
        k4 = h * function_one (x0 + h, y0 + k3, z0 + l3);
        l4 = h * function_two (x0 + h, y0 + k3, z0 + l3);
        k = (1.0/6) * (k1 + 2 * k2 + 2 * k3 + k4);
        l = (1.0/6) * (l1 + 2 * l2 + 2 * l3 + l4);

        x0 += h;
        y0 += k;
        z0 += l;
    }   

}
int main(){
    float x0, y0, z0, h, xn;
    cout << "Enter the value of x0: "<<endl;
    cin >> x0; 
    cout << "Enter the value of y0: "<<endl;
    cin >> y0; 
    cout << "Enter the value of z0: "<<endl;
    cin >> z0;
    cout << "Enter step size: "<<endl;
    cin >> h;
    cout << "Enter the final value of x: "<<endl;
    cin >> xn;
    calculate_and_display(x0, y0, z0, h, xn);


    getch();
    return 0;
}