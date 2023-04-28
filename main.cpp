#include <iostream>
#include <fstream>
using namespace std;

#define DEV_MODE false // default is false
bool dev = DEV_MODE;
#include "NodeLL.cpp"
int main(int argc, char **argv){
    system("clear");
    ifstream RF;//read text file
    ofstream WF;//create text file
    int i;
    /////////////////////////////////////////
    int num_lines = 1; // number of data lines
    /////////////////////////////////////////
    if(dev){
    cout << "The argc is " << argc << endl;
    for(i = 0; i < argc ; i++){
        cout << "argv[" << i << "] is " << argv[i] << endl;
    }
}
    ///////////////////////////////////////////////////////
    LLFood a; LLDrinks b; LLDai c;      LLSpec d;
    food *f;  drinks *dr; dailyUse *da; specificPurpose *s;
    ///////////////////////////////////////////////////////
    //////////////////////////create default///////////////
    RF.open("stock.txt");//ให้developerเก็บข้อมูล
    if(RF.fail())//if my text file doesn't exist, create one
    {
    WF.open("stock.txt");//name+open file
    WF.close();//fclose()
    }
    RF.close();//fclose()
    RF.open("stock.txt");//ให้developerเก็บข้อมูล
    ///////////////////////////////////////////////////////

    int choice = 0;
    string extra;
    do{
        if(dev) cout << "[!] Developer Mode" << endl;
        cout << "Please select command" << endl;
        cout << "1 : Load data" << endl;
        cout << "2 : Showall" << endl;
        cout << "9 : Exit" << endl;
        cout << "99 : Then type: \"dev\" to switch developer mode" << endl;
        cout << "Input number : "; cin >> choice;
        switch(choice){
            case 1 : //Load data
                system("clear");
                while(){}                
                /*
                for(i = 0; i < num_lines; i++){
                    f = new food();             a.add_node(f);
                    dr = new drinks();          b.add_node(dr); 
                    da = new dailyUse();        c.add_node(da); 
                    s = new specificPurpose();  d.add_node(s); 
                }
                */

                cout << "[!] Data has been loaded." << endl;
                break;
            case 2 : //Showall
                    system("clear");
                    a.show_all();
                    b.show_all();
                    c.show_all();
                    d.show_all();
                    cout << "" << endl;
                    break;
            case 99 :
                    cin >> extra;
                    if(extra == "dev") dev = !dev;
                    else choice = 0;
            default : system("clear");
        }
    }while(choice != 9);
    RF.close();//fclose()
    return 0;
}