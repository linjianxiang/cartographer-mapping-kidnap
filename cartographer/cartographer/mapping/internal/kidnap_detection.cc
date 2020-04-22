#include "cartographer/mapping/internal/kidnap_detection.h"



namespace cartographer{
namespace mapping{

//
KidnapDetection::KidnapDetection(){}

void KidnapDetection::ScanMatchingCostTest(double finalcost){
    if (IfKidnapped == true){
        std::cout<<"Kidnapped, find by Scan Matching cost test" <<std::endl;
    }else{
        if(counter > ScanMatchingTestTrigger){
            IfKidnapped = true;
        }else{
            if ( finalcost > ScanMatchingThreshold){
                counter++;
            }
            else{
                CounterClear(); 
            }

        }
    }

}

}
}
