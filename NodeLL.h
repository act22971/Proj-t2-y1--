//All Node stucture

#ifndef NodeLL_h
#define NodeLL_h

/*
========================================
   Stucture of Inheritance 22.04.2023
          UPDATED 26.04.2023
========================================

                    NODE
                     |
                  general
                  /     \ 
                 /       \
       consumable         appliance
       /        \         /      \
    food      drinks  dailyUse  SpecPur
     ||         ||       ||       ||
   LLFood    LLDrinks   LLDai   LLSpec
========================================
*/

// <------------- Node ------------->

/*Node*/
class NODE {
    private:
    protected:
        long NodeID;
    public:
        NODE();
        //~NODE();
        //void show_data();
        virtual ~NODE() = 0;
        virtual void show_data() = 0;
        //void insert(NODE*&);
        //NODE* move_next();
};
/*general*/
class general:public NODE{
    private:
    protected:
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime;
    public:
        general(string = "No Name", string = "No MFG", string = "No EXP", long = 0);
        virtual ~general() = 0;
        virtual void show_data() = 0;;
};

/*consumable: general*/
class consumable:public general{
    private:
    protected:
        double weightAll;
        int quantityContainer, quantityEach;
    public:
        consumable(string = "No Name", string = "No MFG", string = "No EXP", long = 0, double = 0.0, int = 0,int = 0);
        virtual ~consumable() = 0;
        virtual void show_data() = 0;
};
/*food:consumable*/
class food:public consumable{
    private:
        food *next;
    protected:
        double weightEach;
    public:
        food(string = "No Name", string = "No MFG", string = "No EXP", long = 0, double = 0.0, int = 0,int = 0, double = 0.0);
        ~food();
        void show_data();
        void insert(food*&);
        food* move_next();
};
/*drinks: consumable*/
class drinks:public consumable{
    private:
        drinks *next;
    protected:
        double volumeEach;
    public:
        drinks(string = "No Name", string = "No MFG", string = "No EXP", long = 0, double = 0.0, int = 0,int = 0, double = 0.0);
        ~drinks();
        void show_data();
        void insert( drinks*&);
        drinks* move_next();
};

/*appliance: general*/
class appliance:public general{
    private:
    protected:
        string Usefor;
        double weightAll;
        int quantityContainer, quantityEach;
    public:
        appliance(string = "No Name", string = "No MFG", string = "No EXP", long = 0, string = "For non", double = 0.0, int = 0, int = 0);
        virtual ~appliance() = 0;
        virtual void show_data() = 0;
        appliance* move_next();
};
/*dailyUse: appliance*/
class dailyUse:public appliance{
    private:
        dailyUse *next;
    protected:
        string details;
    public:
        dailyUse(string = "No Name", string = "No MFG", string = "No EXP", long = 0, string = "For non", double = 0.0, int = 0, int = 0, string = "No detail");
        ~dailyUse();
        void show_data();
        void insert( dailyUse *&);
        dailyUse* move_next();
};
/*specificPurpose: appliance*/
class specificPurpose:public appliance{
    private:
        specificPurpose *next;
    protected:
        string caution;
    public:
        specificPurpose(string = "No Name", string = "No MFG", string = "No EXP", long = 0, string = "For non", double = 0.0, int = 0, int = 0, string = "No caution");
        ~specificPurpose();
        void show_data();
        void insert( specificPurpose*&);
        specificPurpose* move_next();
};
/*
food{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime;
        double weightAll;
        int quantityContainer, quantityEach;
        double weightEach;
}
drinks{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime;
        double weightAll;
        int quantityContainer, quantityEach;
        double volumeEach;
}
dailyUse{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime;
        string Usefor;
        double weightAll;
        int quantityContainer, quantityEach;
        string details;
}
specificPurpose{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime;
        string Usefor;
        double weightAll;
        int quantityContainer, quantityEach;
        string caution;
}
*/
// <------------- LL ------------->
/*LLFood*/
class LLFood{
      food *hol;
      int size;
public:
       void add_node(food *&);
       void show_all();
       ~LLFood();
       LLFood();
      
};
/*LLDrinks*/
class LLDrinks{
      drinks *hol;
      int size;
public:
       void add_node(drinks*&);
       void show_all();
       ~LLDrinks();
       LLDrinks();
      
};

/*LLDai*/
class LLDai{
      dailyUse *hol;
      int size;
public:
       void add_node(dailyUse *&);
       void show_all();
       ~LLDai();
       LLDai();
      
};
/*LLSpec*/
class LLSpec{
      specificPurpose *hol;
      int size;
public:
       void add_node(specificPurpose *&);
       void show_all();
       ~LLSpec();
       LLSpec();
      
};
#endif