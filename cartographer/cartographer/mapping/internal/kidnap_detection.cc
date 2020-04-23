#include "cartographer/mapping/internal/kidnap_detection.h"
#include "glog/logging.h"



namespace cartographer{
namespace mapping{

//
KidnapDetection::KidnapDetection(){}

void KidnapDetection::ScanMatchingCostTest(double finalcost){
    if (IfKidnapped != true){
        if(counter > ScanMatchingTestTrigger){
            IfKidnapped = true;
            LOG(WARNING)<<"Kidnapped, find by Scan Matching cost test" ;
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
