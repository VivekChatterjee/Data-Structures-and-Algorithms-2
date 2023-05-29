class ParkingSystem {
public:
    int bs, ms, ss;
    ParkingSystem(int big, int medium, int small) {
        bs=big, ms=medium, ss=small;
    }
    
    bool addCar(int carType) {
        if(carType==1)
        {
            if(bs>0)
            {
                bs--;
                return 1;
            }
            return 0;
        }
        else if(carType==2)
        {
            if(ms>0)
            {
                ms--;
                return 1;
            }
            return 0;
        }
        else
        {
            if(ss>0)
            {
                ss--;
                return 1;
            }
            return 0;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */