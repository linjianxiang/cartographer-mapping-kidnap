#ifndef CARTOGRAPHER_MAPPING_INTERNAL_KIDNAP_DETECTION_H_
#define CARTOGRAPHER_MAPPING_INTERNAL_KIDNAP_DETECTION_H_

#include <iostream>
#include <vector>
#include <numeric>

namespace cartographer{
namespace mapping{


//The kidnap detection module
class KidnapDetection{
    public:
        KidnapDetection();
        void CounterClear(){counter = 0;};
        void ScanMatchingCostTest(double finalcost);
        void ExponentialFilterTest(double finalcost);
        void AverageFilterTest(double finalcost);

    //clear the kidnap flag when a new map is initialized
        void KidnapDetectionReset(){
            IfKidnapped =false;
            CounterClear();
        }
        bool GetResult(){return IfKidnapped;}
    private:
        bool IfKidnapped = false;

        // parameters for Scan Matching Cost test
        int counter = 0;
        int ScanMatchingTestTrigger = 3;
        double ScanMatchingThreshold = 0.2;

        // parameters for Exponential Filter test
        double alpha_fast =0.7;
        double alpha_slow = 0.2;
        double weight_fast = 0;
        double weight_slow = 0;

        //parameters for average filter
        int filter_size = 10;
        int kidnap_trigger_weight = 2;
        std::vector<double> filter_input;
};


}
}


#endif // CARTOGRAPHER_MAPPING_INTERNAL_KIDNAP_DETECTION_H_
