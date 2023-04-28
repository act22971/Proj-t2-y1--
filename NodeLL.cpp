//All Node related function

#include "NodeLL.h"
#include "ctime"

// <------------- Node ------------->

/*Node*/
NODE::NODE(){
      static long x = 130000;
      NodeID = ++x;
      if(dev){
      cout << "adding NodeID @ NODE : " << x << endl;
      }
}
  NODE:: ~NODE(){
      if(dev){
      cout << "NodeID " << NodeID << " is being deleted" << endl;
      }
}
void  NODE:: show_data(){
     cout << "NodeID @ NODE : " << NodeID << endl;
 }

/*general*/
general::general(string inName, string inmfg, string inexp, long inLotNo):NODE(){
      static long x = 0, y = 500000;
      LotID = ++x;
      if(inLotNo) LotNo = ++y; // Default inLotNo should be 0
      else LotNo = inLotNo;
      name = inName;
      mfg = inmfg;
      exp = inexp;

      // time input
      time_t curr_time;
	 curr_time = time(NULL);
      string realtime = ctime(&curr_time);
      string textDay, day, textMonth, year, hh, mm, ss, time;
	 if(dev)cout << "Today is : " << realtime; //In this format >> Tue Apr 25 12:31:25 2023
      textDay = textDay + realtime[0] + realtime[1] + realtime[2]; // Tue
      day = day + realtime[8] + realtime[9]; // 25
      textMonth = textMonth + realtime[4] + realtime[5] + realtime[6]; // Apr
      year = year + realtime[20] + realtime[21] + realtime[22] + realtime[23]; //2023
      hh = hh + realtime[11] + realtime[12]; //12
      mm = mm + realtime[14] + realtime[15]; //31
      ss = ss + realtime[17] + realtime[18]; //25
      time = time + hh + ":" + mm + ":" + ss; // hh:mm:ss
      updateTime = updateTime + " " + textDay + " " +  day + " " +  textMonth + " " +  year + " @ " +  time; // Tue 25 Apr 2023 12:31:25

      if(dev){
      cout << "textDay :" << textDay << endl;
      cout << "day :" << day << endl;
      cout << "textMonth :" << textMonth << endl;
      cout << "year :" << year << endl;
      cout << "hh :" << hh << endl;
      cout << "mm :" << mm << endl;
      cout << "ss :" << ss << endl;
      cout << "time :" << time << endl;
      cout << "adding name @ general : " << name << endl;
      cout << "adding mfg @ general : " << mfg << endl;
      cout << "adding exp @ general : " << exp << endl;
      cout << "adding updateTime @ general : " << updateTime << endl;
      }
}
  general:: ~general(){
      if(dev){
      cout << "name " << name << " is being deleted" << endl;
      cout << "mfg " << mfg << " is being deleted" << endl;
      cout << "exp " << exp << " is being deleted" << endl;
      }
}
void  general:: show_data(){
      cout << "name @ general : " << name << endl;
      cout << "mfg @ general : " << mfg << endl;
      cout << "exp @ general : " << exp << endl;
      cout << "updateTime @ general : " << updateTime << endl;
}
/*consumable: general*/
consumable::consumable(string inName, string inmfg, string inexp, long inLotNo, double inweightAll, int inquantityContainer, int inquantityEach):general(inName, inmfg, inexp, inLotNo){
      weightAll = inweightAll;
      quantityContainer = inquantityContainer;
      quantityEach = inquantityEach;
      if(dev){
      cout << "adding weightAll @ consumable : " << weightAll << endl;
      cout << "adding quantityContainer @ consumable : " << quantityContainer << endl;
      cout << "adding quantityEach @ consumable : " << quantityEach << endl;
      }
}
consumable:: ~consumable(){
      if(dev){
      cout << "weightAll " << weightAll << " is being deleted" << endl;
      cout << "quantityContainer " << quantityContainer << " is being deleted" << endl;
      cout << "quantityEach " << quantityEach << " is being deleted" << endl;
      }
}
void  consumable:: show_data(){
      cout << "weightAll @ consumable : " << weightAll << endl;
      cout << "quantityContainer @ consumable : " << quantityContainer << endl;
      cout << "quantityEach @ consumable : " << quantityEach << endl;
}
/*food:consumable*/
food::food(string inName, string inmfg, string inexp, long inLotNo, double inweightAll, int inquantityContainer, int inquantityEach, double inweightEach):consumable(inName, inmfg, inexp, inLotNo, inweightAll, inquantityContainer, inquantityEach){
      weightEach = inweightEach;
      if(dev){
      cout << "adding weightEach @ food : " << weightEach << endl;
      }
}
food:: ~food(){
      if(dev){
      cout << "weightEach " << weightEach << " is being deleted" << endl;
      }
}
void  food:: show_data(){
      NODE::show_data();
      general::show_data();
      consumable::show_data();
      cout << "weightEach @ food : " << weightEach << endl;
}
food *food::move_next(){
      return next;
}
void food::insert(food*& x){
     x->next=this;
}
/*drinks: consumable*/
drinks::drinks(string inName, string inmfg, string inexp, long inLotNo, double inweightAll, int inquantityContainer, int inquantityEach, double involumeEach):consumable(inName, inmfg, inexp, inLotNo, inweightAll, inquantityContainer, inquantityEach){
      volumeEach = involumeEach;
      if(dev){
      cout << "adding volumeEach @ drinks : " << volumeEach << endl;
      }
}
drinks:: ~drinks(){
      if(dev){
      cout << "volumeEach " << volumeEach << " is being deleted" << endl;
      }
}
void  drinks:: show_data(){
      NODE::show_data();
      general::show_data();
      consumable::show_data();
      cout << "volumeEach @ drinks : " << volumeEach << endl;
}
drinks *drinks::move_next(){
      return next;
}
void drinks::insert(drinks*& x){
     x->next=this;
}

