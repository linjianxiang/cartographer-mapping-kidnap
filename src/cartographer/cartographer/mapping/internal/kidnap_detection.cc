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

void KidnapDetection::ExponentialFilterTest(double finalcost){

    double weight_finalcost = 1/finalcost;
    weight_fast = weight_fast + alpha_fast*(weight_finalcost - weight_fast);
    weight_slow = weight_slow + alpha_slow*(weight_finalcost - weight_slow);
    LOG(INFO)<<"weight fast is " << weight_fast;
    LOG(INFO)<<"weight slow is " << weight_slow;
//    if (IfKidnapped != true) {
//
//
//    }
}


double average_vector(std::vector<double> filter_input){
    auto n = filter_input.size();
    if(n != 0 ){
        return accumulate(filter_input.begin(),filter_input.end(),0.0)/n;
    }
    return 0.0;
}
void KidnapDetection::AverageFilterTest(double finalcost) {
    filter_input.push_back(finalcost);
    if (filter_input.size() < filter_size){
    }else{
        double filter_out = average_vector(filter_input);
        filter_input.erase(filter_input.begin());
        if (finalcost > kidnap_trigger_weight * filter_out){
            //kidnaped
            IfKidnapped = true;
        }
    }


}


}
}
