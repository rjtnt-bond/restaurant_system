# restaurant_system
This restauresnt mangement system
#include<bits/stdc++.h>
using namespace std;
class Restaurant
{
public:

    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    int  total_tax;
public:
    Restaurant()
    {
        this->total_tax=0;
    }
    void setter(float amount)
    {
        total_tax+=amount;
    }
  float getter(){
          return total_tax;
    }
};

void Bill_System(Restaurant *myrest,int n)
{
    int t_num,sum;
    cout<<endl;
    cout<<"Enter Table number : ";
    cin>>t_num;
    int code[12];
    int Quantity[12];
    int code_t,quantity,items;
    cout<<"Enter the Number of Items : ";
    cin>>items;
    for(int i=0; i<items; i++)
    {
        int ak=0;
        Flag:

        cout<<"Enter Item "<<i+1<<" Code : ";
        cin>>code[i];
        for(int k=0; k<n; k++)
        {
            if(code[i]==myrest->food_item_codes[k])
            {
                ak++;
            }

        }
        if(ak==0)
        {
            cout<<"Code is not valid, needs to enter the code again."<<endl;
            goto Flag;
        }
        cout<<"Enter Item "<<i+1<<" Quantity : ";
        cin>>Quantity[i];
    }
    cout<<"\t\t\tBILL SUMMARY"<<endl;
    cout<<"\t\t\t_____________"<<endl;
    cout<<"Table No . "<<t_num<<endl;
    cout<<"Item Code\t Item Name\t  Item Price \t Item Quantity \tTotal Price"<<endl;
    for(int i=0; i<items; i++)
    {
        for(int k=0; k<n; k++)
        {
            if(code[i]==myrest->food_item_codes[k])
            {
                cout<<myrest->food_item_codes[k]<<"\t\t"<<myrest->food_item_names[k]<<"\t"<<myrest->food_item_prices[k]<<"\t\t"<<Quantity[i]<<"\t\t"<<myrest->food_item_prices[k]*Quantity[i]<<endl;
                sum+=myrest->food_item_prices[k]*Quantity[i];

            }

        }
    }
    cin.ignore();
    float tax=(float)(5*sum)/100;
    myrest->setter(tax);

    cout<<"TAX\t\t\t\t\t\t\t\t\t";
    cout<<fixed<<setprecision(2)<<tax<<endl;
    cout<<"__________________________________________________________________________________"<<endl;
    cout<<"NET TOTAL\t\t\t\t\t\t\t\t"<<sum+tax<<"Taka"<<endl;
    cout<<myrest->getter()<<endl<<endl;

}

int main()
{
    Restaurant *myrest=new Restaurant;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>myrest->food_item_codes[i];
        cin.ignore();
        getline(cin,myrest->food_item_names[i]);
        cin>>myrest->food_item_prices[i];
    }
    while(true)
    {
        cout<<"\t\t MAKE BILL "<<endl;
        cout<<"\t\t___________"<<endl;
        cout<<"Item code \t Item Name \t\t Item Price"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<myrest->food_item_codes[i]<<"\t\t";
            cout<<myrest->food_item_names[i]<<"\t\t";
            cout<<myrest->food_item_prices[i]<<"\t\t";
            cout<<endl;
        }
        Bill_System(myrest,n);

    }
    return 0;
}