/*appliance: general*/
appliance::appliance(string inName, string inmfg, string inexp, long inLotNo, string inUsefor, double inweightAll, int inquantityContainer, int inquantityEach):general(inName, inmfg, inexp, inLotNo){
      Usefor = inUsefor;
      weightAll = inweightAll;
      quantityContainer = inquantityContainer;
      quantityEach = inquantityEach;
      if(dev){
      cout << "adding Usefor @ appliance : " << Usefor << endl;
      cout << "adding weightAll @ appliance : " << weightAll << endl;
      cout << "adding quantityContainer @ appliance : " << quantityContainer << endl;
      cout << "adding quantityEach @ appliance : " << quantityEach << endl;
      }
}
appliance:: ~appliance(){
      if(dev){
      cout << "Usefor " << Usefor << " is being deleted" << endl;
      cout << "weightAll " << weightAll << " is being deleted" << endl;
      cout << "quantityContainer " << quantityContainer << " is being deleted" << endl;
      cout << "quantityEach " << quantityEach << " is being deleted" << endl;
      }
}
void  appliance:: show_data(){
      cout << "Usefor @ appliance : " << Usefor << endl;
      cout << "weightAll @ appliance : " << weightAll << endl;
      cout << "quantityContainer @ appliance : " << quantityContainer << endl;
      cout << "quantityEach @ appliance : " << quantityEach << endl;
}
/*dailyUse: appliance*/
dailyUse::dailyUse(string inName, string inmfg, string inexp, long inLotNo, string inUsefor, double inweightAll, int inquantityContainer, int inquantityEach, string indetails):appliance(inName, inmfg, inexp, inLotNo, inUsefor, inweightAll, inquantityContainer, inquantityEach){
      details = indetails;
      if(dev){
      cout << "adding details @ dailyUse : " << details << endl;
      }
}
dailyUse:: ~dailyUse(){
      if(dev){
      cout << "details " << details << " is being deleted" << endl;
      }
}
void  dailyUse:: show_data(){
      NODE::show_data();
      general::show_data();
      appliance::show_data();
      cout << "details @ dailyUse : " << details << endl;
}
dailyUse *dailyUse::move_next(){
      return next;
}
void dailyUse::insert(dailyUse*& x){
     x->next=this;
}
/*specificPurpose: appliance*/
specificPurpose::specificPurpose(string inName, string inmfg, string inexp, long inLotNo, string inUsefor, double inweightAll, int inquantityContainer, int inquantityEach, string incaution):appliance(inName, inmfg, inexp, inLotNo, inUsefor, inweightAll, inquantityContainer, inquantityEach){
      caution = incaution;
      if(dev){
      cout << "adding caution @ specificPurpose : " << caution << endl;
      }
}
specificPurpose:: ~specificPurpose(){
      if(dev){
      cout << "caution " << caution << " is being deleted" << endl;
      }
}
void  specificPurpose:: show_data(){
      NODE::show_data(); 
      general::show_data();
      appliance::show_data();
      cout << "caution @ specificPurpose : " << caution << endl;
}
specificPurpose *specificPurpose::move_next(){
      return next;
}
void specificPurpose::insert(specificPurpose*& x){
     x->next=this;
}

// <------------- LL ------------->
/*LLFood*/
LLFood::LLFood(){
       hol=NULL;
       size=0;
}

LLFood::~LLFood(){
     food *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
     cout << "[!] Program is terminated."; // Because food is declared the first, it will be the last to deconstruct.
}

void LLFood::show_all(){
     food *t = hol;
     int i;
     cout << endl << "=== Show Linkedlist Food ==" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "=== End of Show Linkedlist Food ==" << endl;
}
void LLFood::add_node(food *&A){

          hol->insert(A);
          hol=A;

       size++;

 }
 /*LLDrinks*/
LLDrinks::LLDrinks(){
       hol=NULL;
       size=0;
}

LLDrinks::~LLDrinks(){
     drinks *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
}

void LLDrinks::show_all(){
     drinks *t = hol;
     int i;
     cout << endl << "=== Show Linkedlist Drinks ==" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "=== End of Show Linkedlist Drinks ==" << endl;
}
void LLDrinks::add_node(drinks *&A){

          hol->insert(A);
          hol=A;

       size++;

 }

 /*LLDai*/
LLDai::LLDai(){
       hol=NULL;
       size=0;
}

LLDai::~LLDai(){
     dailyUse *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
}

void LLDai::show_all(){
     dailyUse  *t=hol;
     int i;
     cout << endl << "=== Show Linkedlist DailyUse ==" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "=== End of Show Linkedlist DailyUse ==" << endl;
}
void LLDai::add_node(dailyUse *&A){

          hol->insert(A);
          hol=A;

       size++;

 }
 /*LLSpec*/
LLSpec::LLSpec(){
       hol=NULL;
       size=0;
}

LLSpec::~LLSpec(){
     specificPurpose *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
}

void LLSpec::show_all(){
     specificPurpose *t = hol;
     int i;
     cout << endl << "=== Show Linkedlist SpcPurpose ==" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "=== End of Show Linkedlist SpcPurpose ==" << endl;
}
void LLSpec::add_node(specificPurpose *&A){

          hol->insert(A);
          hol=A;

       size++;

 }