#ifndef HLTEgammaClusterShapeFilter_h
#define HLTEgammaClusterShapeFilter_h

/** \class HLTEgammaClusterShapeFilter
 *
 *  \author Alessio Ghezzi (CERN)
 *
 */

#include "HLTrigger/HLTcore/interface/HLTFilter.h"

//
// class decleration
//

class HLTEgammaClusterShapeFilter : public HLTFilter {

   public:
      explicit HLTEgammaClusterShapeFilter(const edm::ParameterSet&);
      ~HLTEgammaClusterShapeFilter();
      virtual bool filter(edm::Event&, const edm::EventSetup&);

   private:
      edm::InputTag candTag_; // input tag identifying product contains filtered photons
      edm::InputTag ecalRechitEBTag_; // input tag identifying product contains hcal isolation map
      edm::InputTag ecalRechitEETag_; // input tag identifying product contains hcal isolation map
      
      double thresholdEB_;
      double thresholdEE_;
      
      int    ncandcut_;        // number of photons required
      bool doIsolated_;

      bool   store_;
      edm::InputTag L1IsoCollTag_; 
      edm::InputTag L1NonIsoCollTag_; 
};

#endif //HLTEgammaClusterShapeFilter_h

