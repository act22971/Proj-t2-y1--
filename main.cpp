#include <iostream>
#include <fstream>
using namespace std;

#define DEV_MODE false // default is false
bool dev = DEV_MODE;
#include "NodeLL.cpp"
int main(int argc, char **argv){
    system("clear");
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
    
    ///////////////////////////////////////////////////////
    ifstream RF,RD,RDA,RS;//read text file readfood readdrink readdaily readspecific
    ofstream WF,WD,WDA,WS;//create text file
    ///////////////////////////////////////////////////////
    
    //

    //

    //////////////////////////create default///////////////
    RF.open("stock_food.txt");//ให้developerเก็บข้อมูล
    if(RF.fail())//if my text file doesn't exist, create one
    {
    WF.open("stock_food.txt");//create+name+open file
    WF.close();//fclose()
    }
    RF.close();//fclose()
    RD.open("stock_drink.txt");//ให้developerเก็บข้อมูล
    if(RD.fail())//if my text file doesn't exist, create one
    {
    WD.open("stock_drink.txt");//name+open file
    WD.close();//fclose()
    }
    RD.close();//fclose()
    RDA.open("stock_dailyuse.txt");//ให้developerเก็บข้อมูล
    if(RDA.fail())//if my text file doesn't exist, create one
    {
    WDA.open("stock_dailyuse.txt");//name+open file
    WDA.close();//fclose()
    }
    RDA.close();//fclose()
    RS.open("stock_specificuse.txt");//ให้developerเก็บข้อมูล
    if(RS.fail())//if my text file doesn't exist, create one
    {
    WS.open("stock_specificuse.txt");//name+open file
    WS.close();//fclose()
    }
    RS.close();//fclose()
    ///////////////////////////////////////////////////////
    
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime;
        string Usefor;
        string caution;
        string details;
        double weightAll;
        int quantityContainer, quantityEach;
        double weightEach,volumeEach;
        
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
                RF.open("stock_food.txt");
                while(RF>>name>>mfg>>exp>>LotNo>>weightAll>>quantityContainer>>quantityEach>>weightEach)/*collect food*/
                {
                    f = new food(name,mfg,exp,LotNo,weightAll,quantityContainer,quantityEach,weightEach);             a.add_node(f);
                }
                RF.close();
                RD.open("stock_drink.txt");
                while(RD>>name>>mfg>>exp>>LotNo>>weightAll>>quantityContainer>>quantityEach>>volumeEach)/*collect drink*/
                {
                    dr = new drink(name,mfg,exp,LotNo,weightAll,quantityContainer,quantityEach,volumeEach);             b.add_node(dr);
                }  
                RD.close();
                RDA.open("stock_dailyuse.txt");
                while(RDA>>name>>mfg>>exp>>LotNo>>Usefor>>weightAll>>quantityContainer>>quantityEach>>caution)/*collect dailyUse*/
                {
                    da = new dailyUse(name,mfg,exp,LotNo,Usefor,weightAll,quantityContainer,quantityEach,caution);             c.add_node(da);
                }
                RDA.close();                  
                RS.open("stock_specificuse.txt");
                while(RS>>name>>mfg>>exp>>LotNo>>Usefor>>weightAll>>quantityContainer>>quantityEach>>details)/*collect specificPurpose*/
                {
                s = new specificPurpose(name,mfg,exp,LotNo,Usefor,weightAll,quantityContainer,quantityEach,details);           d.add_node(s); 
                }
                RS.close();
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
   
    return 0;
}