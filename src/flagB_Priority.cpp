#include "ProjectFunctions.h"

int flagB_Priority(bool battStatus,bool wifiStatus,bool flowHalt,bool overFlow,bool lowFlow,bool hiFlow, int lasFlag){
    int finalFlag;
    
    if(hiFlow == true){
        if(lowFlow == true){
            if (battStatus == false){
                if(wifiStatus == false){
                    if(lasFlag == 6){
                        finalFlag = 5;
                    }
                    if(lasFlag == 5){
                        finalFlag = 2;
                    }
                    if(lasFlag == 2){
                        finalFlag = 1;
                    }
                }
                if(lasFlag == 6){
                        finalFlag = 5;
                    }
                if(lasFlag == 5){
                        finalFlag = 1;
                    }
            }
            if(lasFlag == 6){
                        finalFlag = 5;
                    }
            finalFlag = 6;
        }
        finalFlag = 6;
    }

    if(lowFlow == true){
            if (battStatus == false){
                if(wifiStatus == false){
                    if(lasFlag == 6){
                        finalFlag = 5;
                    }
                    if(lasFlag == 5){
                        finalFlag = 2;
                    }
                    if(lasFlag == 2){
                        finalFlag = 1;
                    }
                }
                if(lasFlag == 6){
                        finalFlag = 5;
                    }
                if(lasFlag == 5){
                        finalFlag = 1;
                    }
            }
            if(lasFlag == 6){
                        finalFlag = 5;
                    }
            finalFlag = 6;
        }
    
    if (battStatus == false){
                if(wifiStatus == false){
                    if(lasFlag == 6){
                        finalFlag = 5;
                    }
                    if(lasFlag == 5){
                        finalFlag = 2;
                    }
                    if(lasFlag == 2){
                        finalFlag = 1;
                    }
                }
                if(lasFlag == 6){
                        finalFlag = 5;
                    }
                if(lasFlag == 5){
                        finalFlag = 1;
                    }
            }

    if(wifiStatus == false){
                    if(lasFlag == 6){
                        finalFlag = 5;
                    }
                    if(lasFlag == 5){
                        finalFlag = 2;
                    }
                    if(lasFlag == 2){
                        finalFlag = 1;
                    }
                }

    if(overFlow == true){
        finalFlag = 4;
    }

    if(flowHalt == true){
        finalFlag = 3;
    }
    else{finalFlag = 0;}

 return finalFlag;
}