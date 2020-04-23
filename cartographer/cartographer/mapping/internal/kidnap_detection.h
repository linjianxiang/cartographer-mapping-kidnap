#ifndef CARTOGRAPHER_MAPPING_INTERNAL_KIDNAP_DETECTION_H_
#define CARTOGRAPHER_MAPPING_INTERNAL_KIDNAP_DETECTION_H_

#include <iostream>

namespace cartographer{
namespace mapping{


//The kidnap detection module
class KidnapDetection{
    public:
        KidnapDetection();
        void CounterClear(){counter = 0;};
        void ScanMatchingCostTest(double finalcost);

        //clear the kidnap flag when a new map is initialized
        void KidnapDetectionReset(){
            IfKidnapped =false;
            CounterClear();
        }
        bool GetResult(){return IfKidnapped;}
    private:
        bool IfKidnapped = false;
        int counter = 0;
        int ScanMatchingTestTrigger = 3;
        double ScanMatchingThreshold = 0.2;
};


}
}


#endif // CARTOGRAPHER_MAPPING_INTERNAL_KIDNAP_DETECTION_H_
